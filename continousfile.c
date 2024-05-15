#include <stdio.h>
#include <stdlib.h>

#define MAX_FILES 10

// Structure to represent a file
struct File {
    int size;
    int start;
    int end;
};

// Function to allocate memory to files using continuous allocation
void allocateFilesContinuous(struct File files[], int numFiles, int diskSize) {
    int current = 0;
    for (int i = 0; i < numFiles; i++) {
        if (current + files[i].size > diskSize) {
            printf("Error: Not enough space for file %d\n", i + 1);
            return;
        }
        files[i].start = current;
        files[i].end = current + files[i].size - 1;
        current += files[i].size;
        printf("File %d allocated from block %d to %d\n", i + 1, files[i].start, files[i].end);
    }
}

int main() {
    int diskSize, numFiles;

    printf("Enter the size of the disk: ");
    scanf("%d", &diskSize);

    printf("Enter the number of files: ");
    scanf("%d", &numFiles);

    struct File files[MAX_FILES];

    printf("Enter the size of each file:\n");
    for (int i = 0; i < numFiles; i++) {
        printf("File %d: ", i + 1);
        scanf("%d", &files[i].size);
    }

    allocateFilesContinuous(files, numFiles, diskSize);

    return 0;
}
