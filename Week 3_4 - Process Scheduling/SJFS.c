// #include<stdio.h>

// int main(){
//     int bt[20], p[20], wt[20], tat[20], i, j, n, total = 0, pos, temp;
//     float avg_wt, avg_tat;

//     // Input number of processesN
//     printf("Enter number of processes: ");
//     scanf("%d", &n);

//     // Input burst times
//     printf("\nEnter Burst Time:\n");
//     for(i = 0; i < n; i++) {
//         printf("p%d: ", i+1);
//         scanf("%d", &bt[i]);
//         p[i] = i+1;  // Storing process number
//     }

//     // Sorting burst times in ascending order using selection sort
//     for(i = 0; i < n; i++) {
//         pos = i;
//         for(j = i + 1; j < n; j++) {
//             if(bt[j] < bt[pos]) {
//                 pos = j;
//             }
//         }

//         // Swapping burst times
//         temp = bt[i];
//         bt[i] = bt[pos];
//         bt[pos] = temp;

//         // Swapping process numbers
//         temp = p[i];
//         p[i] = p[pos];
//         p[pos] = temp;
//     }

//     // Waiting time for the first process is 0
//     wt[0] = 0;

//     // Calculating waiting times
//     for(i = 1; i < n; i++) {
//         wt[i] = 0;
//         for(j = 0; j < i; j++) {
//             wt[i] += bt[j];
//         }
//         total += wt[i];
//     }

//     // Average waiting time
//     avg_wt = (float)total / n;
//     total = 0;

//     // Print table header
//     printf("\n----------------------------------------------------------");
//     printf("\n| Process | Burst Time | Waiting Time | Turnaround Time |");
//     printf("\n----------------------------------------------------------");

//     // Calculating turnaround times and printing the table rows
//     for(i = 0; i < n; i++) {
//         tat[i] = bt[i] + wt[i];  // Turnaround time = burst time + waiting time
//         total += tat[i];
//         printf("\n|   p%d    |     %d      |      %d       |       %d       |", p[i], bt[i], wt[i], tat[i]);
//     }

//     // Average turnaround time
//     avg_tat = (float)total / n;

//     // Print footer
//     printf("\n----------------------------------------------------------");
//     printf("\nAverage Waiting Time = %.2f", avg_wt);
//     printf("\nAverage Turnaround Time = %.2f\n", avg_tat);

//     // Printing the Gantt chart
//     printf("\n\nGantt Chart:\n");

//     // // Print the process execution sequence
//     // for(i = 0; i < n; i++) {
//     //     printf(" -------");
//     // }

//     printf("\n|");
//     for(i = 0; i < n; i++) {
//         printf("  p%d   |", p[i]);
//     }

//     // printf("\n");
//     // for(i = 0; i < n; i++) {
//     //     printf(" -------");
//     // }

//     printf("\n");

//     // Print the timeline
//     printf("0");
//     for(i = 0; i < n; i++) {
//         printf("      %d", wt[i] + bt[i]);
//     }
    
//     printf("\n");

//     return 0;
// }



#include<stdio.h>

void calculateWaitingTime(int n, int bt[], int wt[]){
    wt[0] = 0;

    for(int i = 0; i <n; i++) {
        wt[i] = 0;

        for(int j = 0; j < n; j++) {
            wt[i] += bt[i];
        }
    }
}

void calculateTAT(int n, int bt[], int wt[], int tat[]) {
    for(int i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];
    }
}


void sortProcessesByBurtTime(int n, int bt[], int processec[]){
    int pos, temp;

    for(int i = 0; i < n; i++) {
        pos = i;

        for(int j  = i + 1; j < n; j++) {
            if(bt[j] < bt[pos]) {
                pos = j;
            }
        }
        temp = bt[i];
        bt[i] = bt[pos];
        bt[pos] = temp;

        temp = processec[i];
        processec[i] = processec[pos];
        processec[pos] = temp;
    }    
}

// function to print details 

void printDetails(int n, int bt[], int wt[], int tat[], int processec[]) {
    printf("print all thinf which is passed in the function");

    for(int i = 0; i < n; i++) {
        // printf("\n P %d do %d in what the amount iof the thing you want to print", t  );
    }
}


void printAvgTime(int tat[], int n, int wt[]) {
    float avg_wt = 0, avg_tat = 0, total_wt = 0, total_tat = 0;

    for(int i = 0 ; i < n; i++) {
        total_tat += wt[i];
        total_tat  += tat[i];
    }

    avg_tat = total_tat / n;
    avg_wt = total_wt / n;

   printf("avarget tat is ", avg_tat);
   printf("avg waitingf time is  ", avg_wt);
}


void printGanttChart(int n ,int p[], int bt[], int wt[], int tat[]) {

}


int main(){
    int n , i;

    int bt[n], wt[n], tat[n]; // you can  put use define value in the 

    printf("Enter the number of process ");
    scanf("%d", &n);

    printf("Enter the burst time");
    for(int i = 0 ; i < n ; i++) {
        scanf("%d", &bt[i]);
        // p[i] = i + 1;  process
    }
    // now out of this loop call all the function

    return 0;
}