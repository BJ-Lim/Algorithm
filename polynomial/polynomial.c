#include <stdlib.h>

struct term{
	int coef;		//계수
	int exp;		//지수
	struct term *next;
};

typedef struct term TERM;

void free_poly(TERM **head);
void init_poly(TERM **head);
int max_exp(TERM **head);
void add_term(TERM **head, int coef, int exp);
void del_term(TERM **head, int coef, int exp);
void mult_term(TERM **head, int coef, int exp);
void add_poly(TERM **head1, TERM **head2);
void mult_poly(TERM **head1, TERM **head2);

/*
 	head must be initialized as NULL.
 */
void init_poly(TERM **head){
	TERM *term = (TERM*)malloc(sizeof(TERM));
	term->coef = 0;
	term->exp = 0;
	term->next = NULL;

	if( *head != NULL ){
		free_poly(head);
	}
	*head = term;
}

void free_poly(TERM **head){
	TERM * term;

	while( *head != NULL ){
		term = *head;
		*head = (*head)->next;
		free(term);
	}
}

int max_exp(TERM **head){

}
