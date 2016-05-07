#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../LinkedList.h"

int canUseEntry();
int canAddEntry();
int canRemoveEntry();
int canCountEntries();

int main (void) {
	int result = 0;
	printf("The linked list library can...\n");
	if( (result = canUseEntry()) == 0 ){
		printf("\tuse entries\n");
	}else{
		printf("\tNOT use entries: %i\n", result);
	}
	if( (result = canAddEntry()) == 0 ){
		printf("\tadd entries\n");
	}else{
		printf("\tNOT add entries: %i\n", result);
	}
	if( (result = canRemoveEntry()) == 0 ){
		printf("\tremove entries\n");
	}else{
		printf("\tNOT remove entries: %i\n", result);
	}
	if( (result = canCountEntries()) == 0 ){
		printf("\tcount entries\n");
	}else{
		printf("\tNOT count entries: %i\n", result+100);
	}

	return 0;	
}

int canUseEntry(){
	lll_Entry *entry = calloc(1, sizeof(lll_Entry));
	int value = 10;	
	entry->value = &value;
	if( value == *(int *)entry->value){
		free(entry);
		return 0;
	}
	free(entry);
	return -1;
}

int canAddEntry(){
	lll_List *list = calloc(1, sizeof(lll_List));
	lll_Entry *entry = calloc(1, sizeof(lll_Entry));
	if(NULL == list || NULL == entry){
		printf("allocation failed");
		return -1;
	}
	if( lll_add(list, entry) == SUCCESS_STATUS ){
		free(list);
		free(entry);
		return 0;
	}
	free(list);
	free(entry);
	return -1;
}

int canRemoveEntry(){
	lll_List *list = calloc(1, sizeof(lll_List));
	lll_Entry *entry = calloc(1, sizeof(lll_Entry));
	if(NULL == list || NULL == entry){
		printf("allocation failed");
		return -1;
	}
	if( lll_add(list, entry) != SUCCESS_STATUS ){
		free(list);
		free(entry);
		return -1;
	}
	if( lll_remove(list, entry) == SUCCESS_STATUS) {
		free(list);
		free(entry);
		return 0;
	}
	free(list);
	free(entry);
	return -1;
}
int canCountEntries(){
	lll_List *list = calloc(1, sizeof(lll_List));
	int count = lll_count(*list);
	if( count != 0 ){
		free(list);
		return count-100;
	}
	lll_Entry *entry = calloc(1, sizeof(lll_Entry));	
	lll_add(list, entry);
	count = lll_count(*list);

	if( count != 1 ){
		free(list);
		free(entry);
		return count-100;
	}
	lll_Entry *entry2 = calloc(1, sizeof(lll_Entry));
	lll_add(list, entry2);
	count = lll_count(*list);
	
    free(list);
	free(entry);
	free(entry2);

	if(count != 2){
		return count-100;	
	}
	return 0;
}
