#include <stdio.h>
#include <stdlib.h>

// Node structure for a block in the linked list
typedef struct BlockNode {
    int block_number;
    struct BlockNode* next;
} BlockNode;

// Structure representing a file's block allocation
typedef struct FileAllocation {
    int file_id;
    BlockNode* allocated_blocks;
} FileAllocation;

// Function to allocate a block to a file
void allocateBlock(BlockNode** head, int block_number) {
    BlockNode* new_block = (BlockNode*)malloc(sizeof(BlockNode));
    if (new_block == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    new_block->block_number = block_number;
    new_block->next = *head;
    *head = new_block;
}

// Function to display allocated blocks for a file
void displayFileBlocks(FileAllocation file) {
    printf("Path for File %d: ", file.file_id);
    BlockNode* current = file.allocated_blocks;
    while (current != NULL) {
        printf(" -> %d", current->block_number);
        current = current->next;
    }
    printf("\n");
}

int main() {
    int num_files, num_blocks;

    // Input the number of files
    printf("Enter the number of files: ");
    scanf("%d", &num_files);

    // Input the number of blocks
    printf("Enter the number of blocks: ");
    scanf("%d", &num_blocks);

    // Array of file allocations
    FileAllocation files[num_files];

    // Allocate blocks to each file
    for (int i = 0; i < num_files; i++) {
        files[i].file_id = i + 1;
        files[i].allocated_blocks = NULL;

        printf("Enter block allocations for File %d (separated by spaces): ", i + 1);
        for (int j = 0; j < num_blocks; j++) {
            int block_number;
            scanf("%d", &block_number);
            if (block_number != -1) {
                allocateBlock(&(files[i].allocated_blocks), block_number);
            }
        }
    }

    // Display path for each file
    for (int i = 0; i < num_files; i++) {
        displayFileBlocks(files[i]);
    }

    // Free allocated memory for block lists
    for (int i = 0; i < num_files; i++) {
        BlockNode* current = files[i].allocated_blocks;
        while (current != NULL) {
            BlockNode* temp = current;
            current = current->next;
            free(temp);
        }
    }

    return 0;
}
