#include <stdio.h>
#include <stdlib.h>
#include "circularLinkedList.c"

int main(int argc, char *argv[]){
	Node *head = NULL;

	insertNode(&head, 'B');
	printNode(&head);
	printf("======\n");
	insertNode(&head, 'A');
	printNode(&head);
	printf("======\n");
	insertNode(&head, 'C');
	printNode(&head);
	printf("======\n");
	insertNode(&head, 'E');
	printNode(&head);
	printf("======\n");
	insertNode(&head, 'D');
	printNode(&head);
	printf("======\n");

	printf("===after delete A===\n");
	deleteNode(&head, 'A');
	printNode(&head);

	printf("===after delete E===\n");
	deleteNode(&head, 'E');
	printNode(&head);
	
	printf("===after delete C===\n");
	deleteNode(&head, 'C');
	printNode(&head);

	printf("===after delete B===\n");
	deleteNode(&head, 'B');
	printNode(&head);

	printf("===after delete D===\n");
	deleteNode(&head, 'D');
	printNode(&head);

	freeNode(&head);

}
