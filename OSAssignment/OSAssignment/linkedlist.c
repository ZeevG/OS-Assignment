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

Process* createProcess(int arrival, int burst, int id){
    //Mallocs a new Process struct and retuns
    //a pointer to the new struct


    Process* process = (Process*)malloc(sizeof(Process));
    
    process->next = NULL;
    process->id = id;
    process->arrival = arrival;
    process->burst = burst;
    process->remaining = burst;
    process->waiting = 0;
    
    return process;
}

void addProcessSorted(Process** list, Process* newProcess){
    Process* current;
    
    if(*list == NULL){
        *list = newProcess;
    }else{
        
        current = *list;
        for (current = *list; current != NULL; current = current->next) {
            
            // Append at the end
            if (current->next == NULL){
                current->next = newProcess;
                break;
            }

            //Break if we found a place to insert it.
            if (current->arrival <= newProcess->arrival && current->next->arrival > newProcess->arrival) {
                newProcess->next = current->next;
                current->next = newProcess;
                break;
            }
        }
    }
    
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
