//
//  linkedlist.c
//  PDM Assignment
//
//  Created by Ze'ev Gilovitz on 30/03/2014.
//  Copyright (c) 2014 Work. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "linkedlist.h"




//Standard linked list functions

Process* createProcess(int arrival, int burst){
    //Mallocs a new Process struct and retuns
    //a pointer to the new struct


    Process* process = (Process*)malloc(sizeof(Process));
    
    process->next = NULL;
    process->arrival = arrival;
    process->burst = burst;
    process->remaining = burst;
    
    return process;
}

void addProcess(Process** list, Process* newProcess){
    //Loops through the linked list and adds a new
    //node to the end
    //returns void
    Process* current;
    
    if(*list == NULL){
        *list = newProcess;
    }else{
        
        current = *list;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newProcess;
    }

}

void deleteList(Process* node){
    //Loops thorugh the linked list and
    //deletes every node
    //returns void

    Process* temp;

    while (node->next!=NULL) {
        temp = node->next;

        free(node);
        node = temp;
    }
    free(node);

}
