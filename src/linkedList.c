/*
* The linked list library
*
* Created by: Tamar Hubert
*/

#include <stdlib.h>
#include <stdio.h>

#include "linkedList.h"

LL_LIST* lll_newList(){
    LLL_List *list = (ll_List)malloc(sizeof(ll_List));
    if(NULL == list){
        return NULL;
    }
    list->size = 0;
    list->gateway = NULL;
    list->mutx = tpl_createMutex();
    
    return list;
}

/*
* frees an empty list.
*/
int lll_freeList(LLL_LIST* list){
    void* mutex = list->mutex;
    tpl_lockMutex(mutex);
    if(list->size != 0){
        return -1;
    }
    free(list);
    tpl_unlockMutex(mutex);
    tpl_freeMutex(mutex);
    return 0;    
}



int lll_add(LLL_LIST *list, lll_Element *newElement){
    if(NULL == list || NULL == newElement){
        return -1;
    }
    tpl_lockMutex(list->mutex);
    if(NULL == list->gateway){
        newElement->next = newElement;
        newElement->previous = newElement;
        list->gateway = newElement;
        list->size = 1;
        tpl_unlockMutex(list->mutex);
        return 0;
    }
    newElement->previous = list->gateway->previous;
    list->gateway->previous->next = newElement;

    newElement->next = list->gateway;
    list->gateway->previous = newElement;
    list->size++;
    tpl_unlockMutex(list->mutex);
    
    return list->size;
}

int lll_removeAtIndex(LLL_LIST *list, int index){
    if(NULL == list){
        return -1;
    }
    if(index >= list->size){
        return -2;
    }

    lll_Element *element = lll_elementAtIndex(*list, index);
    if(NULL == element){
        return -3;
    }
    tpl_lockMutex(list->mutex);

    if(element == list->gateway){
        list->gateway = element->next;
    }
    if(element == list->gateway){
        list->gateway = NULL;
    }

    element->next->previous = element->previous;
    element->previous->next = element->next;

 	element->next = NULL;
 	element->previous = NULL;

    free(element);

    list->size--;
    
    tpl_unlock(list->mutex);
    
    return 0;
}

lll_Element* lll_elementAtIndex(LLL_LIST list, int index){
    if(NULL == list.gateway){
        return NULL;
    }
    
    tpl_lockMutex(list.mutex);
    
    int i; lll_Element *current = list.gateway;
    if(list.size - index < index){
        for(i = list.size; i > index; i--){
            current = current->previous;
        }
    }else{
        for(i = 0; i < index; i++){
            current = current->next;
        }
    }
    
    tpl_unlockMutex(list.mutex);
    return current;
}
int lll_indexOfElement(lll_List list, lll_Element *element){

    tpl_lockMutex(list.mutex);

    int i; lll_Element *current = list.gateway;
    for(i = 0; i < list.size; i++){
        if(current == element){
            tpl_unlockMutex(list.mutex);
            return i;
        }
        current = current->next;
    }
    
    tpl_unlockMutex(list.mutex);
    
    return -1;
}

int lll_size(lll_List list){
    return list.size;
}


// developer tools

int lll_count(lll_List);
int lll_check(lll_List);
int lll_print(lll_List list){
    tpl_lockMutex(list.mutex);
    printf("list gateway at %p\n", list.gateway);
    printf("list size is %i\n", list.size);
    printf("elements:\n");
    int i; lll_Element *current = list.gateway;
    for(i = 0; i < list.size; i++){
        printf("\t%i: %p, value: %p\n", i, current, current->value);
        current = current->next;
    }
    tpl_unlockMutex(list.mutex);
    return 0;
}
