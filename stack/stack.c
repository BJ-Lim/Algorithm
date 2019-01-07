/*
 	if you need to include stdlib.h in main file, you must use header guard
 */

#include <stdlib.h>

#define TYPE int
#define STACKSIZE 100

TYPE stack[STACKSIZE];
int top = -1;


void push(TYPE value){
	if(top < STACKSIZE - 1){		//it must be changed
		stack[++top] = value;
	} else {
		printf("stack overflows!\n");
	}
}

TYPE pop(){
	if(top > -1)
		return stack[top--];
	else{
		printf("nothing in stack!\n");
		exit(EXIT_FAILURE);
	}
}
