#include <stdio.h>
#include "fibonacci.c"

int main(int argc, char *argv[]){
	int n = 10;

	printf("fibo(%d) == %d\n", n, fibo(n));
}
