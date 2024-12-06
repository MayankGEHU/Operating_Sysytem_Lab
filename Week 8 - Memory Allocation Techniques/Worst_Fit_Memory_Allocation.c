#include <stdio.h>

void worstFit(int blocks[], int b, int processes[], int p) {
    int allocation[p];

    for (int i = 0; i < p; i++) {
        allocation[i] = -1;
    }

    for (int i = 0; i < p; i++) {
        int worst_idx = -1;
        for (int j = 0; j < b; j++) {
            if (blocks[j] >= processes[i]){
                if (worst_idx == -1 || blocks[worst_idx] < blocks[j]){
                    worst_idx = j;
                }
            }
        }

        if (worst_idx != -1) {
            allocation[i] = worst_idx;
            blocks[worst_idx] -= processes[i];
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
    
    worstFit(blocks, b, processes, p);
    return 0;
}
