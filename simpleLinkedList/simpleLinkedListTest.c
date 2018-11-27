#include <stdio.h>
#include <stdlib.h>
#include "simpleLinkedList.c"

int main(int argc, char *argv[]){
	Node *head = NULL;

	insertNode(&head, 'B');
	insertNode(&head, 'A');
	insertNode(&head, 'C');
	insertNode(&head, 'E');
	insertNode(&head, 'D');
	printNode(&head);

	printf("===after delete A===\n");
	deleteNode(&head, 'A');
	printNode(&head);

	printf("===after delete E===\n");
	deleteNode(&head, 'E');
	printNode(&head);
	
	printf("===after delete C===\n");
	deleteNode(&head, 'C');
	printNode(&head);

	freeNode(&head);
}
