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

typedef struct Node {
    struct Node* next;
    int arrival;
    int burst;
    int remaining;
    
} LLNode;

LLNode* createNode(int arrival, int burst);
void addNode(LLNode* node, int arrival, int burst);
void deleteList(LLNode* node);

#endif
