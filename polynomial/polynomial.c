#include <stdlib.h>

struct term{
	int coef;		//계수
	int exp;		//지수
	struct term *next;
};

typedef struct term TERM;
typedef struct term POLY;


void free_poly(POLY **head);						//ok
void init_poly(POLY **head);						//ok
int max_exp(POLY **head);							//ok
void add_term(POLY **head, int coef, int exp);		//ok
void del_term(POLY **head, int coef, int exp);
void mult_term(POLY **head, int coef, int exp);
void add_poly(POLY **head1, TERM **head2);
void mult_poly(POLY **head1, TERM **head2);
void print_poly(POLY **head);						//ok

/*
 	head must be initialized as NULL.
 */
void init_poly(POLY **head){
	TERM *term = (TERM*)malloc(sizeof(TERM));
	term->coef = 0;
	term->exp = 0;
	term->next = NULL;

	free_poly(head);
	*head = term;
}

void free_poly(POLY **head){
	TERM * term;

	while( *head != NULL ){
		term = *head;
		*head = (*head)->next;
		free(term);
	}
}

int max_exp(POLY **head){
	return (*head)->exp;
}

void add_term(POLY **head, int coef, int exp){
	TERM *c = *head;
	TERM *term = (TERM*)malloc(sizeof(TERM));
	term->coef = coef;
	term->exp = exp;
	term->next = NULL;

	//front
	if( max_exp(head) < exp ){
		term->next = c;
		*head = term;
		return;
	}

	//mid
	while( c->next ){
		if( c->exp == exp ){
			c->coef += coef;
			return;
		}
		if( c->next->exp < exp ){
			term->next = c->next;
			c->next = term;
			return;
		}
		c = c->next;
	}
	//end
	c->next = term;
}

void print_poly(POLY **head){
	TERM *c = *head;

	while( c->next ){
		printf("(%d)^%d + ", c->coef, c->exp);
		c = c->next;
	}
	printf("(%d)^%d\n", c->coef, c->exp);
}
