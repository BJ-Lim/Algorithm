#include <stdio.h>
#include "tree_binary_search.c"

/*
 	A shape of tree is like follow.

								60
				40								80
		30				50				70				90
					45		55						85		95
 */

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
