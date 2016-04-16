// The linked list library

#include <stdio.h>
#include <stdlib.h>

#include "LinkedList.h"

int findFirst(lll_List, lll_Entry**);
int findLast(lll_List, lll_Entry**);
int lll_check(lll_List);

// adds a new entry to an existing list.
int lll_add(lll_List *list, lll_Entry *entry){
	if (list == NULL
		|| entry == NULL
		|| entry->_next != NULL
		|| entry->_previous != NULL
		|| lll_check(*list) < 0){
		return LIST_ERROR;
	}
	lll_Entry *last = NULL;
	findLast(*list, &last);
	if( NULL == last ){
		list->_entry = entry;
	}else {
		last->_next = entry;
		entry->_previous = last;
	}
	return SUCCESS_STATUS;
}

int lll_remove(lll_List* list, lll_Entry* entry){
	if(NULL == list || NULL == entry){
		return LIST_ERROR;
	}
	if(entry->_next != NULL && entry->_previous != entry){
		entry->_next->_previous = entry->_previous;
		if(list->_entry == entry){
			list->_entry = entry->_next;
		}
	} else if( NULL != entry->_next ){		
		entry->_next->_previous = NULL;
	}
	if(entry->_previous != NULL && entry->_next != entry){
		entry->_previous->_next = entry->_next;
		if(list->_entry == entry){
			list->_entry = entry->_next;
		}
	} else if( NULL != entry->_previous ){
		entry->_previous->_next = NULL;
	}

	entry->_next = NULL;
	entry->_previous = NULL;

	return SUCCESS_STATUS;
}

int lll_check(lll_List list){	
	int result;
	lll_Entry *last;
	if( (result = findLast(list, &last)) < 0 ) {
		return result;
	}

	lll_Entry *first;
	if( (result = findFirst(list, &first)) < 0 ) {
		return result;
	}

	return SUCCESS_STATUS;
}


int lll_count(lll_List list){
	if(lll_check(list) < 0){
		printf("%i", lll_check(list));
		return LIST_ERROR;
	}

	lll_Entry *current = NULL;
	findFirst(list, &current);
	int itemCount = 0;
	for(; current != NULL; current = current->_next){
		itemCount++;
	}
	return itemCount;
}

// TODO: Think first, reimplement after.
int findFirst(lll_List list, lll_Entry** first){
	if (list._entry == NULL){
		*first = NULL;
		return SUCCESS_STATUS;
	}
	// loop and hop detection
	lll_Entry *current;
	for(current = list._entry; 
			current != NULL && NULL != current->_next;
			current = current->_next){
		if( current->_next == list._entry ){
			return LOOP_ERROR;
		}
		if( NULL != current->_previous && current->_previous->_next != current ) {
			return HOP_ERROR;
		}
	}
	if( current->_next == list._entry ){
		return LOOP_ERROR;
	}
	if( NULL != current->_previous && current->_previous->_next != current ) {
		return HOP_ERROR;
	}
	*first = current;

	return SUCCESS_STATUS;
}

