#include<stdio.h>

void calculateWaittingTime(int processec[], int n, int bt[], int wt[]){
    wt[0] = 0;

    for(int i = 1; i < n; i++) {
        wt[i] = wt[i - 1] + bt[i - 1];
    }
}

void calculateTat(int processec[], int n, int bt[], int wt[], int tat[]) {
    for(int i = 0; i < n; i++) {
        tat[i] = wt[i] + bt[i];
    }
}

void printGanttChart(int processec[], int n, int bt[], int wt[], int tat[]) {
    printf("Gantt chart for FCFS");
    int time = 0;

    for(int i = 0; i < n; i++) {
        printf("P%d", processec[i]);
    }
    printf("%d",time);
    for(int i = 0; i < n; i++) {
        time += bt[i];
        printf("%d", time);
    }
}

void avaTiming(int processec[], int n, int bt[]) {
    int wt[n], tat[n], total_wt = 0, totat_tat = 0;
    calculateWaittingTime(processec, n , bt, wt);
    calculateTat(processec, n, bt, wt, tat);

    printf("Porcess    BurstTime    Waiting Time     TurnAroundTime");

    for(int i = 0; i < n; i++) {
        total_wt += wt[i];
        totat_tat += tat[i];

        printf("%d\t\t%d\t\t%d\t\t%d\t\t", processec[i], bt[i], wt[i], tat[i]);

        printf("Avarage waiting time is  : " ,(float) total_wt / (float)n);
        printf("Avarge tata"  "same as above");
    }
}


int main(){

}