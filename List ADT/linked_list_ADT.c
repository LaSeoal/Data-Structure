#include "linked_list_ADT.h"
#include <stdio.h>
#include <stdlib.h>

LLIST* create_list() {
	LLIST* list = ( LLIST* )malloc( sizeof( LLIST ));

	if( list ) {
		list->count = 0;
		list->front = NULL;
		list->rear = NULL;
		list->pos = NULL;

		return list;
	}
	return NULL;
}

bool add_node_at( LLIST* list, unsigned int index, void* data ) {
	if( index > list->count )
		return false;

	LLIST_NODE* new_node = ( LLIST_NODE* )malloc( sizeof( LLIST_NODE ));

	if( !new_node )
		return false;

	new_node->data = data;
	new_node->next = NULL;

	if( list->count == 0 ) {
		list->front = new_node;
		list->rear = new_node;
		( list->count )++;

		return true;
	}

	if( index == 0 ) {
		new_node->next = list->front;
		list->front = new_node;
		( list->count )++;

		return true;
	}

	int iter_i = 1;
	list->pos = list->front;
	while( iter_i != index ) {
		list->pos = list->pos->next;
		iter_i++;
	}
	
	if( iter_i == list->count ) {
		list->pos->next = new_node;
		list->rear = new_node;
		( list->count )++;

		return true;
	} else {
		new_node->next = list->pos->next;
		list->pos->next = new_node;
		( list->count )++;

		return true;
	}

	return false;
}

bool del_node_at( LLIST* list, unsigned int index ) {
	if( list->count == 0 )
		return false;

	if( index >= list->count )
		return false;
	
	if( list->count == 1 ) {
		free( list->front );
		list->front = NULL;
		list->rear = NULL;
		list->count = 0;

		return true;
	}

	int iter_i = 0;
	list->pos = list->front;
	LLIST_NODE* pre = NULL;	

	while( iter_i != index ) {
		pre = list->pos;
		list->pos = list->pos->next;
		iter_i++;
	}

	
	if( index == 0 ) {
		list->front = list->pos->next;
		free( list->pos );
		list->pos = NULL;
		( list->count )--;

		return true;
	}

	if( index == list->count-1 ) {
		pre->next = NULL;
		list->rear = pre;
		free( list->pos );
		list->pos = NULL;
		( list->count )--;

		return true;
	} else {
		pre->next = list->pos->next;
		free( list->pos );
		list->pos = NULL;
		( list->count )--;

		return true;
	}

	return false;
}
