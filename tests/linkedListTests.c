/*
* The linked list library
*
* Created by: Tamar Hubert
*/

#include <stdio.h>
#include <stdlib.h>

#include "../src/linkedList.h"

int canAddNewElement(void);
int canRemoveElementAtIndex(void);
int canGetElementAtIndex(void);
int canGetIndexOfElement(void);
int canTellSize(void);
void freeList(lll_List*);

int main (void) {
    if(canAddNewElement() == 0){
        printf("lll can add new element.\n");
    }
    if(canRemoveElementAtIndex() == 0){
        printf("lll can remove element at index.\n");
    }
    if(canGetElementAtIndex() == 0){
        printf("lll can get element at index.\n");
    }
    if(canGetIndexOfElement() == 0){
        printf("lll can get index of element.\n");
    }
    if(canTellSize() == 0){
        printf("lll can tell size.\n");
    }
	return 0;
}

int canAddNewElement(void){
    lll_List *list = lll_newList();

    int i;
    for(i = 0; i < 10; i++) {
        int indexOfNewElement = lll_add(list, NULL);

        if(indexOfNewElement != i){
            printf("index of new element should be %i but is %i\n", i, indexOfNewElement);
            freeList(list);
            return -1;
        }
    }
    freeList(list);
    return 0;
}

int canRemoveElementAtIndex(void){
    lll_List *list = lll_newList();

    int i;
    for(i = 0; i < 10; i++) {
        lll_add(list, NULL);
    }

    for(i = 9; i >= 0; i--) {
        lll_removeAtIndex(list, i);
        if(lll_size(list) != i){
            printf("size of list after removal should be %i but is %i", i, lll_size(list));
            freeList(list);
            return -1;
        }
    }

    freeList(list);
    return 0;
}


int canGetElementAtIndex(void){
    lll_List *list = lll_newList();

    int i;
    for(i = 0; i < 10; i++) {
        int *value = malloc(sizeof(int));
        *value = i;
        lll_add(list, value);
    }

    int j;
    for(j = 0; j < 10; j++) {
        void *element = NULL;
        if(lll_elementAtIndex(list, j, &element) != 0){
            printf("could not find element at %i\n", j);
            freeList(list);
            return -1;
        }
        
        if(NULL == element){
            printf("could not get value at %i\n", j);
            freeList(list);
            return -1;
        }

        int value = *(int*)element;
        if(value != j){
            printf("value of element at index %i should be %i but is %i\n", j, j, value);
            freeList(list);
            return -1;
        }
    }
    
    freeList(list);
    return 0;
}

int canGetIndexOfElement(void){
    return -1;
}

int canTellSize(void){
    lll_List *list = lll_newList();

    int i;
    // add some elements to the list
    for(i = 0; i < 10; i++) {
        lll_add(list, NULL);
    }
    
    // remove some elements from the list
    for(i = 0; i < 5; i++){
        lll_removeAtIndex(list, 0);
    }

    if(lll_size(list) != i){
        freeList(list);
        return -1;
    }
    freeList(list);
    return 0;
}

void freeList(lll_List *list){
    // free each element
    int i; int listSize = lll_size(list);
    for(i = 0; i < listSize; i++){
        void* element = NULL;
        lll_elementAtIndex(list, 0, &element);
        if(NULL != element) free(element);
        lll_removeAtIndex(list, 0);
    }
    
    // free the list it-self
    lll_freeList(list);
}
