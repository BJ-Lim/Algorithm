#include <stdio.h>
#include "tree_binary_search.c"

int main(int argc, char *argv[]){
	Tree *root = NULL;

	insertBST(&root, 60);
	insertBST(&root, 40);
	insertBST(&root, 80);
	insertBST(&root, 30);
	insertBST(&root, 50);
	insertBST(&root, 70);
	insertBST(&root, 90);
	insertBST(&root, 45);
	insertBST(&root, 55);
	insertBST(&root, 85);
	insertBST(&root, 95);


	preorder(root);
	inorder(root);
	postorder(root);

	postfree(&root);
	postorder(root);

}
