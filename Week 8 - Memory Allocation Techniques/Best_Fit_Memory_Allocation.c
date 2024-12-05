#include <stdio.h>
void bestFit(int blocks[], int b, int processes[], int p) {
    int allocation[p];
    for (int i = 0; i < p; i++) {
        allocation[i] = -1;
    }
    for (int i = 0; i < p; i++) {
        int best_idx = -1;
        for (int j = 0; j < b; j++) {
            if (blocks[j] >= processes[i]) {
                if (best_idx == -1 || blocks[best_idx] > blocks[j]) {
                    best_idx = j;
                }
            }
        }
        if (best_idx != -1){
            allocation[i] = best_idx;
            blocks[best_idx] -= processes[i];
        }
    }
    for (int i = 0; i < p; i++){
        if (allocation[i] != -1)
            printf("%d - %d\n", processes[i], allocation[i] + 1);
        else
            printf("%d - no free block allocated\n", processes[i]);
    }
}
int main() {
    int b, p;
    printf("Enter number of free blocks available: ");
    scanf("%d", &b);
    int blocks[b];
    printf("Enter sizes of the blocks: ");
    for (int i = 0; i < b; i++) {
        scanf("%d", &blocks[i]);
    }
    printf("Enter number of processes: ");
    scanf("%d", &p);
    int processes[p];
    printf("Enter the memory requirements of processes: ");
    for (int i = 0; i < p; i++) {
        scanf("%d", &processes[i]);
    }
    bestFit(blocks, b, processes, p);
    return 0;
}
