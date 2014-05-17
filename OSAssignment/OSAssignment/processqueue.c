//
//  processqueue.c
//  OSAssignment
//
//  Created by Work on 12/05/2014.
//  Copyright (c) 2014 ZeevG. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedlist.h"
#include "processqueue.h"


void enqueue(ProcessQueue* self, Process* newProcess){
    addProcess(&self->start, newProcess);
    self->length++;
}

void enqueueSortedArrival(ProcessQueue* self, Process* newProcess){
    addProcessSorted(&self->start, newProcess);
    self->length++;
}

void enqueueCopy(ProcessQueue* self, Process* newProcess){
    Process* tempProcess = (Process*)malloc(sizeof(Process));
    memcpy(tempProcess, newProcess, sizeof(Process));
    
    tempProcess->next=NULL;
    
    addProcess(&self->start, tempProcess);
    self->length++;
}

void incrementWaiting(ProcessQueue* self){
    Process* node = NULL;
    
    for (node = self->start; node != NULL; node = node->next) {
        node->waiting++;
    }
}

Process* dequeue(ProcessQueue* self){
    Process* first = self->start;
    
    if(self->length >= 1){
        self->start = self->start->next;
    }else{
        printf("Dequeue called on a empty list");
    }
    
    self->length--;
    
    return first;
}

ProcessQueue * initProcessQueue(){

    ProcessQueue* queue = (ProcessQueue*)malloc(sizeof(ProcessQueue));
    queue->start = NULL;
    queue->length = 0;
    queue->enqueue = enqueue;
    queue->enqueueCopy = enqueueCopy;
    queue->dequeue = dequeue;
    queue->incrementWaiting = incrementWaiting;
    queue->enqueueSortedArrival = enqueueSortedArrival;

    return queue;

}