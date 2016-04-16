#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../LinkedList.h"

int canUseEntry();
int canAddEntry();
int canRemoveEntry();
int canCountEntries();

int main (void) {
	printf("The linked list library can...\n");
	if( canUseEntry() == 0 ){
		printf("\tuse entries\n");
	}
	if( canAddEntry() == 0 ){
		printf("\tadd entries\n");
	}
	if( canRemoveEntry() == 0 ){
		printf("\tremove entries\n");
	}
	if( canCountEntries() == 0 ){
		printf("\tcount entries\n");
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
		printf("allocation filed");
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
		printf("allocation filed");
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
	lll_Entry *entry = calloc(1, sizeof(lll_Entry));
	if(NULL == list || NULL == entry){
		printf("allocation filed");
		return -1;
	}
	if( lll_add(list, entry) != SUCCESS_STATUS ){
		free(list);
		free(entry);
		return -1;
	}
	if( lll_count(*list) != 1){
		free(list);
		free(entry);
		return -1;
	}
	lll_Entry *entry2 = calloc(1, sizeof(lll_Entry));
	if( lll_add(list, entry2) != SUCCESS_STATUS ){
		free(list);
		free(entry);
		free(entry2);
		return -1;
	}
	if( lll_count(*list) == 2){
		free(list);
		free(entry);
		free(entry2);
		return 0;
	}

	free(list);
	free(entry);
	free(entry2);
	return -1;
}
