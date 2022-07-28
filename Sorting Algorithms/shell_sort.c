/*
	It first sorts elements that are far apart from each other and 
	successively reduces the interval/gap between the elements to be sorted.
	Replacement for insertion sort, where it takes long time to complete given task.
	Time Complexity: 
					(Worst Case): 	O(n2)
					(Average Case): O(n*logn)
					(Best Case):	O(nlogn)
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

//shell sort: ascending
void shell_sort(data arr, int size){
	int gap, indx, ctr;
	
	for(gap = size/2; gap >= 1; gap/=2){
		for(indx = 0; indx < size; indx++){
			for(ctr = indx; ctr < size; ctr+=gap){
				if(arr[ctr] > arr[ctr+gap] && ctr+gap < size){
					swap(&arr[ctr], &arr[ctr+gap]);
				}
			}
		}
	}
	display_data(arr, size);
}

int main(){
	printf("Shell Sort: ");
	shell_sort(arr, 10);
	return 0;
}
