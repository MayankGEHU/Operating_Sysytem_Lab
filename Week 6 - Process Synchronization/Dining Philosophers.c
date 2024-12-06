/*
#include <stdio.h>
#include <stdlib.h>
// #include <pthread.h>
#include <unistd.h>
#define NUM_PHILOSOPHERS 5
pthread_mutex_t forks[NUM_PHILOSOPHERS];
pthread_t philosophers[NUM_PHILOSOPHERS];
int philosopher_ids[NUM_PHILOSOPHERS];
void think(int philosopher_id) {
    printf("Philosopher %d is thinking.\n", philosopher_id);
    sleep(rand() % 3 + 1);
}
void eat(int philosopher_id) {
    printf("Philosopher %d is eating.\n", philosopher_id);
    sleep(rand() % 2 + 1);
}
void *philosopher(void *arg) {
    int philosopher_id = *((int *)arg);
    while (1)     {
        think(philosopher_id);
        int left_fork = philosopher_id;
        int right_fork = (philosopher_id + 1) % NUM_PHILOSOPHERS;
        pthread_mutex_lock(&forks[left_fork]);
        printf("Philosopher %d picked up left fork %d.\n", philosopher_id, left_fork);
        pthread_mutex_lock(&forks[right_fork]);
        printf("Philosopher %d picked up right fork %d.\n", philosopher_id, right_fork);
        eat(philosopher_id);
        pthread_mutex_unlock(&forks[right_fork]);
        printf("Philosopher %d put down right fork %d.\n", philosopher_id, right_fork);
        pthread_mutex_unlock(&forks[left_fork]);
        printf("Philosopher %d put down left fork %d.\n", philosopher_id, left_fork);
    }
    return NULL;
}
int main() {
    for (int i = 0; i < NUM_PHILOSOPHERS; i++) {
        pthread_mutex_init(&forks[i], NULL);
        philosopher_ids[i] = i;
    }
    for (int i = 0; i < NUM_PHILOSOPHERS; i++)  {
        pthread_create(&philosophers[i], NULL, philosopher, &philosopher_ids[i]);
    }
    for (int i = 0; i < NUM_PHILOSOPHERS; i++)  {
        pthread_join(philosophers[i], NULL);
    }
    for (int i = 0; i < NUM_PHILOSOPHERS; i++) {
        pthread_mutex_destroy(&forks[i]);
    }
    return 0;
}
*/
#include <stdio.h>

int p[5];   
int ch[5];  

void signal(int y) {
    int right = (y + 1) % 5; 
    p[y] = 0;                
    ch[y] = 0;                
    ch[right] = 0;           
}

void wait(int y) {
    int right = (y + 1) % 5;  
    if (ch[y] == 0 && ch[right] == 0) { 
        p[y] = 1;                      
        ch[y] = 1;               
        ch[right] = 1;               
        printf("Philosopher %d is Eating.\n", y);
    } else if (p[y] == 1) {            
        int w;
        printf("Philosopher %d is already eating. Do you want them to stop? (1 for yes, 0 for no): ", y);
        scanf("%d", &w);
        if (w == 1) {
            signal(y);                
            printf("Philosopher %d has stopped eating and is now Thinking.\n", y);
        }
    } else {                         
        printf("Chopsticks %d and %d are busy. Philosopher %d has to wait.\n", y, right, y);
    }
}

int main() {
    int u;

    for (int i = 0; i < 5; i++) {
        p[i] = 0;  
        ch[i] = 0; 
    }

    do {
        for (int i = 0; i < 5; i++) {
            if (p[i] == 0) {
                printf("Philosopher %d is Thinking.\n", i);
            } else {
                printf("Philosopher %d is Eating.\n", i);
            }
        }
        int s;
        printf("Enter the Philosopher number (0-4) who wants to eat: ");
        scanf("%d", &s);
        if (s >= 0 && s < 5) {
            wait(s);
        } else {
            printf("Invalid Philosopher number! Please enter a number between 0 and 4.\n");
        }
        printf("\nDo you want to continue? Press 1 for Yes, 0 for No: ");
        scanf("%d", &u);

    } while (u == 1);

    return 0;
}
