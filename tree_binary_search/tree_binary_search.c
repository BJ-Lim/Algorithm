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
void preorder(Tree *tree);
void inorder(Tree *tree);
void postorder(Tree *tree);

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
	case3) root == NULL
		return NULL
 */
Tree* searchBST_b(Tree **root, int key){
	Tree *t = *root;
	Tree *b = NULL;

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

	/*
	 	case) root == NULL
	 */
	if( t == NULL ){
		createBST(root);
		(*root)->key = key;
		return;
	}

	if(t->key == key)		//case) root tree already has the key
		return;

	createBST(&sub);
	sub->key = key;

	if( t->key < key )
		t->right = sub;
	else if( t->key > key )
		t->left = sub;
}

void deleteBST(Tree **root, int key){

}

void print(Tree *tree){
	printf("%3d", tree->key);
}

void preorder_r(Tree *tree){
	if(tree){
		print(tree);
		preorder_r(tree->left);
		preorder_r(tree->right);
	}
}

void preorder(Tree *tree){
	printf("[preorder] : ");
	preorder_r(tree);
	printf("\n");
}

void inorder_r(Tree *tree){
	if(tree){
		inorder_r(tree->left);
		print(tree);
		inorder_r(tree->right);
	}
}

void inorder(Tree *tree){
	printf("[inorder] : ");
	inorder_r(tree);
	printf("\n");
}

void postorder_r(Tree *tree){
	if(tree){
		postorder_r(tree->left);
		postorder_r(tree->right);
		print(tree);
	}
}

void postorder(Tree *tree){
	printf("[postorder] : ");
	postorder_r(tree);
	printf("\n");
}

void postfree_r(Tree *tree){
	if(tree){
		postfree_r(tree->left);
		postfree_r(tree->right);
		free(tree);
	}
}

void postfree(Tree **root){
	postfree_r(*root);
	*root = NULL;
}


