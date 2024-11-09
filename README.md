# System Calls
Zane Rothe

## Overview
System calls are used by programmers to interface directly with the operating system from within C code. This allows for command-line style processes to occur as part of a program. Many libc functions contain system calls within them, however system calls themselses are lower-level functions that can be executed on their own. This laboratory aims to familiarize students with using system calls within their C programs. This repository contains the following four programs.

## info.c
This program provides basic system information by retreiving it and printing to the console. Provided are:
- Number of nanoseconds since 12am
- Current time with nanosecond resolution
- Network name
- Operating system
- Operating system release
- Operating ststem version
- Hardware
- Number of processors
- Total memory in bytes
- Available memory in bytes

## pinfo.c
This program provides basic process information for the program itself or another process input by the user as an argument. Provided are:
- Process ID number
- Nice priority
- Prioritization policy

## pmod.c
This program performs basic process modifications to the program itself. Provided are:
- Process ID number
- Nice priority

Then the process priority is decreased by ten and shown. The program then sleeps for 1837272638 nanoseconds.

## finfo.c
This program provides basic file information for a file input by the user as an argument. Provided are:
- File type
- Owner permissions
- Group permissions
- Others permissions
- Owner user ID
- File size in bytes
- Time of last modification
