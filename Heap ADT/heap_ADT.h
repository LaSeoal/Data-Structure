#include <stdbool.h>

// HEAP
typedef struct {
	int last;		// index of last node (initial: -1)
	int size;		// number of node
	int* array;	// data collection
	int max_size;	// array size is limited
} HEAP;

// Operations
HEAP* create_heap( int max );
void reheapUp( HEAP* heap, int childLoc );
void reheapDown( HEAP* heap, int root );
bool heapInsert( HEAP* heap, int dataPtr );
bool heapDelete( HEAP* heap, int dataOutPtr );