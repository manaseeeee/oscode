#include <stdio.h>
#include <stdlib.h>

// Function to check if a page is present in memory
int search(int key, int *frames, int n) {
    for (int i = 0; i < n; i++) {
        if (frames[i] == key)
            return i;
    }
    return -1;
}

// Function to find the index of page that will not be used for the longest time
int findVictim(int *pages, int *frames, int m, int n, int startIndex) {
    int victimIndex = -1, farthest = startIndex;
    for (int i = 0; i < m; i++) {
        int j;
        for (j = startIndex; j < n; j++) {
            if (frames[i] == pages[j]) {
                if (j > farthest) {
                    farthest = j;
                    victimIndex = i;
                }
                break;
            }
        }
        if (j == n)
            return i;
    }
    if (victimIndex == -1)
        return 0;
    return victimIndex;
}

// Function to simulate Optimal Page Replacement Algorithm
void optimalPageReplacement(int *pages, int n, int m) {
    int faults = 0;
    int frames[m];
    for (int i = 0; i < m; i++)
        frames[i] = -1;

    for (int i = 0; i < n; i++) {
        if (search(pages[i], frames, m) == -1) {
            int victimIndex = findVictim(pages, frames, m, n, i + 1);
            frames[victimIndex] = pages[i];
            faults++;
            printf("Page %d inserted into frame %d\n", pages[i], victimIndex);
        }
    }
    printf("Total Page Faults: %d\n", faults);
}

int main() {
    int numFrames, numPages;

    printf("Enter the number of frames: ");
    scanf("%d", &numFrames);

    printf("Enter the number of pages: ");
    scanf("%d", &numPages);

    int pages[numPages];

    printf("Enter the page reference string: ");
    for (int i = 0; i < numPages; i++) {
        scanf("%d", &pages[i]);
    }

    optimalPageReplacement(pages, numPages, numFrames);

    return 0;
}
