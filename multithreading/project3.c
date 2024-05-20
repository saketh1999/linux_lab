#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#define NUM_THREADS 5
#define NUM_PRINTS 5
int CurrentID = 1;
int notMyTurnCount[NUM_THREADS];
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
void* threadFunction(void* arg) {
   int myID = *((int*) arg);
   int prints = 0;
   while (prints < NUM_PRINTS) {
       pthread_mutex_lock(&mutex);
       if (CurrentID != myID) {
           printf("Not My Turn! ThreadID: %d\n", myID);
           notMyTurnCount[myID - 1]++;
           pthread_mutex_unlock(&mutex);
       } else {
           printf("My Turn! ThreadID: %d\n", myID);
           CurrentID++;
           if (CurrentID == 6)
               CurrentID = 1;
           prints++;
           pthread_mutex_unlock(&mutex);
       }
   }
   return NULL;
}
int main() {
   pthread_t threads[NUM_THREADS];
   int threadIDs[NUM_THREADS];
   for (int i = 0; i < NUM_THREADS; i++) {
       threadIDs[i] = i + 1;
       notMyTurnCount[i] = 0;
       pthread_create(&threads[i], NULL, threadFunction, &threadIDs[i]);
   }
   for (int i = 0; i < NUM_THREADS; i++) {
       pthread_join(threads[i], NULL);
   }
   printf("\nNumber of 'Not My Turn!' prints for each thread:\n");
   for (int i = 0; i < NUM_THREADS; i++) {
       printf("Thread %d: %d\n", i + 1, notMyTurnCount[i]);
   }
   return 0;
}
