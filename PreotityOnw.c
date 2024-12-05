#include <stdio.h>

// Function to swap two integers
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to take input from the user
void inputProcesses(int n, int b[], int p[], int index[]) {
    for (int i = 0; i < n; i++) {
        printf("Enter Burst Time and Priority Value for Process %d: ", i + 1);
        scanf("%d %d", &b[i], &p[i]);
        index[i] = i + 1;  // Storing process ID
    }
}

// Function to sort the processes based on their priority
void sortProcesses(int n, int b[], int p[], int index[]) {
    for (int i = 0; i < n; i++) {
        int maxPriority = p[i], m = i;
        for (int j = i; j < n; j++) {
            if (p[j] > maxPriority) {
                maxPriority = p[j];
                m = j;
            }
        }
        swap(&p[i], &p[m]);
        swap(&b[i], &b[m]);
        swap(&index[i], &index[m]);
    }
}

// Function to print the order of process execution
void printExecutionOrder(int n, int b[], int index[]) {
    int t = 0;
    printf("\nOrder of process execution is:\n");
    for (int i = 0; i < n; i++) {
        printf("P%d is executed from %d to %d\n", index[i], t, t + b[i]);
        t += b[i];
    }
}

// Function to print the Gantt chart
void printGanttChart(int n, int b[], int index[]) {
    int t = 0;
    printf("\nGantt Chart:\n");
    
    // Print the process IDs in order
    printf("|");
    for (int i = 0; i < n; i++) {
        printf("  P%d  |", index[i]);
    }
    printf("\n");

    // Print the time intervals
    t = 0;
    printf("0");
    for (int i = 0; i < n; i++) {
        t += b[i];
        printf("     %d", t); // Printing the time intervals
    }
    printf("\n");
}

// Function to calculate and print the waiting and turnaround times
void printWaitAndTurnaroundTimes(int n, int b[], int index[]) {
    int wait_time = 0;
    int turnaround_time = 0;
    printf("\nProcess Id     Burst Time   Wait Time    TurnAround Time\n");

    for (int i = 0; i < n; i++) {
        turnaround_time = wait_time + b[i];
        printf("P%d          %d          %d          %d\n", index[i], b[i], wait_time, turnaround_time);
        wait_time += b[i];
    }
}

int main() {
    int n;
    printf("Enter Number of Processes: ");
    scanf("%d", &n);

    int b[n], p[n], index[n];

    inputProcesses(n, b, p, index);  // Take input from the user
    sortProcesses(n, b, p, index);   // Sort processes by priority
    printExecutionOrder(n, b, index); // Print the order of execution
    printGanttChart(n, b, index);     // Print the Gantt chart
    printWaitAndTurnaroundTimes(n, b, index); // Print wait and turnaround times

    return 0;
}
