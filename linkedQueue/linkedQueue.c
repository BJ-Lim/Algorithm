#ifndef STDLIB_H
#include <stdlib.h>
#endif
#ifndef STRING_H
#include <string.h>
#endif

#define TYPE int


struct node{
	TYPE data;
	struct node *next;
};

typedef struct node Node;

Node * front = NULL;
Node * back = NULL;

void enqueue(TYPE value){
	Node *temp = (Node*)malloc(sizeof(Node));
	temp->data = value;
	temp->next = NULL;

	if( !back ){
		back = temp;
		front = temp;
		return;
	}

	front->next = temp;
	front = temp;
}

Node dequeue(){
	Node t;
	Node *temp;

	if( !back ){
		t.data = -1;	//empty marker can be changed
		return t;
	}

	memcpy(&t, back, sizeof(Node));
	temp = back;
	back = back->next;
	free(temp);

	return t;
}
