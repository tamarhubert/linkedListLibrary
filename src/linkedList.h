/*
* The linked list library
*
* Created by: Tamar Hubert
*/

#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

#include "../lib/threadingProcessingLibrary/src/threadingProcessingLibrary.h"


typedef void* LLL_LIST;

typedef struct lll_Element lll_Element;

typedef struct lll_List lll_List;

struct lll_List {
	int size;
	lll_Element *gateway;
	void* mutex;
};

struct lll_Element {
	lll_Element *next;
	lll_Element *previous;
	void* value;
};

/*
* creates a new list.
*/
LL_LIST* lll_newList();

/*
* frees an empty list.
*/
int lll_freeList(LL_LIST*);


/*
* adds a new entry to an existing linked list.
* returns the list index of the entry.
*/
int lll_add(lll_LIST*, lll_Element*);

/*
* removes the entry at the index form the list.
*/
int lll_removeAtIndex(lll_List*, int);

/*
* retrives the element of the given index.
*/
lll_Element* lll_elementAtIndex(lll_List, int);

/*
* returns the index the specivied element
*/
int lll_indexOfElement(lll_List, lll_Element*);

/*
* retuns the size of the given list.
*/
int lll_size(lll_List);



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
int lll_print(lll_List);

#endif /* LINKED_LIST_H_ */
