//
//  scheduler.c
//  OSAssignment
//
//  Created by Work on 20/04/2014.
//  Copyright (c) 2014 ZeevG. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "scheduler.h"
#include "processqueue.h"



void run(Scheduler* self){
    self->readyQueue = initProcessQueue();
    self->finishedQueue = initProcessQueue();
    self->time = 0;
    self->complete = 0;
    self->currentProcess = NULL;
    
    while(self->complete == 0){
        
        
        updateTime(self);
        
        step(self);

        
        
    }
}

void updateTime(Scheduler* self){
    Process* next = NULL;

    self->time++;
    
    while (self->processList->length > 0 && next == NULL) {
        next = self->processList->start;

        if(next->arrival == self->time){
            //Dequeue the next process
            //Copy it to the ready queue
            //Free the original
            next = self->processList->dequeue(self->processList);
            self->readyQueue->enqueueCopy(self->readyQueue, next);
            free(next);
            next = NULL;
        }
    }
    
}
void step(Scheduler* self){
    // If there is no current process, then get one.
    if(self->currentProcess==NULL){
        self->currentProcess = self->readyQueue->dequeue(self->readyQueue);
        printf("Loading Process: Process ID %d\n", self->currentProcess->id);
    }
    
    self->currentProcess->remaining--;
    self->readyQueue->incrementWaiting(self->readyQueue);
    
    //This process has completed
    if(self->currentProcess->remaining == 0){
        printf("Process Complete!\nProcess ID: %d\n", self->currentProcess->id);
        printf("Scheduler Time: %d\nProcess Burst Time: %d\n", self->time, self->currentProcess->burst);
        printf("Process Arrival Time: %d\nProcess Waiting Time: %d\n", self->currentProcess->arrival, self->currentProcess->waiting);
        self->finishedQueue->enqueueCopy(self->finishedQueue, self->currentProcess);
        free(self->currentProcess);
        self->currentProcess = NULL;
    }
    
    //prempting this process
    //Assuming we don't put the process back on the ready queue if the ready queue is empty
    if (self->time % self->timeQuantum == 0 && self->readyQueue->length != 0) {
        printf("PREEMPTION: Process ID %d\n", self->currentProcess->id);
        
        self->readyQueue->enqueueCopy(self->readyQueue, self->currentProcess);
        free(self->currentProcess);
        self->currentProcess = NULL;
    }
    
    if(self->readyQueue->length == 0 && self->currentProcess == NULL){
        self->complete = 1;
        printf("Scheduler Complete\n");
    }
    
}