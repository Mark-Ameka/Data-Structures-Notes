#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef int DATA[MAX];
typedef struct{
	int Elem[MAX];
	int lastNdx;
}Heap;

int binarySearch(Heap H, int target){
	int lc, rc, mid;
	lc = 0;
	rc = H.lastNdx;
	mid = (lc + rc)/2;
	while(lc <= rc && target != H.Elem[mid]){
		if(target > H.Elem[mid]){
			lc = mid+1;
		} else{
			rc = mid-1;
		}
		mid = (lc + rc)/2;
	}
	return (lc <= rc) ? 1 : 0;
}

int main(){
	Heap H = {{1, 3, 5, 7, 9, 10}, 6};
	int bs = binarySearch(H, 3);
	printf("%s", bs == 1 ? "Found." : "Not Found");
	return 0;
}
