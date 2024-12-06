#include <stdio.h>
#include <string.h>
#define MAX_FILES 10
#define MAX_BLOCKS 10
typedef struct
{
    char name[50];
    int startBlock;
    int blocks[MAX_BLOCKS];
    int numBlocks;
} File;
void indexedAllocation(File files[], int n, char searchFile[])
{
    for (int i = 0; i < n; i++)
    {
        if (strcmp(files[i].name, searchFile) == 0)
        {
            printf("File Name: %s\n", files[i].name);
            printf("Start block: %d\n", files[i].startBlock);
            printf("No of blocks: %d\n", files[i].numBlocks);
            printf("Blocks occupied: ");
            for (int j = 0; j < files[i].numBlocks; j++)
            {
                printf("%d", files[i].blocks[j]);
                if (j < files[i].numBlocks - 1)
                    printf(", ");
            }
            printf("\n");
            return;
        }
    }
    printf("File not found\n");
}
int main()
{
    int n;
    File files[MAX_FILES];
    char searchFile[50];
    printf("Enter number of files: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("Enter file %d name: ", i + 1);
        scanf("%s", files[i].name);
        printf("Enter starting block of file %d: ", i + 1);
        scanf("%d", &files[i].startBlock);
        printf("Enter no of blocks in file %d: ", i + 1);
        scanf("%d", &files[i].numBlocks);
        printf("Enter blocks for file %d: ", i + 1);
        for (int j = 0; j < files[i].numBlocks; j++)
        {
            scanf("%d", &files[i].blocks[j]);
        }
    }
    printf("Enter the file name to be searched: ");
    scanf("%s", searchFile);
    indexedAllocation(files, n, searchFile);
    return 0;
}
