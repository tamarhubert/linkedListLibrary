/*
* The linked list library
*
* Created by: Tamar Hubert
*/

#include <stdio.h>
#include <stdlib.h>

#include "../LinkedList.h"

int main (void) {
    if(canAddNewElement() == 0){
        printf("lll can add new element.\n");
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
            return -1;
        }
    }
    return 0;
}
