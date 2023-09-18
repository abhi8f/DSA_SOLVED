/*
	The function is called with the parameters:
	quickSort(input, 0, size - 1);

*/

int partitionArray(int input[], int start, int end) {
	int i=start, j=end;
	while(i<=j){
		while(i<=j && input[start]>=input[i]) i++;
		while(i<=j && input[start]<=input[j]) j--;
		if (i<=j) swap(input[i],input[j]);
	}
	swap(input[start], input[j]);
	return j;
}

void quickSort(int input[], int start, int end) {
	if (start>=end) return; 
	int mid=partitionArray(input, start, end);
	quickSort(input, start, mid-1);
	quickSort(input, mid+1, end);
}