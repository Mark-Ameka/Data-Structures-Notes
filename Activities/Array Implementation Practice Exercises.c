/****

	A. Given the definition of a list represented in memory using an array implementation:
	#define MAX  0xF
	typedef struct node {
	   char data[MAX];
	   int ctr;  //actual elements in the array
	}*arrayList;

	B. Function Specifications
	   1) Function initList(). Given a list, the function will prepare the spaces for the elements and will initialize the list to be empty.
	   2) Function changeLetter(): Given a list and 2 characters A and B, as parameters. The function will replace all occurrences of a 
	   		given character A to a given character B. In addition, the function will return to the calling function total number of changes 
			in the function.
	   3) Function insertSorted(). Given a sorted list and a new element,  the function will insert the new element at its 
	   		appropriate position in the given sorted list if the new element does not yet exist in the list.

*****/


#include <stdio.h>
#include <stdlib.h>
#define MAX  0xF
typedef struct node {
   char data[MAX];
   int ctr;  //actual elements in the array
}*arrayList;

void initList(arrayList *L){
	*L = calloc(1, sizeof(struct node));
}

int changeLetter(arrayList L, char A, char B){
	int i, cnt = 0;
	for(i = 0; i < L->ctr; ){
		if(L->data[i] == A){
			L->data[i] = B;
			cnt++;
		} else{
			i++;
		}
	}
	
	return cnt;
}

void insertSorted(arrayList L, int newData){
	int i;
	if(L->ctr < MAX){
		for(i = L->ctr-1; i >= 0 && L->data[i] > newData; i--){
			L->data[i+1] = L->data[i];
		}
		L->data[i+1] = newData;
		L->ctr++;
	}
}

void display(arrayList L){
	int i;
	for(i = 0; i < L->ctr; i++){
		printf("%c ", L->data[i]);
	}
}

int main(){
	arrayList L;
	initList(&L);
	
	insertSorted(L, 'A');
	insertSorted(L, 'Z');
	insertSorted(L, 'C');
	insertSorted(L, 'M');
	insertSorted(L, 'A');
	
	changeLetter(L, 'A', 'O');
	
	display(L);
	
	return 0;
}
