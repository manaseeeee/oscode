#include <stdio.h>
#include <stdbool.h>

#define MAX_FRAMES 10

int findLRU(int time[], int n) {
    int i, minimum = time[0], pos = 0;

    for (i = 1; i < n; ++i) {
        if (time[i] < minimum) {
            minimum = time[i];
            pos = i;
        }
    }

    return pos;
}

int main() {
    int frames[MAX_FRAMES], pages[MAX_FRAMES];
    int num_frames, num_pages, page_faults = 0;
    int i, j, k, time[MAX_FRAMES], found;
    bool page_found;

    printf("Enter the number of frames: ");
    scanf("%d", &num_frames);

    printf("Enter the number of pages: ");
    scanf("%d", &num_pages);

    printf("Enter the reference string: ");
    for (i = 0; i < num_pages; i++) {
        scanf("%d", &pages[i]);
    }

    for (i = 0; i < num_frames; i++) {
        frames[i] = -1; // Initialize all frames to -1 (empty)
        time[i] = 0; // Initialize all times to 0
    }

    printf("\nPage Replacement Process:\n");

    for (i = 0; i < num_pages; i++) {
        page_found = false; // Flag to indicate whether page is found in frames or not
        for (j = 0; j < num_frames; j++) {
            if (frames[j] == pages[i]) {
                page_found = true; // Page found in frames
                time[j] = i; // Update time of last usage
                break;
            }
        }

        if (!page_found) { // Page fault
            int lru_index = findLRU(time, num_frames);
            frames[lru_index] = pages[i]; // Replace the least recently used page in the frame
            time[lru_index] = i; // Update time of last usage
            printf("Page %d causes a page fault\n", pages[i]);
            page_faults++;
        }

        printf("Frames: ");
        for (k = 0; k < num_frames; k++) {
            if (frames[k] == -1) {
                printf("[ ] "); // Empty frame
            } else {
                printf("[%d] ", frames[k]); // Occupied frame
            }
        }
        printf("\n");
    }

    printf("\nTotal Page Faults: %d\n", page_faults);

    return 0;
}
