#include "stack_ADT.h"
#include <stdio.h>
#include <stdlib.h>

STACK* create_stack() {
	STACK* stack = ( STACK* )malloc( sizeof( STACK ) );
	if(stack) {
		stack->count = 0;
		stack->top = NULL;

		return stack;
	}
	return NULL;
}

bool push( STACK* stack, void* in ) {
	STACK_NODE* new_node = ( STACK_NODE* )malloc( sizeof( STACK_NODE* ));

	if(new_node) {	
		new_node->data = in;
		new_node->link = stack->top;
		(stack->count)++;

		return true;
	}
	return false;
}

void* pop( STACK* stack ) {
	if( STACK->count == 0 )
		return NULL;

	STACK_NODE* temp = stack->top;
	void* data_out = stack->top->data;
	stack->top = stack->top->link;
	free(temp);
	(stack->count)--;

	return data_out;
}