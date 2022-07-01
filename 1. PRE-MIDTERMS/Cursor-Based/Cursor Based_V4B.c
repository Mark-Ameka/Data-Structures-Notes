#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 10

//Version 4B
typedef struct{
	int prodID;
	char name[40];
	float price;
	int quantity;
}product;

typedef struct node{
	product elem;
	int next;
}NodeType;

typedef struct{
	NodeType data[MAX]; //Static Array
	int avail;
}*VSpace;				//Dynamic Structure

typedef int List;

void initSpace(VSpace *vs){
	int i;
	*vs = calloc(1, sizeof(struct node));
	
	for(i = MAX-1; i >= 0; i--){
		strcpy((*vs)->data[i].elem.name, "=");
		(*vs)->data[i].next = i-1;
	}
	(*vs)->avail = MAX-1;
}

void visualSpace(VSpace vs, List L){
	printf("\n%15s | %15s | %15s", "INDEX", "ELEM", "NEXT");
	int i;
	for(i = 0; i < MAX; i++){
		printf("\n%15d | %15s | %15d", i, vs->data[i].elem.name, vs->data[i].next);
	}
	printf("\nAvailable: %d\n", vs->avail);
	printf("List: %d\n", L);
}

void insertFirst(VSpace *vs, List *L, product newVal){
	List temp = (*vs)->avail;
	if(temp != -1){
		(*vs)->avail = (*vs)->data[temp].next;
		(*vs)->data[temp].elem = newVal;
		(*vs)->data[temp].next = *L;
		*L = temp;
	}
}

void insertLast(VSpace *vs, List *L, product newVal){
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

void insertSortedUnique(VSpace *vs, List *L, product newVal){
	List temp;
	List *trav;
	
	for(trav = L; *trav != -1 && strcmp((*vs)->data[*trav].elem.name, newVal.name) != 0; trav = &(*vs)->data[*trav].next){}
	if(*trav == -1){
		temp = (*vs)->avail;
		(*vs)->avail = (*vs)->data[temp].next;
		for(trav = L; *trav != -1 && strcmp((*vs)->data[*trav].elem.name, newVal.name) < 0; trav = &(*vs)->data[*trav].next){}
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
		
		strcpy((*vs)->data[temp].elem.name, "=");
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
		
		strcpy((*vs)->data[temp].elem.name, "=");
		(*vs)->data[temp].next = (*vs)->avail;
		(*vs)->avail = temp;
	}
}

void displayList(VSpace vs, List L){
	printf("{");
		for(; L != -1; L = vs->data[L].next){
			printf("%s ", vs->data[L].elem.name);
		}
	printf("}");
}

int main(){
	VSpace mySpace;
	List myList = -1;
	int i;
	
	product prod[MAX] = {{1001, "Fish", 98.23, 90}, {1002, "Meat", 154.92, 10},
					    {1003, "Steak", 293.22, 25}, {1004, "Kimchi", 200.24, 555},
					    {1005, "Butter", 50.23, 445}, {1006, "Shrimp", 353.77, 75},
					    {1007, "Salad", 60.66, 30}, {1008, "Apple", 105.27, 250},
					    {1009, "Banana", 133.52, 205}, {1010, "Hotdogs", 112.32, 295}};
	
	initSpace(&mySpace);
	visualSpace(mySpace, myList);
	displayList(mySpace, myList);
	
	for(i = 0; i < 5; i++) insertFirst(&mySpace, &myList, prod[i]);
	visualSpace(mySpace, myList);
	displayList(mySpace, myList);

	insertLast(&mySpace, &myList, prod[8]);
	visualSpace(mySpace, myList);
	displayList(mySpace, myList);
	
	insertSortedUnique(&mySpace, &myList, prod[9]);
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
