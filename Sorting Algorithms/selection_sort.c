/*
	Repeatedly finding the min/max element from unsorted part and putting it at the beginning.
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
	printf("\n\n");
}

//selection sort: ascending
void selection_sort(data arr, int size){
	int i, j, min = 0;
	
	for(i = 0; i < size; i++){
		min = i;
		for(j = i; j < size; j++){
			if(arr[j] < arr[min]){
				min = j;
			}
		}
		swap(&arr[i], &arr[min]);
	}
	display_data(arr, size);
}

int main(){
	printf("Selection Sort: ");
	selection_sort(arr, 10);
	return 0;
}
