#include <stdio.h>

struct process {
    int pid;
    int bt;  // Burst Time
    int at;  // Arrival Time
    int ct;  // Completion Time
    int wt;  // Waiting Time
    int tat; // Turnaround Time
};

int main() {
    int n, i;
    struct process p[10];

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter the process id, burst time, and arrival time:\n");
    for (i = 0; i < n; i++) {
        scanf("%d %d %d", &p[i].pid, &p[i].bt, &p[i].at);
    }

    // Sorting based on Arrival Time
    for (i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (p[i].at > p[j].at) {
                struct process temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }

    // Calculate Completion Time, Waiting Time, and Turnaround Time
    int currentTime = 0;
    for (i = 0; i < n; i++) {
        if (currentTime < p[i].at) {
            currentTime = p[i].at;
        }
        p[i].ct = currentTime + p[i].bt;
        currentTime += p[i].bt;
        p[i].tat = p[i].ct - p[i].at;
        p[i].wt = p[i].tat - p[i].bt;
    }

    int avgt = 0, avgw = 0;
    // Print the result
    printf("pid\tbt\tat\tct\twt\ttat\n");
    for (i = 0; i < n; i++) {
	    avgw += p[i].wt;
	    avgt += p[i].tat;
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", p[i].pid, p[i].bt, p[i].at, p[i].ct, p[i].wt, p[i].tat);
    }

    printf("Avg wating time : %d\nAvg tat : %d\n",avgw/n , avgt/n);

    return 0;
}

