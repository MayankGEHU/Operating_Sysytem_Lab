#include <stdio.h> 
int isPageInFrames(int frames[], int frameCount, int page) { 
    for (int i = 0; i < frameCount; i++) { 
        if (frames[i] == page) 
            return 1; 
    } 
    return 0; 
} 
int main() { 
    int frameCount, pageCount, pageFaults = 0, currentIndex = 0; 
    printf("Enter number of frames available: "); 
    scanf("%d", &frameCount); 
    printf("Enter number of requests: "); 
    scanf("%d", &pageCount); 
    int pages[pageCount], frames[frameCount]; 
    printf("Enter the page reference string: "); 
    for (int i = 0; i < pageCount; i++) { 
        scanf("%d", &pages[i]); 
    } 
    for (int i = 0; i < frameCount; i++) { 
        frames[i] = -1; 
    } 
    for (int i = 0; i < pageCount; i++) { 
        if (!isPageInFrames(frames, frameCount, pages[i])) { 
            frames[currentIndex] = pages[i]; 
            currentIndex = (currentIndex + 1) % frameCount; 
            pageFaults++; 
        } 
    } 
printf("Total number of page faults: %d\n", pageFaults); 
return 0; 
} 