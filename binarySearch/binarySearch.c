
int bin_search(int *arr, int value, int left, int right){
	int mid = (left + right) / 2;

	if( left > right )
		return -1;

	if ( arr[mid] == value )
		return mid;
	else if( arr[mid] < value )
		return bin_search(arr, value, mid+1, right);
	else if( arr[mid] > value )
		return bin_search(arr, value, left, mid-1);
}
