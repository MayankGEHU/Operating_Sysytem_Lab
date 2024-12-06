// #include <stdio.h>
// #include <stdlib.h>
// #include <unistd.h>

// int main() {
//     pid_t pid;
//     int even_sum = 0, odd_sum = 0;
//     int n, i;

//     printf("Enter the range limit: ");
//     scanf("%d", &n);

//     pid = fork();

//     if (pid < 0) {
//         perror("Fork failed");
//         return 1;
//     }

//     if (pid == 0) {
//         for (i = 1; i <= n; i += 2) {
//             odd_sum += i;
//         }
//         printf("Sum of odd numbers: %d\n", odd_sum);
//     } else {
//         for (i = 0; i <= n; i += 2) {
//             even_sum += i;
//         }
//         printf("Sum of even numbers: %d\n", even_sum);
//         wait(NULL); 
//     }
//     return 0;
// }

#include<stdio.h>
#include<unistd.h>

int main(){
    pid_t pid = fork();

    if(pid < 0) {
        printf("Fork is faild \n");
        return 1;
    } else if(pid == 0) {
        printf("This is the child Process PID %d\n", getpid());
    } else {
        printf("This is parent Procss PID %d\n", getpid());
    }
    return 0;
}