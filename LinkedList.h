// The linked list library

// linked list entry
#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

// define errors
#define FAILED_ERROR -1;
#define LIST_ERROR -2
#define ENTRY_ERROR -3
#define LOOP_ERROR -4
#define CORRUPT_LIST_ERROR -5
#define TEST_FAILED_ERROR -98
#define NOT_IMPLEMENTED -99

// define statuses
#define SUCCESS_STATUS 1
#define ENTRY_MATCH 1
#define ENTRY_DISMATCH 0

typedef struct LinkedListEntry LinkedListEntry;

typedef struct LinkedList LinkedList;

struct lll_List {
	lll_Entry *_entry;
};

struct lll_Entry {
	lll_Entry *_next;
	lll_Entry *_previous;
	void value;
};

typedef int (*Pattern)(lll_Entry);

int lll_add(lll_List*, lll_Entry*);
int lll_remove(lll_List*, lll_Entry*);
int lll_count(lll_List);

//int lll_removeWhere(lll_List*, Pattern, lll_List**);
//int lll_findWhere(lll_List*, Pattern, lll_List**);
//int lll_foreach(lll_List*, Pattern);

#endif /* LINKED_LIST_H_ */
