/* hello_signal.c */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>


int ready = 1;

void handler(int signum)
{ //signal handler
  printf("Hello World!\n");
  ready = 0;
}

int main(int argc, char * argv[])
{
  signal(SIGALRM,handler); //register handler to handle SIGALRM
  while(1) { //for second part of the question
    alarm(1); //Schedule a SIGALRM for 1 second
    while(ready); //keep running till I have prnted helloWord in handler
    printf("Turing was right!\n");
    ready = 1;
  }
  return 0; 
}