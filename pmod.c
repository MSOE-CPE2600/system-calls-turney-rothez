//*****************************************************************************
// pmod.c
// Zane Rothe
// CPE 2600 - 111
// Lab 9
//*****************************************************************************
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/resource.h>
#include <time.h>

int main(int argc, char* argv[])
{
    int pid=getpid(); // use program process id
    printf("Process ID: %d\n",pid);
    int priority=getpriority(PRIO_PROCESS,pid); // get priority
    printf("Priority: %d\n",priority);
    priority=nice(10); // increase priority number (decrease priority) by 10
    printf("New Priority: %d\n",priority);
    
    struct timespec req; // make struct of requested sleep time (s+ns)
    req.tv_sec = 1;
    req.tv_nsec = 837272638;

    if (!nanosleep(&req, NULL)) //sleep successful returns 0
    {
        printf("Goodbye. Slept %ld ns\n",(long int)(req.tv_sec*1e9+req.tv_nsec));
    }
    else
    {
        printf("Did not sleep");
    }
}

