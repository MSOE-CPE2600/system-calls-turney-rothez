//*****************************************************************************
// info.c
// Zane Rothe
// CPE 2600 - 111
// Lab 9
//*****************************************************************************
#include <time.h>
#include <stdio.h>
#include <math.h>
#include <sys/utsname.h>
#include <sys/sysinfo.h>
#include <unistd.h>

void time_of_day (void);
void sys_info(void);
void num_processors(void);
void show_mem(void);

int main(int argc, char* argv[])
{

    time_of_day(); // display time of day in nanoseconds
    sys_info(); // display various system info
    num_processors(); // display number of processors
    show_mem(); // display memory
    
    return 0;
}

void time_of_day (void) // display time of day in nanoseconds
{
    struct timespec ts; // struct ts contains time information
    if (!clock_gettime(CLOCK_REALTIME,&ts))// Update struct, 0 if success
    {
        long int nanotime=\
        (long int)((ts.tv_sec-3600*6)*1e9+ts.tv_nsec)%(long int)(1e9*3600*24);
        int hours= nanotime/(1e9*60*60);
        int minutes= (nanotime/(1e9*60))-hours*60;
        int seconds= (nanotime/(1e9))-hours*60*60-minutes*60;
        int nanosecs= nanotime-hours*60*60*1e9-minutes*60*1e9-seconds*1e9;
        printf("Nanoseconds since 12am (UTC-6): %ld\n", nanotime);//ns since 12
        printf("Time is %d:%02d:%02d and %d ns\n"\
        ,hours,minutes,seconds,nanosecs); //time displayed
    }
    return;
}

void sys_info(void) // display various system info
{
    struct utsname buf; // struct contiang system information
    if (!uname(&buf)) // update struct, 0 if success
    {
        printf("Network name is %s\n",buf.nodename);
        printf("Operating system is %s\n",buf.sysname);
        printf("Release %s\n",buf.release);
        printf("Version %s\n",buf.version);
        printf("Running on %s\n",buf.machine);
    }
    
    return;
}

void num_processors(void) // display number of processors
{
    if(get_nprocs()) // >0 if success
    {
        printf("Number of processors: %d\n",get_nprocs()); // gets num of procs
    }
    return;
}

void show_mem(void) // display memory
{
    // amount of memory expressed in pages. Page size is in bytes
    long int pages=sysconf(_SC_PHYS_PAGES);
    long int avpages=sysconf(_SC_AVPHYS_PAGES);
    long int size=sysconf(_SC_PAGESIZE);
    if (pages != -1 || size != -1 || avpages != -1) //returns -1 if error
    {
        printf("Total memory: %ld bytes\n",pages*size);
        printf("Available memory: %ld bytes\n",avpages*size);
    }
    return;
}