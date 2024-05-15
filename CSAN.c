#include <stdio.h>
#include <stdlib.h>

#define LEFT 0
#define RIGHT 1

int main() {
    int n, initial_head, max_cylinder, direction, total_head_movement = 0;

    printf("Enter the number of disk requests: ");
    scanf("%d", &n);

    int requests[n];

    printf("Enter the initial position of the disk head: ");
    scanf("%d", &initial_head);

    printf("Enter the maximum cylinder of the disk: ");
    scanf("%d", &max_cylinder);

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
        // Go right until the end
        for (int i = initial_index; i < n; i++) {
            total_head_movement += abs(initial_head - requests[i]);
            initial_head = requests[i];
            printf("-> %d ", initial_head);
        }
        // Go to the beginning
        total_head_movement += abs(initial_head - max_cylinder);
        initial_head = 0;
        printf("-> %d ", initial_head);
        // Go right again from the beginning
        for (int i = 0; i < initial_index; i++) {
            total_head_movement += abs(initial_head - requests[i]);
            initial_head = requests[i];
            printf("-> %d ", initial_head);
        }
    }
    // Head movement towards the left
    else {
        // Go left until the beginning
        for (int i = initial_index - 1; i >= 0; i--) {
            total_head_movement += abs(initial_head - requests[i]);
            initial_head = requests[i];
            printf("-> %d ", initial_head);
        }
        // Go to the maximum cylinder
        total_head_movement += abs(initial_head - max_cylinder);
        initial_head = max_cylinder;
        printf("-> %d ", initial_head);
        // Go left again from the maximum cylinder
        for (int i = n - 1; i >= initial_index; i--) {
            total_head_movement += abs(initial_head - requests[i]);
            initial_head = requests[i];
            printf("-> %d ", initial_head);
        }
    }

    printf("\nTotal head movement: %d\n", total_head_movement);

    return 0;
}
