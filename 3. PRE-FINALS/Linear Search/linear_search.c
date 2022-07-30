#include <stdio.h>
#define MAX 10

typedef int data[MAX];

int linear_search(data arr, int size, int val){
	int i;
	for(i = 0; i < size && arr[i] != val; i++){}
	return i < size ? arr[i] : -1;
}

int main(){
	int ls = linear_search((data){2,17,4,19,10,23,1}, 7, 17);
	printf("%d %s", ls, ls != -1 ? "is found" : "is not found");
	return 0;
}

