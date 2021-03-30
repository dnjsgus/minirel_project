/****************************************************************************
              For defining data structures needed for BF layer 
****************************************************************************/

#ifndef BF_DS
#define BF_DS

typedef struct BFpool{
	BFpage *head;
	BFpage *tail;
	size_t entry_num;
} BFpool;

typedef struct Freelist{
	BFpage *head;
	size_t entry_num;
} Freelist;

typedef struct HashTable{
	BFhash_entry **buckets;
	size_t entry_num;
} HashTable;



#endif
