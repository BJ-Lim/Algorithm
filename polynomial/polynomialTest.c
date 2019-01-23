#include <stdio.h>
#include "polynomial.c"

int main(int argc, char *argv[]){
	POLY *head = NULL;

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

	free_poly(&head);

}
