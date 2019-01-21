#include <stdio.h>
#include "binarySearch.c"

int main(int argc, char *argv[]){
	int a[] = {1,3,5,7,9,11};		//6
	int b[] = {2,4,6,8,10,12,14};	//7

	printf("[test array a]\n");

	for(int i = 1 ; i < 12 ; i++ )
		printf("%2d : %2d\n", i, bin_search(a, i, 0, 5));

	printf("[test array b]\n");

	for(int i = 1 ; i < 15 ; i++ )
		printf("%2d : %2d\n", i, bin_search(b, i, 0, 6));
}
