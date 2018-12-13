#ifndef _GRAPH_H_
#define _GRAPH_H_

#include "linked_list_ADT.h"
#include <stdio.h>

// GRAPH
typedef struct {
	LLIST* vertex_list;
} GRAPH;

// VERTEX
typedef struct vertex {
	int data;
	LLIST* arc_list;
} VERTEX;

// ARC
typedef struct arc {
	VERTEX* to_vertex;
} ARC;

GRAPH* create_graph();
bool g_insert_vertex( GRAPH* graph, int data );
int find_vertex( LLIST* list, void* search_data );
bool g_insert_arc( GRAPH* graph, int from, int to );
#endif