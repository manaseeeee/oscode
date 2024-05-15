#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
using namespace std;

int main() {
    int pipefd[2];
    pid_t pid;

    if (pipe(pipefd) == -1) {
        cerr << "Pipe failed" << endl;
        return 1;
    }
    pid = fork();
    if (pid < 0) {
        cerr << "Fork failed" << endl;
        return 1;
    }

    if (pid > 0) { 
        close(pipefd[0]); 
        int data_to_send = 123;
        write(pipefd[1], &data_to_send, sizeof(data_to_send));

        cout << "Parent process: Sent data to child process" << endl;
        wait(NULL);
    } else { 
        close(pipefd[1]);
        int data_received;

        read(pipefd[0], &data_received, sizeof(data_received));
        cout << "Child process: Received data from parent process: " << data_received << endl;
    }
    return 0;
}
