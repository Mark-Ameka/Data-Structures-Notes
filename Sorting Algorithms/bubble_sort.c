/*
	Performs swapping of adjacent pairs without the use of any major data structure.
	Time Complexity: O(N^2)
	Auxiliary Space: O(1)
*/

#include <stdio.h>
#define MAX 10

typedef int data[MAX];
data arr = {5,8,6,22,10,23,1,-99,2,11};

void swap(int *x, int *y){
	int temp = *x;
	*x = *y;
	*y = temp;
}

//display data
void display_data(data arr, int size){
	int i;
	for(i = 0; i < size; i++){
		printf("%d ", arr[i]);
	}
}

//bubble sort: ascending
void bubble_sort(data arr, int size){
	int i, j;
	
	for(i = 0; i < size; i++){
		for(j = i; j < size; j++){
			if(arr[i] > arr[j]){
				swap(&arr[i], &arr[j]);
			}
		}
	}
	display_data(arr, size);
}

int main(){
	printf("Bubble Sort: ");
	bubble_sort(arr, 10);
	return 0;
}
