#include <stdio.h>

int main() {
    int fragments[10], blocks[10], files[10];
    int m, n, number_of_blocks, number_of_files, temp, top = 0;
    static int block_arr[10], file_arr[10];

    printf("\nEnter the Total Number of Blocks:\t");
    scanf("%d", &number_of_blocks);

    printf("Enter the Total Number of Files:\t");
    scanf("%d", &number_of_files);

    printf("\nEnter the Size of the Blocks:\n");
    for (m = 0; m < number_of_blocks; m++) {
        printf("Block No.[%d]:\t", m + 1);
        scanf("%d", &blocks[m]);
    }

    printf("\nEnter the Size of the Files:\n");
    for (m = 0; m < number_of_files; m++) {
        printf("File No.[%d]: \t", m + 1);
        scanf("%d", &files[m]);
    }

    for (m = 0; m < number_of_files; m++) {
        int worst_fit_index = -1;
        for (n = 0; n < number_of_blocks; n++) {
            if (block_arr[n] != 1) {
                temp = blocks[n] - files[m];
                if (temp >= 0) {
                    if (worst_fit_index == -1 || blocks[worst_fit_index] < blocks[n]) {
                        worst_fit_index = n;
                    }
                }
            }
        }

        if (worst_fit_index != -1) {
            fragments[m] = blocks[worst_fit_index] - files[m];
            block_arr[worst_fit_index] = 1;
            file_arr[m] = worst_fit_index;
        }
    }

    printf("\nFile Number\t File Size\t Block Number\t Block Size\t Fragment\n");
    for (m = 0; m < number_of_files; m++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", m + 1, files[m], file_arr[m] + 1, blocks[file_arr[m]], fragments[m]);
    }

    return 0;
}

