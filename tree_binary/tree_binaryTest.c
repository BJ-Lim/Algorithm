#include <stdio.h>
#include "tree_binary.c"

/*
 	We'll make a tree like follow.

	level
	0								/
	1					*						D
	2			+				C
	3		A		B
 */

int main(int argc, char *argv[]){
	Tree *root;
	Tree *tmp;

	createBT(&root);
	set_data(root, '/');

	createBT(&tmp);
	set_data(tmp, '*');
	insert_left_BT(root, tmp);

	createBT(&tmp);
	set_data(tmp, '+');
	insert_left_BT(root->left, tmp);

	createBT(&tmp);
	set_data(tmp, 'A');
	insert_left_BT(root->left->left, tmp);

	createBT(&tmp);
	set_data(tmp, 'B');
	insert_right_BT(root->left->left, tmp);

	createBT(&tmp);
	set_data(tmp, 'C');
	insert_right_BT(root->left, tmp);

	createBT(&tmp);
	set_data(tmp, 'D');
	insert_right_BT(root, tmp);

	printf("preorder : ");
	print_preorder(root);

	printf("\ninorder : ");
	print_inorder(root);
	
	printf("\npostorder : ");
	print_postorder(root);

	printf("\n");
}
