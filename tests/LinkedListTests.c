/*
* The linked list library
*
* Created by: Tamar Hubert
*/

#include <stdio.h>
#include <stdlib.h>

#include "../LinkedList.h"

int canAddNewElements(void);
int canTellSize(void);
void freeList(lll_List*);

int main (void) {
    if(canAddNewElements() == 0){
        printf("lll can add new element.\n");
    }
    if(canTellSize() == 0){
        printf("lll can tell size.\n");
    }
	return 0;	
}

int canAddNewElements(void){
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
/*
    for(i = 0; i < 5; i++){
        lll_Element *element;
        lll_elementAtIndex(list, 0, element)
        lll_removeAtIndex(list, 0);
        free(element)
    }
*/

    if(lll_size(*list) != i){
        freeList(list);
        return -1;
    }
    freeList(list);
    return 0;
}

void freeList(lll_List *list){
    // free each element
/*    
    int i;
    for(i = 0; i < lll_size(list); i++){
        lll_Element *element;
        lll_elementAtIndex(list, i, element)
        lll_removeAtIndex(list, i);
        free(element);
    }
*/
    // free the list it-self
    free(list);
}
