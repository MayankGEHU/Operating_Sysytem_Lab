#include <stdio.h>
#include <stdlib.h>
void main() {
    int requests[100], i, j, n, TotalHeadMoments = 0, initial, size, move, index;
    printf("Enter Number of Requests:");
    scanf("%d", &n);

    printf("\nEnter Requests sequence:");
    for (i = 0; i < n; i++)
        scanf("%d", &requests[i]);

    printf("\nEnter Initial Head Positions:");
    scanf("%d", &initial);

    printf("\nEnter Total Disk size:");
    scanf("%d", &size);

    printf("Enter Head Movements Directions(high = 1 and low = 0):");
    scanf("%d", &move);

    for (i = 0; i < n; i++)
        for (j = 0; j < n - i - 1; j++)
            if (requests[j] > requests[j + 1]){
                int temp;
                temp = requests[j];
                requests[j] = requests[j + 1];
                requests[j + 1] = temp;
            }

    for (i = 0; i < n; i++)
        if (initial < requests[i])
        {
            index = i;
            break;
        }

    if (move == 1)
    {
        for (i = index; i < n; i++)
        {
            TotalHeadMoments = TotalHeadMoments + abs(requests[i] - initial);
            initial = requests[i];
        }

        TotalHeadMoments = TotalHeadMoments + abs(size - requests[i - 1] - 1);

        TotalHeadMoments = TotalHeadMoments + abs(size - 1 - 0);
        initial = 0;

        for (i = 0; i < index; i++)
        {
            TotalHeadMoments = TotalHeadMoments + abs(requests[i] - initial);
            initial = requests[i];
        }
    }

    else
    {
        for (i = index - 1; i >= 0; i--)
        {
            TotalHeadMoments = TotalHeadMoments + abs(requests[i] - initial);
            initial = requests[i];
        }

        TotalHeadMoments = TotalHeadMoments + abs(requests[i + 1] - 0);

        TotalHeadMoments = TotalHeadMoments + abs(size - 1 - 0);
        initial = size - 1;

        for (i = n - 1; i >= index; i--)
        {
            TotalHeadMoments = TotalHeadMoments + abs(requests[i] - initial);
            initial = requests[i];
        }
    }
    printf("Total head movement is %d", TotalHeadMoments);
}