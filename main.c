// CS475W lab05 Mutual Exclusion
// Simulation of process for the classic Dinning Philosopher problem for 'x' amount of time
// Due time: 4/1/2021 Thursday
// Student name: Bishesh Tuladhar, Xavier Betancourt

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

#define NUM_PHILOSOPHERS 5 // 5 philosophers, numbered 0 to 4

/*
    Each pilosophers thinks for a random amount of time (we chose 1-3s thinking time)
    and then proceeds to eat
*/
void think(int);

/*
    Each philosopher, based on the index (odd or even), will proceed to pick up chopstics.
    First, odd index philosophers get to pick up their left and then right chopstick. When they are
    done, even index philosphers get to pick their right and then left chopsticks. This way, we can also
    prevent a deadlock when proceeding sequentially.
*/
void pickUpChop(int);

/*
    Unlock each mutex for left or right-hand chopstick that a philosopher grabbed
*/
void putDownChop(int);

/*
    Each pilosophers eats for a random amount of time (we chose 1-2s thinking time)
    and then puts down the chopsticks
*/
void eat(int);

/*

*/
void *philosopher( void*);

pthread_mutex_t chopsticks[NUM_PHILOSOPHERS];
pthread_t philosophers[NUM_PHILOSOPHERS];
pthread_attr_t attribute[NUM_PHILOSOPHERS];

int main(void)
{
    // Initialize everything here
    
    return 0;
}


void think(int philosopherIndex)
{
    int thinkingTime = rand() % 4 + 1; // philosopher thinks 1 - 3 seconds
    printf("Philosopher %d thinks for %d seconds\n", philosopherIndex, thinkingTime);
    sleep(thinkingTime);  // sleep for random time, philosopher is thinking 
}

void pickUpChop(int philosopherIndex)
{
    // Index of philosopher is the same as the index of chopstick to the left. Index of philosopher + 1 is the same as the index of
    // chopstick to the right.
    // Example, philosopher[0] has left chopstick 0 and right chopstick 1
    int rightChop = (philosopherIndex + 1) % NUM_PHILOSOPHERS; 
    int leftChop = (philosopherIndex + NUM_PHILOSOPHERS) % NUM_PHILOSOPHERS;

    if(philosopherIndex % 2 != 0) // odd philosopher index
    {
        printf("Philosopher %d is waiting to pick up left chopstick %d\n", philosopherIndex, leftChop);
		pthread_mutex_lock(&chopsticks[leftChop]);
		printf("Philosopher %d picked up left chopstick %d\n", philosopherIndex, leftChop);
		printf("Philosopher %d is waiting to pick up right chopstick %d\n", philosopherIndex, rightChop);
		pthread_mutex_lock(&chopsticks[rightChop]);
		printf("Philosopher %d picked up right chopstick %d\n", philosopherIndex, rightChop);
    } else { // even philsopher index
        printf("Philosopher %d is waiting to pick up right chopstick %d\n", philosopherIndex, rightChop);
		pthread_mutex_lock(&chopsticks[rightChop]);
		printf("Philosopher %d picked up right chopstick %d\n", philosopherIndex, rightChop);
		printf("Philosopher %d is waiting to pick up left chopstick %d\n", philosopherIndex, leftChop);
		pthread_mutex_lock(&chopsticks[leftChop]);
		printf("Philosopher %d picked up left chopstick %d\n", philosopherIndex, leftChop);
    }
}

void eat(int philosopherIndex)
{
    int eatTime = rand() % 3 + 1; // philosopher thinks 1 - 2 seconds
    printf("Philosopher % d eats for %d seconds\n", philosopherIndex, eatTime);
    sleep(eatTime); // sleep for random time, philosopher eating
}

void putDownChop(int philosopherIndex)
{
    pthread_mutex_unlock(&chopsticks[(philosopherIndex + 1) % NUM_PHILOSOPHERS]); // Unlock mutex for right-hand chopstick
    printf("Philosopher &d put down his right-hand chopstick", philosopherIndex);
    pthread_mutex_unlock(&chopsticks[(philosopherIndex + NUM_PHILOSOPHERS) % NUM_PHILOSOPHERS]); // Unlock mutex for left-hand chopstick
     printf("Philosopher &d put down his left-hand chopstick", philosopherIndex);
}

void *philosopher( void *philosopherIndex)
{
    while(1)
    {
        think(philosopherIndex);
        pickUpChop(philosopherIndex);
        eat(philosopherIndex);
        putDownChop(philosopherIndex);
    }
}





