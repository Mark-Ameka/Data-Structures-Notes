#include <stdio.h>
#define MAX 10

typedef int Type;
typedef int Position;
typedef int List;

//Linked List Concept
typedef struct{
	Type elem;
	Position next;
}NodeType;

//Array List Concept
typedef struct{
	NodeType data[MAX];
	Position avail;
}VSpace;

//Initialize Heap O(N)
void initHeap(VSpace *vs){
	int i;
	
//	Version 1
/*
	for(i = 0; i < MAX-1; i++){
		vs->data[i].elem = 0;
		vs->data[i].next = i+1;
	}
	vs->data[i].elem = 0;
	vs->data[i].next = -1;
	vs->avail = 0;
*/

//	Version 2
	for(i = MAX-1; i >= 0; i--){
		vs->data[i].elem = 0;
		vs->data[i].next = i-1;
	}
	vs->avail = MAX-1;

}

//View Virtual Space
void visualSpace(VSpace vs){
	printf("\n%15s | %15s | %15s", "INDEX", "ELEM", "NEXT");
	int i;
	for(i = 0; i < MAX; i++){
		printf("\n%15d | %15d | %15d", i, vs.data[i].elem, vs.data[i].next);
	}
	printf("\nAvailable: %d\n", vs.avail);
}

//Allocate Space
Position allocSpace(VSpace *vs){
	Position avail = vs->avail;
	
	if(avail != -1){
		vs->avail = vs->data[avail].next;
	}

	return avail;
}

//Free Space
void freeSpace(VSpace *vs, Position index){
	if(index != -1 && index < MAX){
		vs->data[index].elem = 0;
		vs->data[index].next = vs->avail;
		vs->avail = index;
	}
}

void insertFront(VSpace *vs, List *head, Type item){
	Position temp = allocSpace(vs);

	if(temp != -1){
		vs->data[temp].elem = item;
		vs->data[temp].next = *head;
		*head = temp;
	}
}

void insertLast(VSpace *vs, List *head, Type item){
	int *trav = head;
	int temp = allocSpace(vs);
	
	if(temp != -1){
		for(; *trav != -1; trav = &vs->data[*trav].next);
		vs->data[temp].elem = item;
		vs->data[temp].next = *trav;
		*trav = temp;
	}
}

void deleteFront(VSpace *vs, List *head){
	Position temp;
	if(*head != -1){
		temp = *head;
		*head = vs->data[temp].next;
		freeSpace(vs, temp);
	}
}

void deleteRear(VSpace *vs, List *head){
	Position *trav = head;
	Position temp;
	
	for(; *trav != -1 && vs->data[*trav].next != -1; trav = &vs->data[*trav].next){}
	if(*trav != -1){
		temp = *trav;
		*trav = vs->data[temp].next;
		freeSpace(vs, temp);
	}
}

void displayList(VSpace vs, List head){
	int trav;
	printf("{");
		for(trav = head; trav != -1; trav = vs.data[trav].next){
			printf("%d ", vs.data[trav].elem);
		}
	printf("}");
}

int main(){
	List myList = -1;
	VSpace mySpace;
	initHeap(&mySpace);
	
	//View Empty Heap
	printf("\n=============== VIEW EMPTY: ===============\n");
	visualSpace(mySpace);
	displayList(mySpace, myList);
	
	//Insert Front: 200
	printf("\nmyList: %d", myList);
	printf("\n=============== INSERTION FRONT: 200 ===============\n");
	insertFront(&mySpace, &myList, 200);
	visualSpace(mySpace);
	displayList(mySpace, myList);
	
	//Insert Front: 100
	printf("\nmyList: %d", myList);
	printf("\n=============== INSERTION FONT: 100 ===============\n");
	insertFront(&mySpace, &myList, 100);
	visualSpace(mySpace);
	displayList(mySpace, myList);

	//Insert Front: 500
	printf("\nmyList: %d", myList);
	printf("\n=============== INSERTION FRONT: 500 ===============\n");
	insertFront(&mySpace, &myList, 500);
	visualSpace(mySpace);
	displayList(mySpace, myList);
	
	//Delete Front
	printf("\nmyList: %d", myList);
	printf("\n=============== DELETION FRONT: ===============\n");
	deleteFront(&mySpace, &myList);
	visualSpace(mySpace);
	displayList(mySpace, myList);
	
	//Insert Last: 900
	printf("\nmyList: %d", myList);
	printf("\n=============== INSERTION LAST: 900 ===============\n");
	insertLast(&mySpace, &myList, 900);
	visualSpace(mySpace);
	displayList(mySpace, myList);
	
	//Delete Last
	printf("\nmyList: %d", myList);
	printf("\n=============== DELETION LAST: ===============\n");
	deleteRear(&mySpace, &myList);
	visualSpace(mySpace);
	displayList(mySpace, myList);

	return 0;
}
