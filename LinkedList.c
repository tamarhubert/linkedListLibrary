/*
* The linked list library
*
* Created by: Tamar Hubert
*/

#include <stdlib.h>

#include "LinkedList.h"

int lll_add(lll_List *list, lll_Element *newElement){
    if(NULL == list->gateway){
        newElement->next = newElement;
        newElement->previous = newElement;
        list->gateway = newElement;
        list->size = 1;
        return 0;
    }
    newElement->previous = list->gateway->previous;
    list->gateway->previous->next = newElement;

    newElement->next = list->gateway;
    list->gateway->previous = newElement;
    return list->size++;
}

void lll_removeAtIndex(lll_List*, int);
void lll_elementAtIndex(lll_List, int, lll_Element**);
int lll_indexOfElement(lll_List, lll_Element);
int lll_size(lll_List);


// developer tools

int lll_count(lll_List);
int lll_check(lll_List);
