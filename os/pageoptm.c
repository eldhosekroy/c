#include <stdio.h>
#include <stdlib.h>

// Function to check if a page is in memory
int isPageInMemory(int page, int frames[], int frameCount) {
    for (int i = 0; i < frameCount; i++) {
        if (frames[i] == page) {
            return 1;
        }
    }
    return 0;
}

// Function to predict the farthest page in the future
int findOptimalPage(int referenceString[], int page, int referenceLength, int frames[], int frameCount) {
    int maxDistance = -1;
    int pageToReplace = -1;

    for (int i = 0; i < frameCount; i++) {
        int j;
        for (j = page + 1; j < referenceLength; j++) {
            if (frames[i] == referenceString[j]) {
                if (j > maxDistance) {
                    maxDistance = j;
                    pageToReplace = i;
                }
                break;
            }
        }

        // If the page is never referenced in the future, return it for replacement
        if (j == referenceLength) {
            return i;
        }
    }

    // If all pages are referenced in the future, return the one that appears the latest
    return pageToReplace;
}

// Optimal page replacement algorithm
void optimalPageReplacement(int referenceString[], int referenceLength, int frameCount) {
    int frames[frameCount];
    for (int i = 0; i < frameCount; i++) frames[i] = -1; // Initialize frames array

    int pageFaults = 0;
    for (int i = 0; i < referenceLength; i++) {
        int page = referenceString[i];

        if (!isPageInMemory(page, frames, frameCount)) {
            int replaceIndex = (pageFaults < frameCount) ? pageFaults : findOptimalPage(referenceString, i, referenceLength, frames, frameCount);
            frames[replaceIndex] = page;
            pageFaults++;
        }

        // Print current frame state
        for (int j = 0; j < frameCount; j++) {
            if (frames[j] != -1) printf("%d ", frames[j]);
            else printf(". ");
        }
        printf("\n");
    }

    printf("Total Page Faults: %d\n", pageFaults);
}

int main() {
    int referenceString[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2, 1};
    int referenceLength = sizeof(referenceString) / sizeof(referenceString[0]);
    int frameCount = 4;

    optimalPageReplacement(referenceString, referenceLength, frameCount);

    return 0;
}
