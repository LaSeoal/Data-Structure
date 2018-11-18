#include <stdbool.h>

// LLIST node
typedef struct node {
	void* data;
	struct node* next;
}LLIST_NODE;

// LLIST
typedef struct {
	int count;
	NODE* front;
	NODE* rear;
	NODE* pos;
}LLIST;

//Operations
LLIST* create_list();
bool add_node_at( LLIST* list, unsigned int index, void* data );
bool del_node_at( LLIST* list, unsigned int index );