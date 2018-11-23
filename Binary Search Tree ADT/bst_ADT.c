#include "bst_ADT.h"
#include <stdio.h>
#include <stdlib.h>

BST_TREE* create_bst() {
	BST_TREE* tree = ( BST_TREE* )malloc( sizeof( BST_TREE ));

	if( tree ) {
		tree->count = 0;
		tree->root = NULL;

		return tree;
	}
	return NULL;
}

void traverse_preorder( T_NODE* root ) {
	if( root != NULL ) {
		printf( "%d ", root->data );
		traverse_preorder( root->left );
		traverse_preorder( root->right );
	}
}

void traverse_inorder( T_NODE* root ) {
	if( root != NULL ) {
		traverse_inorder( root->left );
		printf( "%d ", root->data );
		traverse_inorder( root->right );
	}
}

void traverse_postorder( T_NODE* root ) {
	if( root != NULL ) {
		traverse_postorder( root->left );
		traverse_postorder( root->rifht );
		printf( "%d ", root->data );
	}
}

T_NODE* find_smallest_node( T_NODE* root ) {
	if( root->left == NULL )
		return root;
	else find_smallest_node( root->left );
}

T_NODE* find_largest_node( T_NODE* root ) {
	if( root->right == NULL )
		return root;
	else find_largest_node( root->right );
}

T_NODE* search_bst( T_NODE* root, int key ) {
	if( root == NULL )
		return NULL;

	if( key == root->data )
		return root;
	else if( key < root->data )
		search_bst( root->left, key );
	else	search_bst( root->right, key );
}

bool BST_insert( BST_TREE* tree, int data ) {
	T_NODE* newRoot = add_bst( tree->root, data );

	if( newRoot ) {
		tree->root = newRoot;
		( tree->count )++;

		return true;
	}
	return false;
}

bool BST_delete( BST_TREE* tree, int data ) {
	bool success;

	T_NODE* newRoot = ( tree->root, data, &success );

	if( success ) {
		tree->root = newRoot;
		( tree->count )--;
		if( tree->count == 0 )
			tree->root = NULL;
	}
	return success;
}

T_NODE* add_bst( T_NODE* root, int data ) {

	if( root == NULL ) {
		T_NODE* newRoot = ( T_NODE* )malloc( sizeof( T_NODE ));
			
		if( newRoot ) {
			newRoot->left = NULL;
			newRoot->right = NULL;
			newRoot->data = data;

			return newRoot;
		}
		return NULL;
	}
	
	if( data < root->data ) {
		root->left = add_bst( root->left, data );
		return root;
	}
	else { // if( data > root->data )
		root->right = add_bst( root->right, data );
		return root;
	}
}

T_NODE* delete_bst( T_NODE* root, int data, bool* success ) {
	if( root == NULL ) {
		*success = false;
		return NULL;
	}

	if( data < root->data ) {
		root->left = delete_bst( root->left, data, success );	
	}
	else if( data > root->data ) {
		root->right = delete_bst( root->right, data, success );
	}
	else { // matched
		T_NODE* deleted_node = root;

		if( root->left == NULL ) {
			T_NODE* newRoot = root->right;
			free( deleted_node );
			*success = true;
			return newRoot;
		} else {
			if( root->right == NULL ) {
				T_NODE* newRoot = root->left;
				free( deleted_node );
				*success = true;
				return newRoot;
			} else {
				T_NODE* search = root->left;
				while( search->right != NULL )
					search = search->right;
				root->data = search->data;
				root->left = delete_bst( root->left, search->data, success );
			}
		}
	}
	return root;
}
