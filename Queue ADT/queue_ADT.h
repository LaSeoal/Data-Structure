#include <stdbool.h>

// QUEUE Node
typedef struct node {
	void* data;
	struct node* next;
} QUEUE_NODE;

// QUEUE
typedef struct {
	int count;
	QUEUE_NODE* front;
	QUEUE_NODE* rear;
} QUEUE;

// Operations
QUEUE* create_queue();
bool enqueue( QUEUE* queue, void* in );
void* dequeue( QUEUE* queue );