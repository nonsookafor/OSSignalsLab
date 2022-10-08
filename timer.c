/* timer.c */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <time.h>

int ready = 1;
int alarmNumber = 0;
double time_spent;
clock_t start;

void handler(int signum)
{ //signal handler
  printf("Hello World!\n");
	alarmNumber += 1;
  ready = 0;
}

void handler1(int signum) {
	clock_t end = clock();
	time_spent += (double)(end - start) / CLOCKS_PER_SEC;
	printf("Execution time: %f\n", time_spent);
	printf("Number of Alarms: %d\n", alarmNumber);
	exit(1);
}

int main(int argc, char * argv[])
{
	time_spent = 0.0;
	start = clock();
	signal(SIGINT, handler1);
  signal(SIGALRM,handler); //register handler to handle SIGALRM
  while(1) { //for second part of the question
    alarm(1); //Schedule a SIGALRM for 1 second
    while(ready); //keep running till I have prnted helloWord in handler
    printf("Turing was right!\n");
    ready = 1;
  }
	return 0;
}
