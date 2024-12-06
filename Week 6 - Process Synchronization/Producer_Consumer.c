/*
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define MaxItems 5
#define BufferSize 5

int buffer[BufferSize];
int in = 0;
int out = 0;
int itemCount = 0;

pthread_mutex_t mutex;
pthread_cond_t notFull;
pthread_cond_t notEmpty;

int produceItem() {
    return rand() % 100;
}

void insertItem(int item) {
    buffer[in] = item;
    in = (in + 1) % BufferSize;
    itemCount++;
}

int removeItem() {
    int item = buffer[out];
    out = (out + 1) % BufferSize;
    itemCount--;
    return item;
}

void* producer(void* arg) {
    int id = *(int*)arg;
    for (int i = 0; i < MaxItems; i++) {
        int item = produceItem();
        pthread_mutex_lock(&mutex);

        while (itemCount == BufferSize) 
            pthread_cond_wait(&notFull, &mutex);

        insertItem(item);
        printf("Producer %d: Insert Item %d at %d\n", id, item, (in - 1 + BufferSize) % BufferSize);

        pthread_cond_signal(&notEmpty); 
        pthread_mutex_unlock(&mutex);

        usleep(100000); 
    }
    return NULL;
}

void* consumer(void* arg) {
    int id = *(int*)arg;
    for (int i = 0; i < MaxItems; i++) {
        pthread_mutex_lock(&mutex);

        while (itemCount == 0) 
            pthread_cond_wait(&notEmpty, &mutex);

        int item = removeItem();
        printf("Consumer %d: Remove Item %d from %d\n", id, item, (out - 1 + BufferSize) % BufferSize);

        pthread_cond_signal(&notFull); 
        pthread_mutex_unlock(&mutex);

        usleep(150000); 
    }
    return NULL;
}

int main() {
    pthread_t producers[5], consumers[5];
    int ids[5] = {1, 2, 3, 4, 5};

    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&notFull, NULL);
    pthread_cond_init(&notEmpty, NULL);
    for (int i = 0; i < 5; i++) {
        pthread_create(&producers[i], NULL, producer, &ids[i]);
    }
    for (int i = 0; i < 5; i++) {
        pthread_create(&consumers[i], NULL, consumer, &ids[i]);
    }

    for (int i = 0; i < 5; i++) {
        pthread_join(producers[i], NULL);
        pthread_join(consumers[i], NULL);
    }

    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&notFull);
    pthread_cond_destroy(&notEmpty);

    return 0;
}

 */