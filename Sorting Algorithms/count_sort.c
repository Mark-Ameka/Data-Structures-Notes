/*
	Sorts the elements of an array by counting the number of occurrences of each unique element in the array.
	Disadvantage: cannot sort an array with negative values (e.g. -187)
	Time Complexity: 
					k = range
					n = number of elements
					
					(Worst Case)	O(n+k)
					(Average Case)	O(n+k)
					(Best Case)		O(n+k)
	Auxiliary Space: O(max)
*/

/*
	
	given an array of n = 6
	4	9	2	4	7	6
	
	first, determine the largest element. This is because we are storing the count of each element.
	if we have 19 as our max then we should and could store how many 19's at index 19
	but in this case our largest element would be [9].
	
	create a new array for storing counts of each element n of 9 (since 9 is the largest element)
	count size should be max+1
	
	count array:
	 0   1	 2	 3   4   5   6	 7   8	 9		<--- index
	[0]	[0]	[0]	[0]	[0]	[0]	[0]	[0]	[0]	[0]		<--- value
	
	in every iteration, count how many elements are there in the original array to the count array.
	
	count array:
	 0   1	 2	 3   4   5   6   7   8   9		<--- index
	[0]	[0]	[1]	[0]	[2]	[0]	[1]	[1]	[0]	[1]		<--- value
	
	after, sum up index array values with predecessor values.
	
	example:
			[1]   [2]	=>   [1]   [3]
			 ^     ^	            ^
			 +-----+              1+2=3 -> update
	
	count array:
	 0   1	 2	 3   4   5   6   7   8   9		<--- index
	[0]	[0]	[1]	[0]	[2]	[0]	[1]	[1]	[0]	[1]		<--- value
	 ^	 ^                               
	 +---+
	 0   0 
	 	 ^	 ^
		 +---+
		 0   1
		 	 ^	 ^
			 +---+
			 1   1
			     ^	 ^
             	 +---+
             	 1 + 3
               	     ^	 ^
	                 +---+
	                 3 + 3
	                     ^	 ^
                      	 +---+
                      	 3   4
                      	     ^	 ^
	 					     +---+
	 					     4   5
	 	     				     ^	 ^
                             	 +---+
                             	 5   5
                                  	 ^	 ^
                               		 +---+
                               		 5   6
    
	update count array:
	 0   1	 2	 3   4   5   6   7   8   9		<--- index
	[0]	[0]	[1]	[1]	[3]	[3]	[4]	[5]	[5]	[6]		<--- value
	
	create an output array size of the size of the original array
	with this, traverse the original array and map the index to the count array to the output array.
	
	process:	
	
	original array:
	 0   1	 2	 3   4   5 		<--- index
	[4]	[9]	[2]	[4]	[7]	[6]		<--- value
	
	 ^							<--- start of mapping
	 +----------------
	                 +
	                 v 			<--- map element 4 to the index 4
	                 
	 0   1	 2	 3   4   5   6   7   8   9		<--- index 		<= COUNT ARRAY
	[0]	[0]	[1]	[1]	[3]	[3]	[4]	[5]	[5]	[6]		<--- value
	
					 ^			<--- at index 4, element is 3
				 +---+
				 v				<--- map element 3 to the index 3
				 
	 0   1	 2	 3   4   5		<--- index						<= OUTPUT ARRAY:
	[0]	[0]	[0]	[4]	[0]	[0]		<--- value
	
	we need to decrement by 1 after mapping. so in count array at index 4, value decremented by 1 will be 3-1 = 2
	
	updated field and skip process (you get the idea):
	======================================================================================
	
	original array:
	 0   1	 2	 3   4   5 		<--- index
	[4]	[9]	[2]	[4]	[7]	[6]		<--- value
	
	count array: (decremented by 1)
	 0   1	 2	 3   4   5   6   7   8   9		<--- index
	[0]	[0]	[0]	[1]	[2]	[3]	[3]	[4]	[5]	[5]		<--- value
	
	output array:
	 0   1	 2	 3   4   5		<--- index
	[2]	[2]	[4]	[6]	[7]	[9]		<--- value
	
	after storing to the output array, copy all the elements from the output array to the array.
	
	original array:	
	 0   1	 2	 3   4   5		<--- index
	[2]	[2]	[4]	[6]	[7]	[9]		<--- value		<====== list is sorted
*/

#include <stdio.h>
#include <string.h>
#define MAX 10

typedef int data[MAX];
data arr = {4, 2, 8, 7, 1, 2, 8, 3, 3, 1};

//display data
void display_data(data arr, int size){
	int i;
	for(i = 0; i < size; i++){
		printf("%d ", arr[i]);
	}
}

void count_sort(data arr, int size){
	//the output must have the same size as the arr.
	int output[size];
	//declare and initialize max as the arr index 0
	int max = arr[0];
	
	//find the largest element to get the size of count array.
	int i;
	for(i = 1; i < size; i++){
		if(arr[i] > max){
			max = arr[i];
		}
	}
	
	//declare and initialize count with all indices as 0
	int count[max+1];
	//we can also use loop
	memset(count, 0, sizeof(count));
	
	//store to the count array of all counts of each elements
	for(i = 0; i < size; i++){
		count[arr[i]]++;
	}
	//store the cummulative count of each array
	for(i = 1; i <= max; i++){
		count[i] += count[i-1];
	}
	//find the index of each element of the original array in count array, and
  	//place the elements in output array
  	//start at the end so that it's easy to place the elements
	for(i = size-1; i >= 0; i--){
		output[count[arr[i]]-1] = arr[i];
		count[arr[i]]--;
	}
	//copy all the elements from output array to the original array.
	for(i = 0; i < size; i++){
		arr[i] = output[i];
	}
	
	display_data(arr, size);
}

int main(){
	printf("Count Sort: ");
	count_sort(arr, 10);
	return 0;
}
