#include <stdlib.h>

typedef struct tree{
	int key;
	struct tree *left;
	struct tree *right;
}Tree;

void createBST(Tree **root);
Tree* searchBST(Tree **root, int key);
void insertBST(Tree **root, int key);
void deleteBST(Tree **root, int key);

void createBST(Tree **root){
	*root = (Tree*)malloc(sizeof(Tree));
	(*root)->key = -1;
	(*root)->left = NULL;
	(*root)->right = NULL;
}

/*
   	case1) searched target
		return targeted pointer
	case2) didn't search target
		return pointer that has address prior to target
 */
Tree* searchBST_b(Tree **root, int key){
	Tree *t = *root;
	Tree *b = *root;

	while(t){
		b = t;
		
		if( t->key < key )
			t = t->right;
		else if( t->key > key )
			t = t->left;
		else if( t->key == key )
			break;
	}

	return b;
}

/*
 	return targeted pointer
 */
Tree* searchBST(Tree **root, int key){
	Tree *t = searchBST_b(root, key);

	if(t->key == key)
		return t;
	else
		return NULL;
}

void insertBST(Tree **root, int key){
	Tree *sub = NULL;
	Tree *t = searchBST_b(root, key);

	if(t->key == key)		//case) root tree already has the key
		return;

	createBST(&sub);
	sub->key = key;

	if( t->key < key )
		t->right = sub;
	else if( t->key > key )
		t->left = sub;
}
