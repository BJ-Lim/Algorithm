#include <stdio.h>
#include "stack.c"

int main(int argc, char *argv[]){
	for(int i =1; i < 102; i++)
		push(i);

	for(int i=1; i < 102; i++){
		printf("%4d", pop());
		if(i % 10 == 0)
			printf("\n");
	}

}
