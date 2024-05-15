#include <stdio.h>
#include <stdlib.h>

#define MAX_BLOCKS 100
#define MAX_FILES 100

struct IndexTable {
    int blocks[MAX_BLOCKS];
};

struct File {
    char name[20];
    int size;
    struct IndexTable indexTable;
};

struct File files[MAX_FILES];
int numFiles = 0;

void createFile() {
    if (numFiles >= MAX_FILES) {
        printf("Cannot create more files. Maximum limit reached.\n");
        return;
    }

    struct File newFile;

    printf("Enter file name: ");
    scanf("%s", newFile.name);

    printf("Enter file size: ");
    scanf("%d", &newFile.size);

    printf("Enter index blocks for the file (up to %d blocks, -1 to stop): ", MAX_BLOCKS);
    for (int i = 0; i < MAX_BLOCKS; i++) {
        scanf("%d", &newFile.indexTable.blocks[i]);
        if (newFile.indexTable.blocks[i] == -1) {
            break;
        }
    }

    files[numFiles++] = newFile;
    printf("File created successfully.\n");
}

void displayFiles() {
    if (numFiles == 0) {
        printf("No files created yet.\n");
        return;
    }

    printf("List of Files:\n");
    for (int i = 0; i < numFiles; i++) {
        printf("%d. Name: %s, Size: %d, Index Blocks: ", i+1, files[i].name, files[i].size);
        for (int j = 0; j < MAX_BLOCKS; j++) {
            if (files[i].indexTable.blocks[j] == -1) {
                break;
            }
            printf("%d ", files[i].indexTable.blocks[j]);
        }
        printf("\n");
    }
}

int main() {
    int choice;

    do {
        printf("\nIndexed File Allocation Methods\n");
        printf("1. Create a File\n");
        printf("2. Display Files\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createFile();
                break;
            case 2:
                displayFiles();
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 3);

    return 0;
}
