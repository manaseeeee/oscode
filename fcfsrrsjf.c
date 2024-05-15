#include <stdio.h>

// Structure to represent a process
typedef struct {
    int pid;        // Process ID
    int arrival;    // Arrival time
    int burst;      // Burst time
    int waiting;    // Waiting time
    int turnaround; // Turnaround time
} Process;

// Function to perform FCFS scheduling
void fcfs(Process processes[], int n) {
    int currentTime = 0;
    
    printf("FCFS Scheduling:\n");
    printf("Process\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");
    
    for (int i = 0; i < n; i++) {
        if (currentTime < processes[i].arrival)
            currentTime = processes[i].arrival;
        
        processes[i].waiting = currentTime - processes[i].arrival;
        processes[i].turnaround = processes[i].waiting + processes[i].burst;
        
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].pid, processes[i].arrival,
               processes[i].burst, processes[i].waiting, processes[i].turnaround);
        
        currentTime += processes[i].burst;
    }
}

// Function to perform SJF scheduling
void sjf(Process processes[], int n) {
    // Sort processes based on burst time (shortest job first)
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (processes[j].burst > processes[j + 1].burst) {
                Process temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
        }
    }
    
    // Now perform FCFS on the sorted processes
    fcfs(processes, n);
}

// Function to perform Round Robin scheduling
void roundRobin(Process processes[], int n, int quantum) {
    int remainingBurst[n];
    
    for (int i = 0; i < n; i++)
        remainingBurst[i] = processes[i].burst;
    
    int currentTime = 0;
    printf("Round Robin Scheduling (Quantum = %d):\n", quantum);
    printf("Process\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");
    
    while (1) {
        int done = 1;
        
        for (int i = 0; i < n; i++) {
            if (remainingBurst[i] > 0) {
                done = 0;
                
                if (remainingBurst[i] > quantum) {
                    currentTime += quantum;
                    remainingBurst[i] -= quantum;
                } else {
                    currentTime += remainingBurst[i];
                    processes[i].waiting = currentTime - processes[i].burst;
                    processes[i].turnaround = processes[i].waiting + processes[i].burst;
                    remainingBurst[i] = 0;
                    
                    printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].pid, processes[i].arrival,
                           processes[i].burst, processes[i].waiting, processes[i].turnaround);
                }
            }
        }
        
        if (done == 1)
            break;
    }
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    
    Process processes[n];
    int quantum;
    
    printf("Enter quantum time for Round Robin: ");
    scanf("%d", &quantum);
    
    // Input arrival time and burst time for each process
    for (int i = 0; i < n; i++) {
        printf("Enter arrival time and burst time for process %d: ", i + 1);
        scanf("%d %d", &processes[i].arrival, &processes[i].burst);
        processes[i].pid = i + 1;
    }
    
    // Perform scheduling algorithms
    printf("\n");
    fcfs(processes, n);
    printf("\n");
    sjf(processes, n);
    printf("\n");
    roundRobin(processes, n, quantum);
    
    return 0;
}
