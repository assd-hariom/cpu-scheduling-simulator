/* Used AI assistance for code refinement */
#include <stdio.h>
#include <stdlib.h>

#define MAX 20

typedef struct {
    int pid;
    int arrival;
    int burst;
    int remaining;
    int waiting;
    int turnaround;
    int completed;
} Process;

void input_processes(Process p[], int *n) {
    printf("Enter number of processes: ");
    scanf("%d", n);

    for (int i = 0; i < *n; i++) {
        p[i].pid = i + 1;
        printf("Enter Arrival Time for P %d: ", i + 1);
        scanf("%d", &p[i].arrival);
        printf("Enter Burst Time for P %d: ", i + 1);
        scanf("%d", &p[i].burst);

        p[i].remaining = p[i].burst;
        p[i].waiting = 0;
        p[i].turnaround = 0;
        p[i].completed = 0;
    }
}

void print_results(Process p[], int n) {
    float total_wait = 0, total_turn = 0;

    printf("\nPID\tArrival\tBurst\tWaiting\tTurnaround\n");

    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\n",
               p[i].pid,
               p[i].arrival,
               p[i].burst,
               p[i].waiting,
               p[i].turnaround);

        total_wait += p[i].waiting;
        total_turn += p[i].turnaround;
    }

    printf("\nAverage Waiting Time: %.2f\n", total_wait / n);
    printf("Average Turnaround Time: %.2f\n", total_turn / n);
}

void reset_processes(Process p[], int n) {
    for (int i = 0; i < n; i++) {
        p[i].remaining = p[i].burst;
        p[i].waiting = 0;
        p[i].turnaround = 0;
        p[i].completed = 0;
    }
}

void fcfs(Process p[], int n) {
    int time = 0;

    printf("\n Gantt Chart: ");

    for (int i = 0; i < n; i++) {
        if (time < p[i].arrival)
            time = p[i].arrival;

        printf("| P%d ", p[i].pid);

        p[i].waiting = time - p[i].arrival;
        time += p[i].burst;
        p[i].turnaround = time - p[i].arrival;
    }
    printf("|\n");

    print_results(p, n);
}

void sjf(Process p[], int n) {
    int time = 0, done = 0;

    printf("\nGantt Chart: ");

    while (done < n) {
        int idx = -1;
        int min = 9999;

        for (int i = 0; i < n; i++) {
            if (!p[i].completed &&
                p[i].arrival <= time &&
                p[i].burst < min) {
                min = p[i].burst;
                idx = i;
            }
        }

        if (idx != -1) {
            printf("| P%d ", p[idx].pid);

            p[idx].waiting = time - p[idx].arrival;
            time += p[idx].burst;
            p[idx].turnaround = time - p[idx].arrival;
            p[idx].completed = 1;
            done++;
        } else {
            time++;
        }
    }

    printf("|\n");

    print_results(p, n);
}

void round_robin(Process p[], int n) {
    int quantum;
    printf("Enter Time Quantum: ");
    scanf("%d", &quantum);

    int time = 0, done = 0;

    printf("\nGantt Chart: ");

    while (done < n) {
        int executed = 0;

        for (int i = 0; i < n; i++) {
            if (p[i].remaining > 0 &&
                p[i].arrival <= time) {

                executed = 1;

                printf("| P%d ", p[i].pid);

                int run = (p[i].remaining < quantum)
                              ? p[i].remaining
                              : quantum;

                time += run;
                p[i].remaining -= run;

                if (p[i].remaining == 0) {
                    p[i].turnaround =
                        time - p[i].arrival;

                    p[i].waiting =
                        p[i].turnaround - p[i].burst;

                    done++;
                }
            }
        }

        if (!executed)
            time++;
    }

    printf("|\n");

    print_results(p, n);
}

int main() {
    Process p[MAX];
    int n;
    int choice;

    input_processes(p, &n);

    do {
        printf("\n===== CPU Scheduling Simulator =====\n");
        printf("1. FCFS Scheduling\n");
        printf("2. SJF Scheduling (Non-Preemptive)\n");
        printf("3. Round Robin Scheduling\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        reset_processes(p, n);

        switch (choice) {
        case 1:
            fcfs(p, n);
            break;

        case 2:
            sjf(p, n);
            break;

        case 3:
            round_robin(p, n);
            break;

        case 4:
            printf("Exiting program...\n");
            break;

        default:
            printf("Invalid choice. Try again.\n");
        }

    } while (choice != 4);

    return 0;
}

