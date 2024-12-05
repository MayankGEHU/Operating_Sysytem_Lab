#include <stdio.h> 
int isPageInFrames(int frames[], int frameCount, int page) { 
    for (int i = 0; i < frameCount; i++) { 
        if (frames[i] == page) { 
            return i; 
        } 
    } 
    return -1; 
} 
void updateFrames(int frames[], int frameCount, int page, int index) { 
    for (int i = index; i < frameCount - 1; i++) { 
        frames[i] = frames[i + 1]; 
    } 
    frames[frameCount - 1] = page; 
} 
int main() { 
    int frameCount, pageCount, pageFaults = 0; 
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
        int page = pages[i]; 
        int pageIndex = isPageInFrames(frames, frameCount, page); 
        if (pageIndex == -1) { 
            pageFaults++; 
            for (int j = 0; j < frameCount - 1; j++) { 
                frames[j] = frames[j + 1]; 
            } 
            frames[frameCount - 1] = page; 
        } else { 
            updateFrames(frames, frameCount, page, pageIndex); 
        } 
    } 
    printf("Total number of page faults: %d\n", pageFaults); 
    return 0; 
} 