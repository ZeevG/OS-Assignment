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

//Parses the passed file into a linked list
//This fucntion expects the file to contain a
//"\n" seperated list of doubles

LLNode* parseFile(char* fileName){
    FILE* file;
    int ii;
    double tempDouble;
    LLNode* listHead = NULL;
    
    file = fopen(fileName, "r");
    
    if(file==NULL){
        perror(fileName);
        return listHead;
    }
    
    for(ii=0;fscanf(file, "%lf", &tempDouble)==1;ii++){
        if(ii==0){
            listHead = createNode(tempDouble);
        }else{
            addNode(listHead, tempDouble);
        }
    }

    return listHead;
}