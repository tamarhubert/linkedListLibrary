/*
* The linked list library
*
* Created by: Tamar Hubert
*/

#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

#include "../lib/threadingProcessingLibrary/src/threadingProcessingLibrary.h"

typedef struct lll_List lll_List;

/*
* creates a new list.
*/
lll_List* lll_newList(void);

/*
* frees an empty list.
*/
int lll_freeList(lll_List*);


/*
* adds a new entry to an existing linked list.
* returns the list index of the entry.
*/
int lll_add(lll_List*, void*);

/*
* removes the entry at the index form the list.
*/
int lll_removeAtIndex(lll_List*, int);

/*
* retrives the element of the given index.
*/
int lll_elementAtIndex(lll_List*, int, void**);

/*
* retuns the size of the given list.
*/
int lll_size(lll_List*);



// developer tools

/*
* counts to get the size of the list.
*/
int lll_count(lll_List);

/*
* checks if everything is interger.
*/
int lll_check(lll_List);

/*
* prints each element of the list.
*/
int lll_print(lll_List*);

#endif /* LINKED_LIST_H_ */
