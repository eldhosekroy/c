#include <stdio.h>
int main() {
    int page[16], frame[3], time[3], pf = 0, fno = 3, no = 12, index = 0;

    printf("Enter reference string: ");
    for (int i = 0; i < no; i++) {
        scanf("%d", &page[i]);
    }

    // Initialize frame array and time array
    for (int i = 0; i < 3; i++) {
        frame[i] = -1;
        time[i] = 0;
    }

    printf("Frame Status:\n");
    for (int i = 0; i < no; i++) {
        int pgno = page[i];
        int found = 0;
        // Check if page is in frame
        for (int j = 0; j < 3; j++) {
            if (frame[j] == pgno) {
                found = 1;
                time[j] = i; // Update the time to the current index
                break;
            }
        }
        if (!found) {
            // Page fault occurs
            pf++;
            // Find the least recently used frame
            int lruIndex = 0;
            for (int j = 1; j < 3; j++) {
                if (time[j] < time[lruIndex]) {
                    lruIndex = j;
                }
            }
            // Replace the LRU page
            frame[lruIndex] = pgno;
            time[lruIndex] = i;
        }
        // Print current frame status
        for (int j = 0; j < 3; j++) {
            if (frame[j] != -1) {
                printf("%d\t", frame[j]);
            } else {
                printf("-\t");
            }
        }

        if (!found) {
            printf("page fault\t");
        }
        printf("\n");
    }
    printf("\nTotal Page Faults: %d\n", pf);
    return 0;

}
