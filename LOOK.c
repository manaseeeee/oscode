#include <stdio.h>
#include <stdlib.h>

#define LEFT 0
#define RIGHT 1

int main() {
    int n, initial_head, direction, total_head_movement = 0;

    printf("Enter the number of disk requests: ");
    scanf("%d", &n);

    int requests[n];

    printf("Enter the initial position of the disk head: ");
    scanf("%d", &initial_head);

    printf("Enter the direction of head movement (0 for left, 1 for right): ");
    scanf("%d", &direction);

    printf("Enter the sequence of disk requests:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &requests[i]);
    }

    // Sort requests according to their cylinder numbers
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (requests[j] > requests[j + 1]) {
                int temp = requests[j];
                requests[j] = requests[j + 1];
                requests[j + 1] = temp;
            }
        }
    }

    // Find the index of initial head position in the requests
    int initial_index = -1;
    for (int i = 0; i < n; i++) {
        if (requests[i] >= initial_head) {
            initial_index = i;
            break;
        }
    }

    // If initial head position is not found in requests, place it at the beginning
    if (initial_index == -1)
        initial_index = 0;

    // Print path
    printf("Path: %d ", initial_head);

    // Head movement towards the right
    if (direction == RIGHT) {
        for (int i = initial_index; i < n; i++) {
            total_head_movement += abs(initial_head - requests[i]);
            initial_head = requests[i];
            printf("-> %d ", initial_head);
        }
        // If direction is right and there are no requests further to the right,
        // move left to the last request in the sequence
        if (initial_index == 0 || initial_index == n) {
            initial_head = requests[n - 1];
            printf("-> %d ", initial_head);
        }
        // Head movement towards the left (backward)
        for (int i = initial_index - 1; i >= 0; i--) {
            total_head_movement += abs(initial_head - requests[i]);
            initial_head = requests[i];
            printf("-> %d ", initial_head);
        }
    }
    // Head movement towards the left
    else {
        for (int i = initial_index; i >= 0; i--) {
            total_head_movement += abs(initial_head - requests[i]);
            initial_head = requests[i];
            printf("-> %d ", initial_head);
        }
        // If direction is left and there are no requests further to the left,
        // move right to the first request in the sequence
        if (initial_index == 0 || initial_index == n) {
            initial_head = requests[0];
            printf("-> %d ", initial_head);
        }
        // Head movement towards the right (forward)
        for (int i = initial_index + 1; i < n; i++) {
            total_head_movement += abs(initial_head - requests[i]);
            initial_head = requests[i];
            printf("-> %d ", initial_head);
        }
    }

    printf("\nTotal head movement: %d\n", total_head_movement);

    return 0;
}
