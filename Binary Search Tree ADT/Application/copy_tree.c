#include "bst_ADT.h"
#include "queue_ADT.h"
#include <stdio.h>
#include <stdlib.h>

BST_TREE* copy_tree( BST_TREE* tree ) {
	BST_TREE* newTree = create_bst();
	QUEUE* queue = creat_queue();

	traverse_inorder( tree->root, queue );
	int* data_ptr = ( int* )dequeue( queue );
	while( data_ptr != NULL ) {
		BST_insert( newTree, &data_ptr );
		data_ptr = ( int* )dequeue( queue );
	}

	return newTree;
}

QUEUE* traverse_inorder( T_NODE* root, QUEUE* queue ) {
	if( root != NULL ) {
		traverse_inorder( root->left, queue );
		enqueue( queue, root->data );
		traverse_postorder( root->right, queue );
	}
	return queue;
}