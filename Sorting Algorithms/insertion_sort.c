/*
	Values from the unsorted part are picked and placed at the correct position in the sorted part.
	Time Complexity: O(N^2)
	Auxiliary Space: O(1)
*/

#include <stdio.h>
#define MAX 10

typedef int data[MAX];
data arr = {5,8,6,22,10,23,1,-99,2,11};

//display data
void display_data(data arr, int size){
	int i;
	for(i = 0; i < size; i++){
		printf("%d ", arr[i]);
	}
	printf("\n\n");
}

//insertion sort: ascending
void insertion_sort(data arr, int size){
	int i, j, temp;
	for(i = 0; i < size; i++){
		temp = arr[i];
		for(j = i-1; temp < arr[j] && j >= 0; j--){
			arr[j+1] = arr[j];
		}
		arr[j+1] = temp;
	}
	display_data(arr, size);	
}

int main(){
	printf("Insertion Sort: ");
	insertion_sort(arr, 10);
	return 0;
}
