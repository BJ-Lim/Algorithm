#include <stdio.h>
#include "simpleQueue.c"

int main(int argc, char *argv[]){
	for(int i = 0; i < 101; i++)
		enqueue(i);

	for(int i = 1; i < 102; i++){
		printf("%3d", dequeue());
		if( i % 10 == 0)
			printf("\n");
	}
}
