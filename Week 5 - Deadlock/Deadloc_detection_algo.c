#include <stdio.h>
#define MAX 10
int isDeadlockDetected(int processes, int resources, int max[MAX][MAX], int allocation[MAX][MAX], int available[MAX]) {
    int finish[MAX] = {0};
    int work[MAX];

    for (int i = 0; i < resources; i++) {
        work[i] = available[i];
    }
    
    int count = 0;
    while (count < processes) {
        int processFound = 0;
        for (int i = 0; i < processes; i++){
            if (!finish[i]) {
                int canProceed = 1;
                for (int j = 0; j < resources; j++) {
                    if (max[i][j] - allocation[i][j] > work[j]) {
                        canProceed = 0;
                        break;
                    }
                }
                if (canProceed) {
                    for (int j = 0; j < resources; j++) {
                        work[j] += allocation[i][j];
                    }
                    finish[i] = 1;
                    count++;
                    processFound = 1;
                    break;
                }
            }
        }
        if (!processFound){
            return 1;
        }
    }
    return 0;
}
int main(){
    int processes, resources;
    printf("Enter number of processes: ");
    scanf("%d", &processes);
    printf("Enter number of resources: ");
    scanf("%d", &resources);
    int max[MAX][MAX], allocation[MAX][MAX], available[MAX];
    printf("Enter maximum requirement matrix:\n");
    for (int i = 0; i < processes; i++){
        for (int j = 0; j < resources; j++){
            scanf("%d", &max[i][j]);
        }
    }
    printf("Enter allocated matrix:\n");
    for (int i = 0; i < processes; i++) {
        for (int j = 0; j < resources; j++){
            scanf("%d", &allocation[i][j]);
        }
    }
    printf("Enter available resource vector:\n");
    for (int i = 0; i < resources; i++) {
        scanf("%d", &available[i]);
    }
    if (isDeadlockDetected(processes, resources, max, allocation, available)){
        printf("Deadlock detected\n");
    } else {
        printf("No deadlock detected\n");
    }
    return 0;
}