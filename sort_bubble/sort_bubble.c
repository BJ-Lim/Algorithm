/*
 	example

	i		0	1	2	3	4	5
	arr		5	3	2	4	1	6
 */



void swap(int *a, int *b){
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void sort(int *arr, int size){
	int i, j;
	int temp;

	for(i = size - 1; i > 0 ; i--){
		for(j = 0; j < i; j++){
			if( arr[j] > arr[j+1]){
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}	
		}
	}
}
