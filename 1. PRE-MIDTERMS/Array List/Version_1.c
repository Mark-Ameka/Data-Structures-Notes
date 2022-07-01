#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

typedef struct P{
	char elements[SIZE];
	int count;
}List;

typedef enum {TRUE, FALSE} Boolean;

void initializeList(List *L){
	L->count = 0;
}

//O(N)
void insertFirst(List *L, char newElem){
	int i;
	if(L->count < SIZE){
		for(i = L->count; i > 0; i--){
			L->elements[i] = L->elements[i-1];
		}
		L->elements[i] = newElem;
		L->count++;
	}
}

//O(N)
void insertSort(List *L, char newElem){
	int i;
	if(L->count < SIZE){
		for(i = L->count-1; i >= 0 && L->elements[i] > newElem; i--){
			L->elements[i+1] = L->elements[i];
		}
		L->elements[i+1] = newElem;
		L->count++;
	}
}

//O(N/2)
int locate(List L, char elem){
	int i;
	for(i = 0; i < L.count && elem != L.elements[i]; i++){}
	return i < L.count ? i : -1;
}

//O(1)
char retrieve(List L, int x){
	return x != -1 && x < L.count ? L.elements[x] : '\0';
}

//O(N)
void deleteFirst(List *L){
	int i;
	for(i = 0; i < L->count; i++){
		L->elements[i] = L->elements[i+1];
	}
	L->count--;
}

//O(N)
void displayList(List L){
	int i;
	for(i = 0; i < L.count; i++){
		printf("%c ", L.elements[i]);
	}
}

int main(){
	List L;
	initializeList(&L);
	
	insertFirst(&L, 'F');
	insertFirst(&L, 'E');
	insertFirst(&L, 'B');
	insertFirst(&L, 'A');
	
	displayList(L); printf("\n");
	
	deleteFirst(&L);

	displayList(L); printf("\n");
	
	insertSort(&L, 'C');
	
	displayList(L); printf("\n");
	
	printf("%d = ", locate(L, 'E'));
	printf("%c", retrieve(L, locate(L, 'E')));
	
	return 0;
}


