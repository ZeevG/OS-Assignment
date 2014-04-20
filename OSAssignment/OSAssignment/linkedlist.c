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

LLNode* createNode(int arrival, int burst){
    //Mallocs a new LLNode struct and retuns
    //a pointer to the new struct


    LLNode* newNode = (LLNode*)malloc(sizeof(LLNode));
    
    newNode->next = NULL;
    newNode->arrival = arrival;
    newNode->burst = burst;
    newNode->remaining = burst;
    
    return newNode;
}

void addNode(LLNode* node, int arrival, int burst){
    //Loops through the linked list and adds a new
    //node to the end
    //returns void

    LLNode* newNode = (LLNode*)malloc(sizeof(LLNode));
    
    newNode->next = NULL;
    newNode->arrival = arrival;
    newNode->burst = burst;
    newNode->remaining = burst;

    while (node->next!=NULL) {
        node = node->next;
    }
    node->next = newNode;
}

void deleteList(LLNode* node){
    //Loops thorugh the linked list and
    //deletes every node
    //returns void

    LLNode* temp;

    while (node->next!=NULL) {
        temp = node->next;

        free(node);
        node = temp;
    }
    free(node);

}
