#include <stdio.h>

void firstFit(int blocks[], int b, int processes[], int p) {
    int allocation[p];
    for (int i = 0; i < p; i++) {
        allocation[i] = -1;
    }

    for (int i = 0; i < p; i++) {
        for (int j = 0; j < b; j++){
            if (blocks[j] >= processes[i]){
                allocation[i] = j;
                blocks[j] -= processes[i];
                break;
            }
        }
    }
    
    for (int i = 0; i < p; i++){
        if (allocation[i] != -1)
            printf("%d - %d\n", processes[i], allocation[i] + 1);
        else
            printf("%d - no free block allocated\n", processes[i]);
    }
}
int main(){
    int b, p;

    printf("Enter number of free blocks available: ");
    scanf("%d", &b);

    int blocks[b];
    printf("Enter sizes of the blocks: ");
    for (int i = 0; i < b; i++){
        scanf("%d", &blocks[i]);
    }

    printf("Enter number of processes: ");
    scanf("%d", &p);

    int processes[p];
    printf("Enter the memory requirements of processes: ");
    for (int i = 0; i < p; i++){
        scanf("%d", &processes[i]);
    }

    firstFit(blocks, b, processes, p);
    return 0;
}
