#include "queue_ADT.h"
#include <stdio.h>
#include <stdlib.h>

QUEUE* create_queue() {
	QUEUE* queue = ( QUEUE* )malloc( sizeof( QUEUE ));

	if( queue ) {
		queue->count=0;
		queue->front=NULL;
		queue->rear=NULL;

		return queue;
	}
	return NULL;
}

bool enqueue( QUEUE* queue, void* in ) {
	QUEUE_NODE* new_node = ( QUEUE_NODE* )malloc( sizeof( QUEUE_NODE ));

	if( new_node ) {
		new_node->data = in;
		new_node->next = NULL;

		if( queue->count == 0 )
			queue->front = new_node;
		else
			queue->rear->next = new_node;

		queue->rear = new_node;
		(queue->count)++;

		return true;
	}
	return false;
}

void* dequeue( QUEUE* queue ) {
	if( QUEUE->count == 0 )
		return NULL;

	QUEUE_NODE* deleted_node = queue->front;
	void* data_out = queue->front->data;

	if( queue->count == 1 ) {
		queue->front = NULL;
		queue->rear = NULL;
	} else {
		queue->front = queue->front->next;
	}

	( queue->count )--;
	free( deleted_node );
	
	return data_out;
}