#include <stdio.h>
#include "linkedQueue.c"

int main(int argc, char *argv[]){
	for( int i = 0; i < 101; i++){
		enqueue(i);
	}

	for( int i = 1; i < 103; i++){
		Node temp = dequeue();

		if(temp.data != -1)
			printf("%3d", temp.data);
		else
			printf("queue is empty!!\n");

		if( i % 10 == 0 )
			printf("\n");
	}
}
