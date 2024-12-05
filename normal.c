#include <stdio.h>
#include <stdlib.h>
void C_SCAN(int requests[], int n, int head, int disk_size)
{
    int seek = 0;
    int temp_requests[n + 2];
    temp_requests[0] = head;
    temp_requests[n + 1] = disk_size - 1;
    for (int i = 0; i < n; i++)
        temp_requests[i + 1] = requests[i];
    n += 2;
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (temp_requests[j] > temp_requests[j + 1])
            {
                int temp = temp_requests[j];
                temp_requests[j] = temp_requests[j + 1];
                temp_requests[j + 1] = temp;
            }
    int pos = 0;

    for (int i = 0; i < n; i++)
        if (temp_requests[i] == head)
        {
            pos = i;
            break;
        }
    for (int i = pos + 1; i < n; i++)
    {
        seek += abs(temp_requests[i] - head);
        head = temp_requests[i];
    }
    for (int i = 0; i < pos; i++)
    {
        seek += abs(temp_requests[i] - head);
        head = temp_requests[i];
    }
    printf("Total seek movement: %d\n", seek);
}
int main()
{
    int n, head, disk_size = 200;
    printf("Enter number of disk requests: ");
    scanf("%d", &n);
    int requests[n];
    printf("Enter the disk requests: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &requests[i]);
    }
    printf("Enter the initial head position: ");
    scanf("%d", &head);
    C_SCAN(requests, n, head, disk_size);
    return 0;
}
