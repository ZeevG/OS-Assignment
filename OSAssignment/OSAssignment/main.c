//
//  main.c
//  OSAssignment
//
//  Created by Work on 20/04/2014.
//  Copyright (c) 2014 ZeevG. All rights reserved.
//

#include <stdio.h>
#include "readfile.h"
#include "linkedlist.h"
#include "scheduler.h"


int main(int argc, const char * argv[])
{

    Scheduler* rrSched;
    rrSched = parseFile("test.txt");
    
    
    run(rrSched);
    
    doSomeStats(rrSched);


    return  0;

}