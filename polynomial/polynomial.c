/*
 	Last term always exists as 0 coef.
 */
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
void del_term(POLY **head, int exp);
void mult_term(POLY **head, int coef, int exp);
void add_poly(POLY **head1, POLY **head2);
void mult_poly(POLY **head1, POLY **head2);
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
	if( exp == 0 ){
		c->coef += coef;
		return;
	}
	//end
	c->next = term;
}

void print_poly(POLY **head){
	TERM *c = *head;

	while( c->next ){
		printf("(%d)x^%d + ", c->coef, c->exp);
		c = c->next;
	}
	printf("(%d)x^%d\n", c->coef, c->exp);
}

void del_term(POLY **head, int exp){
	TERM *c = *head;
	TERM *t = NULL;

	//front
	if( max_exp(head) == exp ){
		if( exp == 0 ){
			c->coef = 0;
			return;
		}
		*head = c->next;
		free(c);
		return;
	}

	while( c->next ){
		if( c->next->exp == exp ){
			if( exp == 0 ){
				c->next->coef = 0;
				return;
			}
			t = c->next;
			c->next = c->next->next;
			free(t);
			return;
		}
		c = c->next;
	}
}


void mult_term(POLY **head, int coef, int exp){
	TERM *c = *head;

	TERM *z = (TERM*)malloc(sizeof(TERM));
	z->coef = 0;
	z->exp = 0;
	z->next = NULL;

	while( c->next ){
		c->coef = c->coef * coef;
		c->exp = c->exp + exp;

		c = c->next;
	}

	if( c->exp ){
		c->coef = c->coef * coef;
		c->exp = c->exp + exp;
		c->next = z;
	}
}


void add_poly(POLY **head1, POLY **head2){
	TERM *c = *head2;

	while(c){
		add_term(head1, c->coef, c->exp);
		c = c->next;
	}
}

void copy_poly(POLY **dest, POLY **org){
	TERM *c = *org;
	init_poly(dest);

	while( c ){
		add_term(dest, c->coef, c->exp);
		c = c->next;
	}
}

void mult_poly(POLY **head1, POLY **head2){
	TERM *c = *head2;
	POLY *rs = NULL;	
	POLY *t = NULL;		//It'll have a temporal polynomial

	init_poly(&rs);

	while( c && c->coef ){
		copy_poly(&t, head1);
		mult_term(&t, c->coef, c->exp);
		add_poly(&rs, &t);
		c = c->next;
	}

	copy_poly(head1, &rs);
	free_poly(&rs);
	free_poly(&t);
}
