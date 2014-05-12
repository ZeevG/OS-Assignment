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
    self->time = 0;
    self->complete = 0;
    self->currentProcess = NULL;
    
    while(self->complete < 3){
        
        
        updateTime(self);
        
//        self->currentProcess = self->readyQueue->dequeue(self->readyQueue);
//        
//        
//        step(self);
        
        self->complete++;
        
        
        
        
    }
}

void updateTime(Scheduler* self){
    self->time++;
    
    for (Process* process = self->processList; process != NULL; process = process->next) {
        if(process->arrival == self->time){
            self->readyQueue->enqueueCopy(self->readyQueue, process);
        }
    }
    
}
void step(Scheduler* self){
    self->currentProcess->remaining--;
}





//void runRRScheduler(Process * ProcessList){
//    Process * unspawnedProcesses;
//    
//    
//    
//}





//Old things

//void printGantt(Scheduler* sched){
//
//    int ii = 0;
//    
//    TimeSlice* gantt = NULL;
//    
//    
//    Process* process = sched->processList;
//    
//    while (process != NULL) {
//        addTimeSlice(gantt, ii, process->burst);
//        process = process->next;
//        ii++;
//    }
//}
//
//void addProcess(Scheduler* sched, int arrival, int burst){
//
//    if(sched->processNumber==0){
//        sched->processList = createNode(arrival, burst);
//    }else{
//        addNode(sched->processList, arrival, burst);
//    }
//    
//    sched->processNumber++;
//
//}
//
//void deleteScheduler(Scheduler* sched){
//    deleteList(sched->processList);
//    free(sched);
//}
//
//void addTimeSlice(TimeSlice* list, int number, int burst){
//    
//    TimeSlice* newTimeSlice = (TimeSlice*)malloc(sizeof(TimeSlice));
//    newTimeSlice->processNumber = number;
//    newTimeSlice->cpuBurst = burst;
//    newTimeSlice->next = NULL;
//    
//    if (list == NULL){
//        list = newTimeSlice;
//
//        printf("things! %d\n", list->processNumber);
//    }else{
//        while (list->next != NULL) {
//            list = list->next;
//        }
//        list->next = newTimeSlice;
//    }
//}
