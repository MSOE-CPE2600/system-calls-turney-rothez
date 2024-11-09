//*****************************************************************************
// finfo.c
// Zane Rothe
// CPE 2600 - 111
// Lab 9
//*****************************************************************************
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

void show_type(int mode); //shows file type
void show_perm(int mode); //shows permissions
void show_owner(int uid); //show user id of owner
void show_size(int size); //shows file size in bytes
void show_time(time_t time); //shows time last modified

int main(int argc, char* argv[])
{
    struct stat buf; //struct contains file info
    //add filepath as argument when executing program
    if (!stat(argv[1], &buf)) //returns 0 on success
    {
        show_type(buf.st_mode);
        show_perm(buf.st_mode);
        show_owner(buf.st_uid);
        show_size(buf.st_size);
        show_time(buf.st_mtime);
    }
    else
    {
        printf("Invalid or no directory given\n");
    }
    return 0;
}

void show_type(int mode) //shows file type
{
    printf("File type: ");
    // decode file type
    if (S_ISREG(mode))
    {
        printf("Regular file\n");
    }
    if (S_ISDIR(mode))
    {
        printf("Directory\n");
    }
    if (S_ISCHR(mode))
    {
        printf("Character device\n");
    }
    if (S_ISBLK(mode))
    {
        printf("Block device\n");
    }
    if (S_ISFIFO(mode))
    {
        printf("FIFO\n");
    }
    if (S_ISLNK(mode))
    {
        printf("Symbolic link\n");
    }
    if (S_ISSOCK(mode))
    {
        printf("Socket\n");
    }
    return;
}

void show_perm(int mode) //shows permissions
{
    // decode file permissions (bitwise with drwxrwxrwx)
    printf("Owner permissions: ");
    if (mode & S_IRUSR)
    {
        printf("read ");
    }
    if (mode & S_IWUSR)
    {
        printf("write ");
    }
    if (mode & S_IXUSR)
    {
        printf("execute ");
    }

    printf("\nGroup permissions: ");
    if (mode & S_IRGRP)
    {
        printf("read ");
    }
    if (mode & S_IWGRP)
    {
        printf("write ");
    }
    if (mode & S_IXGRP)
    {
        printf("execute ");
    }

    printf("\nOthers permissions: ");
    if (mode & S_IROTH)
    {
        printf("read ");
    }
    if (mode & S_IWOTH)
    {
        printf("write ");
    }
    if (mode & S_IXOTH)
    {
        printf("execute ");
    }
    printf("\n");
    return;
}

void show_owner(int uid) //show user id of owner
{
    printf("Owner user ID: %d\n",uid);
    return;
}

void show_size(int size) //shows file size in bytes
{
    printf("File size: %d bytes\n",size);
    return;
}

void show_time(time_t time) //shows time last modified
{
    printf("Last modified: %s\n",ctime(&time));
    return;
}