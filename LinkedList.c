/*
* The linked list library
*
* Created by: Tamar Hubert
*/

#include <stdlib.h>
#include <stdio.h>

#include "LinkedList.h"

int lll_add(lll_List *list, lll_Element *newElement){
    if(NULL == newElement){
        return -1;
    }    
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

void lll_removeAtIndex(lll_List *list, int index);

void lll_elementAtIndex(lll_List list, int index, lll_Element **element){
    if(NULL == list.gateway){
        *element = NULL;
        return;
    }
    lll_Element *current = list.gateway; int i;
    if(list.size - index < index){
        for(i = list.size; i > index; i--){
            current = current->previous;
        }
    }else{
        for(i = 0; i < index; i++){
            current = current->next;
        }
    }
    *element = current;
}
int lll_indexOfElement(lll_List, lll_Element);

int lll_size(lll_List list){
    return list.size;
}


// developer tools

int lll_count(lll_List);
int lll_check(lll_List);
int lll_print(lll_List list){
    printf("list gateway at %p\n", list.gateway);
    printf("list size is %i\n", list.size);
    printf("elements:\n");
    int i; lll_Element *current = list.gateway;
    for(i = 0; i < list.size; i++){
        printf("\t%i: %p, value: %p\n", i, current, current->value);
        current = current->next;
    }
    return 0;
}
