//
//  processqueue.h
//  OSAssignment
//
//  Created by Work on 12/05/2014.
//  Copyright (c) 2014 ZeevG. All rights reserved.
//

#ifndef OSAssignment_processqueue_h
#define OSAssignment_processqueue_h

#include "linkedlist.h"

typedef struct ProcessQueue {
    Process* start;
    int length;
    void (* enqueue)();
    void (* enqueueCopy)();
    Process* (* dequeue)();
} ProcessQueue;

void enqueue(ProcessQueue*, Process*);
Process* dequeue(ProcessQueue*);
ProcessQueue * initProcessQueue();
void enqueueCopy(ProcessQueue* self, Process* newProcess);




#endif
