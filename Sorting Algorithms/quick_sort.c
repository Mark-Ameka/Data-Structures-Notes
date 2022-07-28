/*
	Quick Sort = pivot
	pivote which means central point
	It picks an element as a pivot and partitions the given array around the picked pivot.
	pivot components:
						Correct position in final (sorted array)
						Items to the left are smaller
						Items to the right are larger
	Time Complexity: 
					(Worst Case): O(n2)
	Auxiliary Space: O(1)
*/

/*
*	[] = pivot
*	CONCEPTUAL VIEW:
*	
*	Given an array: Chooses the 6 as the pivot cause 6 is in the middle of the list.
*	4	10	8	7	[6]	5	3	12	14	2
*	
*	With these, move smaller items to the left and right vice versa and select a new pivot.
*	4	5	3	2	[6]	10	8	7	12	14
*	
*	we start from the left. now, 5 is our 'item to the left' pivot
*	compare the left pivot to the items of the left, as it goes:
*	4 [5]	3	2	[6]
*	4	3	2	[5]	[6]
*	
*	afterwards, repeat the process, select new pivot and move smaller items to the left and right vice versa.
*	4	[3]	2	[5]	[6]
*	2	[3]	4	[5]	[6]
*	
*	items to the left are now sorted, do the same thing at the right side of the main pivot which is 6.
*	4 [5]	3	2	[6]	10	8	[7]	12	14				<---- select pivot at the items of the right.
*	4	3	2	[5]	[6]	[7]	10	8	12	14				<---- move smaller items to the left of 7 and right vice versa.
*	4	[3]	2	[5]	[6]	[7] 10	[8]	12	14				<---- 8 is the new pivot
*	2	[3]	4	[5]	[6]	[7]	[8]	[10]	12	14			<---- 10 is the new pivot
*	
*	2	3	4	5	6	7	8	10	12	14				<---- list is now sorted.
*
*	MEMORY VIEW:
*	How to know the pivot? 
*		= If you have a randomly sorted list then something in the middle is likely to be the mid point of the list.
*	
*	Supposed we have an unsorted list. Chooses the 6 as the pivot.
*	10	7	12	[6]	3	2	8
*	
*	move 6 at the end.
*	10	7	12	[6]	3	2	8
*				 ^			^
*				 +----------+
*	10	7	12	8	3	2	[6]
*	
*	now, we have 2 counters, outer loop and inside loop, inside loop compares what the outer loop is pointing.
*	same concept as it goes... (items to the left smaller and items to the right are larger)
*	10	7	12	8	3	2	[6]
*	^	  swap		^
*	+---------------+
*	3	7	12	8	10	12	[6]	
*		
*	Do the same...
*	
*	3	7	12	8	10	2	[6]
*	    ^	  swap		^
*	    +---------------+
*	3	2	12	8	10	7	[6]
*			^			^
*	
*	we are at the last element of the entire array.
*	we swap the outer loop pointer to the main pivot whic is 12 and 6.
*	3	2	[6]	8	10	7	12
*	
*	3 	2	6	8	19	7	12		<---- list is now sorted.
*
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

//partition func
int partition(data arr, int small, int large){
	//pivot will be at the rightmost of the entire array.
	int pivot = arr[large];
	//pointer for greater element
	int pointer = (small-1);
	int i;
	
	for(i = small; i < large; i++){
		//swap i is lesser than the pivot, swap
		if(arr[i] <= pivot){
			pointer++;
			//swap pointer with the i
			swap(&arr[pointer], &arr[i]);
		}
	}
	//swap pointer element is greater than the pivot
	swap(&arr[pointer+1], &arr[large]);
	return pointer+1;
}

//quick sort: ascending
void quick_sort(data arr, int small, int large){
	int divide;
	if(small < large){
		divide = partition(arr, small, large);
		
		//Recusively call quick sort function for left partition
		quick_sort(arr, small, divide-1);
		//Recusively call quick sort function for right partition
		quick_sort(arr, divide+1, large);
	}
}

int main(){
	printf("Quick Sort: ");
	quick_sort(arr, 0, 9);
	display_data(arr, 10);
	return 0;
}
