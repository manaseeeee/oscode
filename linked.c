#include <stdio.h>

#define MAX_FILES 10
#define MAX_BLOCKS 100

int main() {
    int num_files, num_blocks;
    int file_blocks[MAX_FILES][MAX_BLOCKS]; // Array to store block allocation for each file
    int i, j;

    // Input the number of files
    printf("Enter the number of files: ");
    scanf("%d", &num_files);

    if (num_files > MAX_FILES || num_files <= 0) {
        printf("Invalid number of files\n");
        return 1;
    }

    // Input the number of blocks
    printf("Enter the number of blocks: ");
    scanf("%d", &num_blocks);

    if (num_blocks > MAX_BLOCKS || num_blocks <= 0) {
        printf("Invalid number of blocks\n");
        return 1;
    }

    // Input block allocation for each file
    for (i = 0; i < num_files; i++) {
        printf("Enter the block allocation for file %d (separated by spaces): ", i + 1);
        for (j = 0; j < num_blocks; j++) {
            scanf("%d", &file_blocks[i][j]);
        }
    }

    // Display path for each file
    for (i = 0; i < num_files; i++) {
        printf("Path for File %d: ", i + 1);
        for (j = 0; j < num_blocks; j++) {
            if (file_blocks[i][j] != -1) { // Check if block is allocated to file
                printf(" -> %d", file_blocks[i][j]);
            }
        }
        printf("\n");
    }

    return 0;
}
