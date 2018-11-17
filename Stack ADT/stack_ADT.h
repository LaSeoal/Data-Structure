#include <stdbool.h>

// Stack Node
typedef struct node {
	void* data;
	struct node* link;
} STACK_NODE;

// STAcK
typedef struct {
	int count;
	STACK_NODE* top;
} STACK;

// Operations
STACK* create_stack();
bool push( STACK* stack, void* in );
void* pop( STACK* stack );
