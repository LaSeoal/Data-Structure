#include "AVL_ADT.h"
#include <stdio.h>
#include <stdlib.h>

T_NODE* rotate_left( T_NODE* root ) {
	T_NODE* newRoot;
	newRoot = root->right;
	root->right = newRoot->left;
	newRoot->left = root;

	return newRoot; 
}

T_NODE* rotate_right( T_NODE* root ) {
	T_NODE* newRoot;
	newRoot = root->left;
	root->left = newRoot -> right;
	newRoot->right = root;

	return newRoot;
}