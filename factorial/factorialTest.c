#include <stdio.h>
#include "factorial.c"

int main(int argc, char *argv[]){
	for(int i = 0; i < 10; i++){
		for(int j = 1; j < i; j++)
			printf("%d*", j);
		printf("%d = %d\n",i ,fact(i));
	}

}
