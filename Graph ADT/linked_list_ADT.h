#ifndef _LLIST_H_
#define _LLIST_H_

#include <stdbool.h>

// LLIST node
typedef struct node {
	void* data;
	struct node* next;
}LLIST_NODE;

// LLIST
typedef struct {
	int count;
	LLIST_NODE* front;
	LLIST_NODE* rear;
	LLIST_NODE* pos;
}LLIST;

//Operations
LLIST* create_list();
bool add_node_at( LLIST* list, unsigned int index, void* data );
bool del_node_at( LLIST* list, unsigned int index );
void* get_data_at( LLIST* list, unsigned int index );

#endif