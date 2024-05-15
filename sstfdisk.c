#include<stdio.h>
#include<stdlib.h>

int main() {
    int RQ[100], i, n, TotalHeadMovement = 0, initial, count = 0;
    
    printf("Enter the number of Requests: ");
    scanf("%d", &n);
    
    printf("Enter the Requests sequence: ");
    for(i = 0; i < n; i++)
        scanf("%d", &RQ[i]);
    
    printf("Enter initial head position: ");
    scanf("%d", &initial);
    
    // Logic for SSTF disk scheduling
    printf("Path: %d ", initial); // Print initial head position
    
    // Loop will execute until all processes are completed
    while(count != n) {
        int min = 1000, d, index;
        for(i = 0; i < n; i++) {
            d = abs(RQ[i] - initial);
            if(min > d) {
                min = d;
                index = i;
            }
        }
        TotalHeadMovement += min;
        initial = RQ[index];
        RQ[index] = 1000; // Mark request as completed
        printf("-> %d ", initial); // Print the path taken
        count++;
    }
    
    printf("\nTotal head movement is %d\n", TotalHeadMovement);
    return 0;
}
