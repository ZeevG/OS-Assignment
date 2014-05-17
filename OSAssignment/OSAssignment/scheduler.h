//
//  scheduler.h
//  OSAssignment
//
//  Created by Work on 20/04/2014.
//  Copyright (c) 2014 ZeevG. All rights reserved.
//

#ifndef OSAssignment_scheduler_h
#define OSAssignment_scheduler_h

#include "linkedlist.h"
#include "processqueue.h"





//Old things

typedef struct Scheduler{
    int complete;
    int time;
    int timeQuantum;
    Process* currentProcess;
    ProcessQueue* processList;
    ProcessQueue* readyQueue;
    ProcessQueue* finishedQueue;
} Scheduler;

typedef struct TimeSlice{
    int processNumber;
    int cpuBurst;
    struct TimeSlice* next;
} TimeSlice;

void run(Scheduler* self);
void updateTime(Scheduler* self);
void step(Scheduler* self);

//
//void addProcess(Scheduler* sched, int arrival, int burst);
//
//void printGantt(Scheduler* sched);
//
//void deleteScheduler(Scheduler* sched);
//
//void addTimeSlice(TimeSlice* timeSlice, int number, int burst);

#endif