// TODO: Think first, reimplement after.
int findLast(lll_List list, lll_Entry** last){
	if (list._entry == NULL){
		*last = NULL;
		return SUCCESS_STATUS;
	}
	// loop and hop detection
	lll_Entry *current;
	for(current = list._entry; 
			current != NULL && NULL != current->_next;
			current = current->_previous){
		if( current->_previous == list._entry ){
			return LOOP_ERROR;
		}
		if( NULL != current->_next && current->_next->_previous != current ) {
			return HOP_ERROR;
		}
	}
	if( current->_previous == list._entry ){
		return LOOP_ERROR;
	}
	if( NULL != current->_next && current->_next->_previous != current ) {
		return HOP_ERROR;
	}

	*last = current;

	return SUCCESS_STATUS;
}
// outdated code:
/*

int lll_removeWhere(LinkedList* list, Pattern pattern, LinkedList** resultList){
    int result = NOT_IMPLEMENTED;

    if(list == NULL){
        return LIST_ERROR;
    }

    if(resultList == NULL){
        return LIST_ERROR;
    }

    if( (result = lll_check(list)) BAD ) {
        return result;
    }

    if( (result = gotoFirst(&list)) BAD ) {
        return result;
    }

    for(; list != NULL; list = list->_next){
        result = pattern(*list);
        if(result BAD){
            return result;
        }
        if(result == ENTRY_MATCH){
            LinkedList *entry = list;
            list = list->_previous;
            lll_remove(*entry);
            lll_add(resultList, entry);
        }
    }
    return SUCCESS_STATUS;
}

int lll_findWhere(LinkedList* list, Pattern pattern, LinkedList** resultList){
    int result = NOT_IMPLEMENTED;

    if(list == NULL){
        return LIST_ERROR;
    }

    if(resultList == NULL){
        return LIST_ERROR;
    }

    if( (result = lll_check(list)) BAD ) {
        return result;
    }

    if( (result = gotoFirst(&list)) BAD ) {
        return result;
    }

    for(; list != NULL; list = list->_next){
        result = pattern(*list);
        if(result BAD){
            return result;
        }
        if(result == ENTRY_MATCH){
            // allocating memory for a new list object.
            LinkedList *entry = calloc(1, sizeof(LinkedList));
            entry->value = list->value;
            lll_add(resultList, entry);
        }
    }
    return SUCCESS_STATUS;
}

int lll_foreach(LinkedList* list, Pattern pattern){
    int result = NOT_IMPLEMENTED;

    if(list == NULL){
        return LIST_ERROR;
    }

    if( (result = lll_check(list)) BAD ) {
        return result;
    }

    if( (result = gotoFirst(&list)) BAD ) {
        return result;
    }

    for(; list != NULL; list = list->_next){
        result = pattern(*list);
        if(result BAD){
            return result;
        }
    }
    return SUCCESS_STATUS;
}

int gotoLast(LinkedList **lpp){
	LinkedList *list = *lpp;
	if (list == NULL){
		return LIST_ERROR;
	}
	// loop detection
	LinkedList *startEntry = list;
	for(; list->_next != NULL && list->_next != startEntry; list = list->_next);
	if( list->_next == startEntry ){
		return LOOP_ERROR;
	}
	*lpp = list;
	return SUCCESS_STATUS;
}

int gotoFirst(LinkedList **lpp){
	LinkedList *list = *lpp;
	if (list == NULL){
		return LIST_ERROR;
	}
	// loop detection
	LinkedList *startEntry = list;
	for(; list->_previous != NULL && list->_previous != startEntry; list = list->_previous);
	if( list->_previous == startEntry ){
		return LOOP_ERROR;
	}
	*lpp = list;
	return SUCCESS_STATUS;
}

// default patterns

// where linked list entry value is null
int lll_pattern_whereNull(LinkedList entry){
    if(entry.value == NULL){
        return ENTRY_MATCH;
    }
    return ENTRY_DISMATCH;
}

*/


/*
int lll_add_list(LinkedList* list, LinkedList* list2){
    if (list == NULL){
        return LIST_ERROR;
    }
    if (list2 == NULL){
        return LIST_ERROR;
    }

    int result = NOT_IMPLEMENTED;

    if( (result = lll_check(list)) BAD ){
        return result;
    }

    if( (result = lll_check(list2)) BAD ){
        return result;
    }

    if( (result = gotoLast(&list)) BAD ) {
        return result;
    }

    if( (result = gotoFirst(&list2)) BAD ) {
        return result;
    }

    list->_next = list2;
    list2->_previous = list;

    return lll_check(list);
}

int lll_clean(LinkedList* list){
    int result = NOT_IMPLEMENTED;

    if( (result = lll_check(list)) BAD ) {
        return result;
    }

    if( (result = gotoFirst(&list)) BAD ) {
        return result;
    }
    for(; list != NULL; list = list->_next){
        result = lll_pattern_whereNull(*list);
        if(result BAD){
            return result;
        }
        if(result == ENTRY_MATCH){
            LinkedList *entry = list;
            list = list->_previous;
            lll_remove(*entry);
            free(entry);
        }
    }
    return SUCCESS_STATUS;
}

*/
