/****************************************************************************
 * Data structures and corrosponding interface definition for the BF layer
 ***************************************************************************/

#ifndef BF_DS
#define BF_DS


/********************************
 * Data sturcture definitions
 ********************************/

// The Buffer pool entry
typedef struct BFpage {
  PFpage         fpage;       /* page data from the file                 */
  struct BFpage  *newpage;    /* buffer page that was accessed right after then this page */
  struct BFpage  *oldpage;    /* buffer page that was accessed right before then this page  */
  bool_t         dirty;       /* TRUE if page is dirty                   */
  short          count;       /* pin count associated with the page      */
  int            pageNum;     /* page number of this page                */
  int            fd;          /* PF file descriptor of this page         */
  int            unixfd;      /* Unix file descriptor of this page       */
} BFpage;

// The hash table entry
typedef struct BFhash_entry {
  struct BFhash_entry *nextentry;     /* next hash table element or NULL */
  struct BFhash_entry *preventry;     /* prev hash table element or NULL */
  int fd;                             /* file descriptor                 */
  int pageNum;                        /* page number                     */
  struct BFpage *bpage;               /* ptr to buffer holding this page */
} BFhash_entry;

// The Buffer pool
typedef struct BFpool{
	BFpage *mru_end; // the MRU end
	BFpage *lru_end; // the LRU end
	size_t entry_num;
} BFpool;

// The free list of buffer pool entries
typedef struct Freelist{
	BFpage *head;
	size_t entry_num;
} Freelist;

// The hash table
typedef struct HashTable{
	BFhash_entry **buckets;
	size_t entry_num;
} HashTable;


/*****************************
 * DS Interface definitions
 ****************************/

void freelist_insert(Freelist *freelist, BFpage *entry);

#endif
