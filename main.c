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

/*
    Each pilosophers thinks for a random amount of time (we chose 1-3s thinking time)
    and then proceeds to eat
*/
void think(int);

void pickUpChop(int);
void putDownChop(int);

/*
    Each pilosophers eats for a random amount of time (we chose 1-2s thinking time)
    and then puts down the chopsticks
*/
void eat(int);

pthread_mutex_t chopsticks[NUM_PHILOSOPHERS];
pthread_t philosophers[NUM_PHILOSOPHERS];
pthread_attr_t attribute[NUM_PHILOSOPHERS];

int main(void)
{
    int num = 1%5;
    int num2 = 2%5;
    int num3 = 3%5;
    int num4 = 4%5;
    int num5 = 5%5;

    printf("Result %d", num5);
    
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
}

void eat(int philosopherIndex)
{
    int eatTime = rand() % 3 + 1; // philosopher thinks 1 - 2 seconds
    printf("Philosopher % d eats for %d seconds\n", philosopherIndex, eatTime);
    sleep(eatTime); // sleep for random time, philosopher eating
}





