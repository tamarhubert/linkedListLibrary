/*
* The linked list library
*
* Created by: Tamar Hubert
*/

#include <stdio.h>
#include <stdlib.h>

#include "../LinkedList.h"

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
    lll_List *list = malloc(sizeof(lll_List));
    lll_Element *newElement;

    int i;
    for(i = 0; i < 10; i++) {
        newElement = malloc(sizeof(lll_Element));

        int indexOfNewElement = lll_add(list, newElement);

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
    lll_List *list = malloc(sizeof(lll_List));
    lll_Element *newElement;

    int i;
    for(i = 0; i < 10; i++) {
        newElement = malloc(sizeof(lll_Element));
        lll_add(list, newElement);
    }

    for(i = 9; i >= 0; i--) {
        lll_Element *element = lll_elementAtIndex(*list, i);
        lll_removeAtIndex(list, i);
        free(element);
        if(lll_size(*list) != i){
            printf("size of list after removal should be %i but is %i", i, lll_size(*list));
            freeList(list);
            return -1;
        }
    }

    freeList(list);
    return 0;
}


int canGetElementAtIndex(void){
    lll_List *list = malloc(sizeof(lll_List));
    lll_Element *element;

    int i;
    for(i = 0; i < 10; i++) {
        element = malloc(sizeof(lll_Element));
        int *value = &i;
        element->value = value;
        lll_add(list, element);
    }

    for(i = 0; i < 10; i++) {
        element = lll_elementAtIndex(*list, i);
        if(element == NULL){
            printf("could not find element at %i\n", i);
            freeList(list);
            return -1;
        }
        if(NULL == element->value){
            printf("the elements value is %p\n", element->value);
            freeList(list);
            return -1;
        }
        int value = *(int*)element->value;
        if(value != i){
            printf("value of element at index %i should be %i but is %i\n", i, i, value);
            freeList(list);
            return -1;
        }
    }
    freeList(list);
    return 0;
}

int canGetIndexOfElement(void){
    lll_List *list = malloc(sizeof(lll_List));
    lll_Element *element;

    int i;
    for(i = 0; i < 10; i++) {
        element = malloc(sizeof(lll_Element));
        int *value = &i;
        element->value = value;
        lll_add(list, element);
    }
    for(i = 0; i < 10; i++) {
        element = lll_elementAtIndex(*list, i);
        int indexOfElement = lll_indexOfElement(*list, element);

        if(indexOfElement != i){
            printf("index of element should be %i but is %i\n", i, indexOfElement);
            freeList(list);
            return -1;
        }
    }
    freeList(list);
    return 0;
    
}

int canTellSize(void){
    lll_List *list = malloc(sizeof(lll_List));
    lll_Element *newElement;

    int i;
    // add some elements to the list
    for(i = 0; i < 10; i++) {
        newElement = malloc(sizeof(lll_Element));
        lll_add(list, newElement);
    }
    // remove some elements from the list
    for(i = 0; i < 5; i++){
        lll_Element *element = lll_elementAtIndex(*list, 0);
        lll_removeAtIndex(list, 0);
        free(element);
    }

    if(lll_size(*list) != i){
        freeList(list);
        return -1;
    }
    freeList(list);
    return 0;
}

void freeList(lll_List *list){
    // free each element
    int i; int listSize = lll_size(*list);
    for(i = 0; i < listSize; i++){
        lll_Element *element = 
        	    lll_elementAtIndex(*list, 0);
        lll_removeAtIndex(list, 0);
        free(element);
    }
    // free the list it-self
    free(list);
}
