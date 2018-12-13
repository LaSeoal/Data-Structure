// AVL node
typedef struct node {
	int data;
	struct node* left;
	struct node* right;
	int balance;
	/*
		#define LH +1
		#define EH 0
		#define RH -1
	*/
} T_NODE;

// AVL
typedef struct {
	int count;
	T_NODE* root;
} AVL_TREE;

// Operations
T_NODE* rotate_left( T_NODE* root );
T_NODE* rotate_right( T_NODE* root );