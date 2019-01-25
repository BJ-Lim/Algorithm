#include <stdio.h>
#include "sort_select.c"

int main(int argc, char *argv[]){
	int arr[] = {5, 3, 2, 4, 1};

	printf("[before sorting]\n");
	for(int i = 0; i < sizeof(arr) / sizeof(int); i++){
		printf("%3d", arr[i]);
	}

	printf("\n[after sorting]\n");
	sort(arr, sizeof(arr) / sizeof(int));

	for(int i = 0; i < sizeof(arr) / sizeof(int); i++){
		printf("%3d", arr[i]);
	}
	printf("\n");

}
