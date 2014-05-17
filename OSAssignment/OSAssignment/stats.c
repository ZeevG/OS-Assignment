//
//  stats.c
//  OSAssignment
//
//  Created by Work on 15/05/2014.
//  Copyright (c) 2014 ZeevG. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "scheduler.h"
#include "processqueue.h"

void doSomeStats(Scheduler* rrSched){
    
    Process* gantt;
    
    int waiting = 0;
    int turnaround = 0;
    int numProcesses = rrSched->finishedQueue->length;
    
    while(rrSched->finishedQueue->length > 0){
        gantt = rrSched->finishedQueue->dequeue(rrSched->finishedQueue);
        waiting += gantt->waiting/numProcesses;
        turnaround += (gantt->waiting + gantt->burst)/numProcesses;
    }
    
    printf("the average turnaround time=%d,", waiting);
    printf("the average waiting time=%d\n", turnaround);
}