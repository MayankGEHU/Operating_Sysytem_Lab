#include<stdio.h>

void findWaitingTime(int processes[], int n, int bt[], int wt[]){
    wt[0] = 0;  // Waiting time for first process is 0

    for (int i = 1; i < n; i++){
        wt[i] = bt[i - 1] + wt[i - 1];
    }
}

void findTurnAroundTime(int processes[], int n, int bt[], int wt[], int tat[]){
    for (int i = 0; i < n; i++){
        tat[i] = bt[i] + wt[i];
    }
}

void printGanttChart(int processes[], int n, int bt[]){
    printf("\nGantt Chart:\n");
    int time = 0;

    // Print the Gantt chart with process names
    for (int i = 0; i < n; i++){
        printf("| P%d ", processes[i]);
    }
    printf("|\n");

    // Print the time markers below the Gantt chart
   // time = 0;
    printf("%d\t", time);
    for (int i = 0; i < n; i++){
        time += bt[i];
        printf("%d\t", time);
    }
    printf("\n");
}

void findavgTime(int processes[], int n, int bt[]){
    int wt[n], tat[n], total_wt = 0, total_tat = 0;

    findWaitingTime(processes, n, bt, wt);
    findTurnAroundTime(processes, n, bt, wt, tat);

    printf("Processes  Burst time  Waiting time  Turn around time\n");
    for (int i = 0; i < n; i++){
        total_wt += wt[i];
        total_tat += tat[i];
        printf("   %d\t\t%d\t    %d\t\t  %d\n", processes[i], bt[i], wt[i], tat[i]);
    }

    printf("Average waiting time = %.2f\n", (float)total_wt / (float)n);
    printf("Average turn around time = %.2f\n", (float)total_tat / (float)n);

    printGanttChart(processes, n, bt);
}

int main(){
    int n;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int processes[n], burst_time[n];

    // Input process IDs and burst times
    for (int i = 0; i < n; i++){
        processes[i] = i + 1;  // Process IDs as 1, 2, 3, ...
        printf("Enter burst time for process %d: ", processes[i]);
        scanf("%d", &burst_time[i]);
    }

    findavgTime(processes, n, burst_time);

    return 0;
}
