/*
	Sorts the elements by first grouping the individual digits of the same place value.
	Disadvantage: like count sort, cannot sort an array with negative values (e.g. -187)
	Time Complexity: 
					k = range
					n = number of elements
					
					(Worst Case)	O(n+k)
					(Average Case)	O(n+k)
					(Best Case)		O(n+k)
	Auxiliary Space: O(max)
*/

/*
	given an element of n = 6
	[25] [125] [522] [362] [1] [231]
	
	supposed we have 10 as max to store. Now, we first sort the least significant of each element.
	how do we get the least significant digit? by the power of modulo we can check each digit from each element.
	= e.g. 2861 % 10 = 286
		   placement value = 1
	
	since we are comparing the last digit, we are placing them in their proper indices.
	[25] [125] [522] [362] [1] [231]
	  ^	    ^     ^     ^   ^     ^
	
	[0]	=> 
	[1]	=> 1    -	231
	[2]	=> 522	-	362
	[3]	=> 
	[4]	=> 
	[5]	=> 25   -	125
	[6]	=> 
	[7]	=> 
	[8]	=> 
	[9]	=> 
	
	after placing them, move to the next digit.
	[1] [231] [522] [362] [25]  [125]
 	^	  ^     ^     ^    ^      ^
	
	[0]	=> 
	[1]	=> 1
	[2]	=> 522	-	25   -   125
	[3]	=> 231
	[4]	=> 
	[5]	=> 
	[6]	=> 362
	[7]	=> 
	[8]	=> 
	[9]	=> 
	
	do the process again.
	
	[1] [522] [25] [125] [231] [362]
 	^	 ^     ^    ^     ^     ^

	[0]	=> 1    -   25			<== why is 1 and 25 in the 0 index? it is because they don't have hundreds place value.
	[1]	=> 125
	[2]	=> 231
	[3]	=> 362
	[4]	=> 
	[5]	=> 522
	[6]	=> 
	[7]	=> 
	[8]	=> 
	[9]	=> 	
	
	after list is sorted, sort it to the output array and copy its content to the original array.
	
	[1] [25] [125] [231] [362] [522]		<== list is sorted
	
*/

#include <stdio.h>
#include <string.h>
#define MAX 10

typedef int data[MAX];
data arr = {121, 432, 237, 2287, 564, 23, 1, 45, 788, 982};

//display data
void display_data(data arr, int size){
	int i;
	for(i = 0; i < size; i++){
		printf("%d ", arr[i]);
	}
}

//function to get the largest element in the arr
int get_max(data arr, int size){
	int max = arr[0];
	while(size != -1){
		if(arr[size] > max){
			max = arr[size];
		}
		size--;
	}
	return max;
}

//using count sort to sort the elements in the basis of significant places.
void count_sort(data arr, int size, int place){
	int output[size+1];
	int max = (arr[0]/place)%10;
	int i;
	for(i = 1; i < size; i++){
		if(arr[i] > max){
			max = arr[i];
		}
	}
	
	int count[max+1];
	memset(count, 0, sizeof(count));
	
	//count of elements
	for(i = 0; i < size; i++){
		count[(arr[i]/place)%10]++;
	}
	//cumulative count
	for(i = 1; i <= max; i++){
		count[i] += count[i-1];
	}
	//place sorted elements in the output array
	for(i = size-1; i >= 0; i--){
		output[count[(arr[i]/place)%10]-1] = arr[i];
		count[(arr[i]/place)%10]--;
	}
	//copy output contents to the arr
	for(i = 0; i < size; i++){
		arr[i] = output[i];
	}

}

//radix sort function implementation
void radix_sort(data arr, int size){
	int max = get_max(arr, size);
	int place;
	//apply count sort to sort elements based on place value
	for(place = 1; max/place > 0; place *= 10){
		count_sort(arr, size, place);
	}
	display_data(arr, size);
}

int main(){
	printf("Radix Sort: ");
	radix_sort(arr, 10);
	return 0;
}
