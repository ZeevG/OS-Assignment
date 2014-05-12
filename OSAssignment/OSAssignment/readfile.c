//
//  readfile.c
//  PDM Assignment
//
//  Created by Ze'ev Gilovitz on 30/03/2014.
//  Copyright (c) 2014 Work. All rights reserved.
//

#include <stdio.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "linkedlist.h"
#include "scheduler.h"

//Parses the passed file into a linked list
//This fucntion expects the file to contain a
//"\n" seperated list of doubles

Scheduler* parseFile(char* fileName){
    FILE* file;
    int ii;
    int arrival;
    int burst;
    Scheduler* rrScheduler = NULL;
    
    file = fopen(fileName, "r");
    
    if(file==NULL){
        perror(fileName);
    }
    
    rrScheduler = (Scheduler*)malloc(sizeof(Scheduler));
    rrScheduler->processList = NULL;
    
    fscanf(file, "%d", &rrScheduler->timeQuantum);
        
    for(ii=0;fscanf(file, "%d %d", &arrival, &burst)==2;ii++){
        
        Process* newProcess = createProcess(arrival, burst);
        addProcess(&rrScheduler->processList, newProcess);
    }
    return rrScheduler;
}