/*
	Shell sort is mainly a variation of [Insertion Sort].
	
	It first sorts elements that are far apart from each other and 
	successively reduces the interval/gap between the elements to be sorted.
	Replacement for insertion sort, where it takes long time to complete given task.
	Time Complexity: 
					(Worst Case): 	O(n2)
					(Average Case): O(n*logn)
					(Best Case):	O(nlogn)
	Auxiliary Space: O(1)
*/

/*
	Given an array:
	Our gap is size divided by 2 and compare and swap.
	size/2 = 8/2 = 4
	
	9	8	3	7	5	6	4	1
	^		    	^
	+---------------+
	
	swap:
	5	8	3	7	9	6	4	1
	^		    	^
	+---------------+
	
	then do the same process.
	5	8	3	7	9	6	4	1
		^		    	^
		+---------------+
		6				8
			^		        ^
			+---------------+
			3				4
				^		    	^
				+---------------+
				1				7
	
	will be:
	5	6	3	1	9	8	4	7
	
	if gap reaches the end of the array divide the gap by 2 again.
	size/4 = 8/4 = 2
	
	5	6	3	1	9	8	4	7
	^		^
	+-------+
	3		5
		^		^
		+-------+
		1		6
	
	At this point, all the elements in the array lying at the current interval are compared.
	as the gap changes, iteration will also change
	3	1	5	6	9	8	4	7
	
	3	1	5	6	9	8	4	7
		^		^		^
		+-------+-------+
			^		^		^
			+-------+-------+
			4		5		9
		^		^		^		^
		+-------+-------+-------+
		1		6		7		8
	
	again, as the gap changes, iteration will also change
	N/8 = 8/8 =1
	
	3	1	4	6	5	7	9	8
	^	^
	+---+
	1	3
		^	^
		+---+
		3	4
			^	^
			+---+
			4	6
				^	^
				+---+
				5	6
					^	^
					+---+
					6	7
						^	^
						+---+
						7	9
							^	^
							+---+
							9	8
							
	1	3	4	5	6	7	8	9		<---- list is sorted
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
