#include <stdio.h>
#include "polynomial.c"

int main(int argc, char *argv[]){
	POLY *head = NULL;
	POLY *head2 = NULL;

	init_poly(&head);
	print_poly(&head);

	add_term(&head, 3, 4);
	print_poly(&head);

	add_term(&head, 3, 2);
	print_poly(&head);

	add_term(&head, 3, 2);
	print_poly(&head);

	add_term(&head, 3, 6);
	print_poly(&head);

	add_term(&head, 3, 0);
	print_poly(&head);

	printf("------------------------------------\n");

	del_term(&head, 6);
	print_poly(&head);

	del_term(&head, 6);
	print_poly(&head);

	del_term(&head, 4);
	print_poly(&head);

	del_term(&head, 0);
	print_poly(&head);

	del_term(&head, 2);
	print_poly(&head);

	printf("------------------------------------\n");

	add_term(&head, 3, 0);
	print_poly(&head);

	del_term(&head, 0);
	print_poly(&head);

	printf("--------------------del test completed!-------------------\n");

	add_term(&head, 1, 1);
	add_term(&head, 2, 2);
	add_term(&head, 3, 3);

	mult_term(&head, 2, 2);
	print_poly(&head);

	printf("--------------------mult term completed!------------------\n");

	init_poly(&head2);
	add_term(&head2, 1, 1);
	add_term(&head2, 2, 2);
	add_term(&head2, 3, 3);
	printf("[poly1]\n");
	print_poly(&head);
	printf("[poly2]\n");
	print_poly(&head2);
	printf("[poly1 + poly2]\n");
	add_poly(&head, &head2);
	print_poly(&head);

	printf("--------------------add poly completed!------------------\n");

	printf("[poly1]\n");
	print_poly(&head);
	printf("[poly2]\n");
	print_poly(&head2);
	printf("[poly1 * poly2]\n");
	mult_poly(&head, &head2);
	print_poly(&head);

	printf("--------------------mult poly completed!------------------\n");

	free_poly(&head);
	free_poly(&head2);

}
