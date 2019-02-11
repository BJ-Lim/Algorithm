#include <stdlib.h>

typedef struct tree{
	char data;
	struct tree *left;
	struct tree *right;
}Tree;

#ifndef TYPE
#define TYPE char
#endif

void createBT(Tree **root);
void set_data(Tree *tree, TYPE data);
void insert_left_BT(Tree *tree, Tree *sub);
void insert_right_BT(Tree *tree, Tree *sub);
void freeBT(Tree **root);
void print_preorder(Tree *tree);
void print_inorder(Tree *tree);
void print_postorder(Tree *tree);

void createBT(Tree **root){
	*root = (Tree*)malloc(sizeof(Tree));
	(*root)->left = NULL;
	(*root)->right = NULL;
}

void set_data(Tree *tree, TYPE data){
	tree->data = data;
}

void insert_left_BT(Tree *tree, Tree *sub){
	tree->left = sub;
}

void insert_right_BT(Tree *tree, Tree *sub){
	tree->right = sub;
}

//This function will be used in this file only.
void free_postorder(Tree *tree){
	if(tree){
		free_postorder(tree->left);
		free_postorder(tree->right);
		free(tree);
	}
}

void freeBT(Tree **root){
	free_postorder(*root);
	*root = NULL;
}

void print(TYPE data){
	printf("%c ", data);
}

void print_preorder(Tree *tree){
	if(tree){
		print(tree->data);
		print_preorder(tree->left);
		print_preorder(tree->right);
	}
}

void print_inorder(Tree *tree){
	if(tree){
		print_inorder(tree->left);
		print(tree->data);
		print_inorder(tree->right);
	}
}

void print_postorder(Tree *tree){
	if(tree){
		print_postorder(tree->left);
		print_postorder(tree->right);
		print(tree->data);
	}
}	
