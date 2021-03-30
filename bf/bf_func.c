/****************************************************************************
               For the actual user function definition
****************************************************************************/

// Standard library import
#include <stdio.h>
#include <stdlib.h>

// Minirel public header file import
#include "minirel.h"
#include "bf.h"

// Header file developed by me
#include "bf_struct.h"
#include "bf_ds.h"

/************************************************
    The global data structures to be maintained 
*************************************************/
BFpool bfpool;
Freelist freelist;
Hashtable hashtable;

/***********************************
     The actual user functions
***********************************/

void BF_Init(void){

}

int BF_GetBuf(BFreq bq, PFpage **fpage){

}

int BF_AllocBuf(BFreq bq, PFpage **fpage){

}

int BF_UnpinBuf(BFreq bq){

}

int BF_TouchBuf(BFreq bq){

}

int BF_FlushBuf(int fd){

}

void BF_ShowBuf(void){

}

void BF_PrintError(const char *s){

}