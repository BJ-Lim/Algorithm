
void swap(int *a, int *b){
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void sort(int *arr, int size){
	for(int i = 0; i < size; i++){
		int min_index = i;
		for(int j = i; j < size; j++){
			if( arr[j] < arr[min_index] )
				min_index = j;
		}
		swap(arr+i, arr+min_index);
	}
}
