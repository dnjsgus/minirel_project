#include "bf_ds.h"

void freelist_insert(Freelist *freelist, BFpage *entry){
	entry->oldpage = freelist->head->oldpage;
	freelist->head->oldpage = entry;
	freelist->entry_num++;
}