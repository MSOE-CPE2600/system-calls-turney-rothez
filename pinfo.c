//*****************************************************************************
// pinfo.c
// Zane Rothe
// CPE 2600 - 111
// Lab 9
//*****************************************************************************
#define _GNU_SOURCE
#include <stdio.h>
#include <sched.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/resource.h>
#include <string.h>

int main(int argc, char* argv[])
{
    int pid;
    if (argc>1) // if argument given
    {
        char *error;
        pid=strtod(argv[1],&error); // convert to int
        if(argv[1]==error) // if int not given
        {
            printf("Invalid Process ID\n");
            exit(1);
        }
    }
    else
    {
        pid=getpid(); // otherwise use program process id
    }
    printf("Process ID: %d\n",pid);

    int priority=getpriority(PRIO_PROCESS,pid); // get priority

    int policy=sched_getscheduler(pid); // get schedule policy
    char policy_name[20];
    switch (policy)  // select proper policy from int
    {
        case SCHED_OTHER: 
            strcpy(policy_name,"Other");
            break;
        case SCHED_FIFO: 
            strcpy(policy_name,"First in first out");
            break;
        case SCHED_RR: 
            strcpy(policy_name,"Round robin");
            break;
        case SCHED_BATCH: 
            strcpy(policy_name,"Batch");
            break;
        case SCHED_IDLE: 
            strcpy(policy_name,"Idle");
            break;
        default:
            printf("Invalid Process ID\n");
            exit(1);
            break;
    }
    printf("Priority: %d\n",priority);
    printf("Policy: %s\n",policy_name);
}

