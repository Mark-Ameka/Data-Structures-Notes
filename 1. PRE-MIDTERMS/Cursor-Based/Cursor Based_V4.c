#include <stdio.h>
#include <stdlib.h>
#define MAX 10

//Version 4
typedef struct{
	int elem;
	int next;
}NodeType;

typedef struct{
	NodeType *data;		//Dynamic Array
	int avail;
}*VSpace;				//Dynamic Structure

typedef int List;

void initSpace(VSpace *vs){
	int i;
	*vs = calloc(1, sizeof(VSpace));
	(*vs)->data = malloc(sizeof(NodeType)*MAX);
	
	for(i = MAX-1; i >= 0; i--){
		(*vs)->data[i].elem = 0;
		(*vs)->data[i].next = i-1;
	}
	(*vs)->avail = MAX-1;
}

void visualSpace(VSpace vs, List L){
	printf("\n%15s | %15s | %15s", "INDEX", "ELEM", "NEXT");
	int i;
	for(i = 0; i < MAX; i++){
		printf("\n%15d | %15d | %15d", i, vs->data[i].elem, vs->data[i].next);
	}
	printf("\nAvailable: %d\n", vs->avail);
	printf("List: %d\n", L);
}

void insertFirst(VSpace *vs, List *L, int newVal){
	List temp = (*vs)->avail;
	if(temp != -1){
		(*vs)->avail = (*vs)->data[temp].next;
		(*vs)->data[temp].elem = newVal;
		(*vs)->data[temp].next = *L;
		*L = temp;
	}
}

void insertLast(VSpace *vs, List *L, int newVal){
	List temp = (*vs)->avail;
	List *trav;
	
	if((*vs)->avail != -1){
		(*vs)->avail = (*vs)->data[temp].next;
		for(trav = L; *trav != -1; trav = &(*vs)->data[*trav].next){}
		if(temp != -1){
			(*vs)->data[temp].elem = newVal;
			(*vs)->data[temp].next = *trav;
			*trav = temp;
		}
	}
}

void insertSortedUnique(VSpace *vs, List *L, int newVal){
	List temp;
	List *trav;
	
	for(trav = L; *trav != -1 && (*vs)->data[*trav].elem != newVal; trav = &(*vs)->data[*trav].next){}
	if(*trav == -1){
		temp = (*vs)->avail;
		(*vs)->avail = (*vs)->data[temp].next;
		for(trav = L; *trav != -1 && (*vs)->data[*trav].elem < newVal; trav = &(*vs)->data[*trav].next){}
		if(temp != -1){
			(*vs)->data[temp].elem = newVal;
			(*vs)->data[temp].next = *trav;
			*trav = temp;
		}
	}
}

void deleteFirst(VSpace *vs, List *L){
	List temp;
	if(*L != -1){
		temp = *L;
		*L = (*vs)->data[temp].next;
		
		(*vs)->data[temp].elem = 0;
		(*vs)->data[temp].next = (*vs)->avail;
		(*vs)->avail = temp;
	}
}

void deleteLast(VSpace *vs, List *L){
	List temp;
	List *trav;
	
	for(trav = L; *trav != -1 && (*vs)->data[*trav].next != -1; trav = &(*vs)->data[*trav].next){}
	if(*trav != -1){
		temp = *trav;
		*trav = (*vs)->data[temp].next;
		
		(*vs)->data[temp].elem = 0;
		(*vs)->data[temp].next = (*vs)->avail;
		(*vs)->avail = temp;
	}
}

void displayList(VSpace vs, List L){
	printf("{");
		for(; L != -1; L = vs->data[L].next){
			printf("%d ", vs->data[L].elem);
		}
	printf("}");
}

int main(){
	VSpace mySpace;
	List myList = -1;
	
	initSpace(&mySpace);
	visualSpace(mySpace, myList);

	insertFirst(&mySpace, &myList, 200);
	visualSpace(mySpace, myList);
	displayList(mySpace, myList);

	insertFirst(&mySpace, &myList, 700);
	visualSpace(mySpace, myList);
	displayList(mySpace, myList);
	
	insertLast(&mySpace, &myList, 900);
	visualSpace(mySpace, myList);
	displayList(mySpace, myList);
	
	insertSortedUnique(&mySpace, &myList, 1000);
	visualSpace(mySpace, myList);
	displayList(mySpace, myList);
	
	deleteFirst(&mySpace, &myList);
	visualSpace(mySpace, myList);
	displayList(mySpace, myList);
	
	deleteLast(&mySpace, &myList);
	visualSpace(mySpace, myList);
	displayList(mySpace, myList);
	
	return 0;
}
