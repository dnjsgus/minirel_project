/****************************************************************************
 * The interface definition for the BF layer.
 ***************************************************************************/

// Standard library import
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>  // For debugging purpose. 

// Minirel public header file import
#include "minirel.h"
#include "bf.h"

// Header file developed by me
#include "bf_ds.h"

/************************************************
    The global data structures to be maintained 
*************************************************/
BFpool *bfpool;
Freelist *freelist;
Hashtable *hashtable;



/***********************************
     The actual user functions
***********************************/

/************************************************** 
 * 1. BF_Init
 *    void input, void output.
 *    Initialize the BF layer by 
 *      - Initialize bfpool, freelist, hashtable
 *      - creating all buffer entries
 *      - add them to the free list
 **************************************************/
void BF_Init(void){

	// The buffer pool initialization
	// All elements would be inserted as the head's oldpage
	bfpool = malloc(sizeof(BFpool));  assert(bfpool);
	bfpool->mru_end->newpage = NULL;
	bfpool->mru_end->oldpage = bfpool->lru_end;
	bfpool->lru_end->newpage = bfpool->mru_end;
	bfpool->lru_end->oldpage = NULL;
	bfpool->entry_num = 0;

	// The free list initialization
	// All elements would be inserted as the head's oldpage
	freelist = malloc(sizeof(Freelist));  assert(freelist);
	freelist->head->newpage = NULL;
	freelist->head->oldpage = NULL;
	freelist->entry_num = 0;

	// The hash table initialization
	// Preventry of each bucket is always NULL.
	// All hash entries would be inserted as the each bucket's nextentry.
	hashtable = malloc(sizeof(Hashtable));  assert(hashtable);
	hashtable->buckets = malloc(BF_HASH_TBL_SIZE * sizeof(BFhash_entry *)); assert(hashtable->buckets);
	for(int i=0; i < BF_HASH_TBL_SIZE; i++){
		hashtable->buckets[i]->preventry = NULL;
		hashtable->buckets[i]->nextentry = NULL;
	}
	hashtable->entry_num = 0;

	// Filling out the freelist with buffer entries.
	BFpage *entry; 
	for(int i=0; i < BF_MAX_BUFS; i++){
		entry = malloc(sizeof(BFpage)); assert(entry);
		freelist_insert(freelist, entry);
	}
}

/************************************************** 
 * 2. BF_GetBuf
 *    Takes BFreq ba, PFpage **fpage as input, and returns int.
 * 

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