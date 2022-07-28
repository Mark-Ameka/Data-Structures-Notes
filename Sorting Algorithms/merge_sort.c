/*
	Divide and Conquer (Done Recursively)
	Time Complexity: O(nlogn)
	Auxiliary Space: O(n)
*/

#include <stdio.h>
#define MAX 10

typedef int data[MAX];
data arr = {5,8,6,22,10,23,1,-99,2,11};

/*
	| = division
	given an array of n = 8;
	2	8	5	3	9	4	1	7
	
	We divide the array by 2 
	=	[2	8	5	3]	|	[9	4	1	7]
	
	=	[2	8]	|	[5	3]	|	[9	4]	|	[1	7]
	
	=	[2] | [8] |	[5]	| [3] |	[9]	| [4] |	[1]	| [7]
	
	now, if the subarrays done dividing, sort all elements.
	
	=	[2	8]	|	[3	5]	|	[4	9]	|	[1	7]
	
	=	[2	3	5	8]	|	[1	4	7	9]
	
	=	[1	2	3	4	5	7	8	9]			<--- list is sorted
	
*/

//display data
void display_data(data arr, int size){
	int i;
	for(i = 0; i < size; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
}

/*	merge sort: ascending
	Merges two subarrays of arr[].
	First subarray is arr[left...mid]
	Second subarray is arr[(mid+1)...right]
*/
void merge_func(data arr, int left, int mid, int right){
	int i, j, sort_ctr;
	int left_size = (mid-left)+1;
	int right_size = right-mid;
	
	//Declaration of L[] and R[]
	int L[left_size], R[right_size];
	
	//Copy data to temporary arrays
	for(i = 0; i < left_size; i++){
		L[i] = arr[left+i];
	}
	for(i = 0; i < right_size; i++){
		R[i] = arr[(mid+1)+i];
	}

	sort_ctr = left;
	
	//Merge the temporary arrays back into the arr[left...right]
	for(i = j = 0; i < left_size && j < right_size; ){
		if(L[i] <= R[j]){
			arr[sort_ctr] = L[i++];
		} else{
			arr[sort_ctr] = R[j++];
		}
		sort_ctr++;
	}
	
	//If L[] is not empty copy remaining.
	while(i < left_size){
		arr[sort_ctr++] = L[i++];
	}
	//If R[] is not empty copy remaining.
	while(j < right_size){
		arr[sort_ctr++] = R[j++];
	}
}

void merge_sort(data arr, int left, int right, int size){
	int mid;
	if(left < right){
		//supposed we have max as 10
		// 0 + (9 - 0) / 2 = 4.5 or 5 (round up)
		mid = left+(right-left)/2;
		
		merge_sort(arr, left, mid, size);
		merge_sort(arr, mid+1, right, size);
		
		merge_func(arr, left, mid, right);
	}
}

int main(){
	printf("Merge Sort: ");
	merge_sort(arr, 0, 9, 10);
	display_data(arr, 10);
	return 0;
}
