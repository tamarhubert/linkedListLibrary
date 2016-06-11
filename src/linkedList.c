/*
* The linked list library
*
* Created by: Tamar Hubert
*/

#include <stdlib.h>
#include <stdio.h>

#include "linkedList.h"


typedef struct lll_Element lll_Element;
struct lll_List {
	int size;
	lll_Element *gateway;
	tpl_Mutex* mutex;
};
struct lll_Element {
	lll_Element *next;
	lll_Element *previous;
	void* value;
};

lll_List* lll_newList(){
    lll_List *list = malloc(sizeof(lll_List));
    if(NULL == list){
        return NULL;
    }
    list->size = 0;
    list->gateway = NULL;
    list->mutex = tpl_createMutex();
    
    return (lll_List*)list;
}

/*
* frees an empty list.
*/
int lll_freeList(lll_List* list){
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



int lll_add(lll_List *list, void *value){
    if(NULL == list){
        return -1;
    }
    lll_Element *element = malloc(sizeof(lll_Element));
    element->value = value;
    
    tpl_lockMutex(list->mutex);
    if(NULL == list->gateway){
        element->next = element;
        element->previous = element;
        list->gateway = element;
        list->size = 1;
        tpl_unlockMutex(list->mutex);
        return 0;
    }
    element->previous = list->gateway->previous;
    list->gateway->previous->next = element;

    element->next = list->gateway;
    list->gateway->previous = element;
    list->size++;
    tpl_unlockMutex(list->mutex);
    
    return list->size-1;
}

int lll_removeAtIndex(lll_List *list, int index){
    if(NULL == list || NULL == list->gateway){
        return -1;
    }
    if(index >= list->size){
        return -2;
    }

    int i; lll_Element *element = list->gateway;
    if(list->size - index < index){
        for(i = list->size; i > index; i--){
            element = element->previous;
        }
    }else{
        for(i = 0; i < index; i++){
            element = element->next;
        }
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
    
    tpl_unlockMutex(list->mutex);
    
    return 0;
}

int lll_elementAtIndex(lll_List *list, int index, void** value){
    if(NULL == list || NULL == list->gateway || NULL == value){
        return -1;
    }
    
    tpl_lockMutex(list->mutex);
    
    int i; lll_Element *current = list->gateway;
    if(list->size - index < index){
        for(i = list->size; i > index; i--){
            current = current->previous;
        }
    }else{
        for(i = 0; i < index; i++){
            current = current->next;
        }
    }
    
    *value = current->value;
    tpl_unlockMutex(list->mutex);
    return 0;
}

int lll_size(lll_List *list){
    return list->size;
}


// developer tools

int lll_count(lll_List);
int lll_check(lll_List);
int lll_print(lll_List *list){
    tpl_lockMutex(list->mutex);
    printf("list gateway at %p\n", list->gateway);
    printf("list size is %i\n", list->size);
    printf("elements:\n");
    int i; lll_Element *current = list->gateway;
    for(i = 0; i < list->size; i++){
        printf("\t%i: %p, value: %p\n", i, current, current->value);
        current = current->next;
    }
    tpl_unlockMutex(list->mutex);
    return 0;
}
