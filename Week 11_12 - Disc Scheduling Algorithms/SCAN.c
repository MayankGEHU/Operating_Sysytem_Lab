#include <stdio.h>
#include <stdlib.h>

void scan(int tracks[], int n, int head, int diskSize) {
    int totalSeekMovement = 0;
    int sortedTracks[n + 2];
    int index = 0;

    sortedTracks[index++] = 0;       
    sortedTracks[index++] = diskSize; 

    for (int i = 0; i < n; i++) {
        sortedTracks[index++] = tracks[i];
    }
    
    for (int i = 0; i < index - 1; i++) {
        for (int j = i + 1; j < index; j++) {
            if (sortedTracks[i] > sortedTracks[j]) {
                int temp = sortedTracks[i];
                sortedTracks[i] = sortedTracks[j];
                sortedTracks[j] = temp;
            }
        }
    }

    int headPosition = 0;
    for (int i = 0; i < index; i++) {
        if (sortedTracks[i] >= head) {
            headPosition = i;
            break;
        }
    }

    for (int i = headPosition; i < index; i++) {
        totalSeekMovement += abs(head - sortedTracks[i]);
        head = sortedTracks[i];
    }

    for (int i = headPosition - 1; i >= 0; i--) {
        totalSeekMovement += abs(head - sortedTracks[i]);
        head = sortedTracks[i];
    }

    printf("Total seek movement: %d\n", totalSeekMovement);
}

int main() {
    int n, diskSize = 200, head;
    printf("Enter number of disk requests: ");
    scanf("%d", &n);

    int tracks[n];
    printf("Enter the disk requests: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &tracks[i]);
    }

    printf("Enter initial head position: ");
    scanf("%d", &head);

    scan(tracks, n, head, diskSize);
    return 0;
}
