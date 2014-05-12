//
//  linkedlist.h
//  PDM Assignment
//
//  Created by Ze'ev Gilovitz on 30/03/2014.
//  Copyright (c) 2014 Work. All rights reserved.
//

#ifndef PDM_Assignment_linkedlist_h
#define PDM_Assignment_linkedlist_h

//Linked list node.
//This is a simple linked list
//It doesn't have a struct for
//keeping track of the head/tail

typedef struct Process {
    struct Process* next;
    int arrival;
    int burst;
    int remaining;
    
} Process;



Process* createProcess(int arrival, int burst);
void addProcess(Process** list, Process* newProcess);
void deleteList(Process* node);

#endif
