// CS475W lab05 Mutual Exclusion
// Simulation of process for 'x' amount of time
// Due time: 4/1/2021 Thursday
// Student name: Bishesh Tuladhar, Xavier Betancourt

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

#define NUM_PHILOSOPHERS 5 // 5 philosophers, numbered 0 to 4

void think(int);
void pickUpChop(int);
void eat(int);
void putDownChop(int);

pthread_mutex_t chopsticks[NUM_PHILOSOPHERS];
pthread_t philosophers[NUM_PHILOSOPHERS];
pthread_attr_t attribute[NUM_PHILOSOPHERS];

int main(void)
{
    printf("HOla bisheshh");
    
    return 0;
}

void think(int philosopherIndex)
{
    int thinkingTime = rand() % 4 + 1; // philosopher thinks 1 - 3 seconds
    printf("Philosopher %d thinks for %d seconds\n", philosopherIndex, thinkingTime);
    sleep(thinkingTime);  
}





