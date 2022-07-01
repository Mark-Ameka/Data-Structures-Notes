#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

typedef struct P{
	char *elem;
	int count;
}*List;

int initList(List *L){
	*L = (List) calloc(1, sizeof(struct P)); //allocate the struct
	if(*L != NULL){ 
		(*L)->elem = (char*) malloc(sizeof(char)*SIZE); //allocate the array
		if(*L == NULL){ //if the structure failed tot allocate then free *L and make it NULL
			free(*L);
			*L = NULL;
		}
	}
	return (*L != NULL) ? 1 : 0;
}

void insertFirst(List *L, char newElem){
	int i;
	if((*L)->count < SIZE){
		for(i = (*L)->count; i > 0; i--){
			(*L)->elem[i] = (*L)->elem[i-1];
		}
		(*L)->elem[i] = newElem;
		(*L)->count++;
	}
}

void insertSort(List *L, char newElem){
	int i;
	if((*L)->count < SIZE){
		for(i = (*L)->count-1; i >= 0 && newElem < (*L)->elem[i]; i--){
			(*L)->elem[i+1] = (*L)->elem[i];
		}
		(*L)->elem[i+1] = newElem;
		(*L)->count++;
	}
}

char locate(List L, char elem){
	int i;
	for(i = 0; i < L->count && L->elem[i] != elem; i++){}
	return i < L->count ? i : -1;
}

char retrieve(List L, int x){
	return x != -1 && x < L->count ? L->elem[x] : '\0';
}

void deleteFirst(List *L){
	int i;
	if((*L)->count < SIZE){
		for(i = 0; i < (*L)->count; i++){
			(*L)->elem[i] = (*L)->elem[i+1];
		}
		(*L)->count--;
	}
}

void makeNULL(List *L){
	free((*L)->elem); //Free the array
	free((*L)); //Free the structure
	*L = NULL; //Make it NULL
}

void displayList(List L){
	int i;
	for(i = 0; i < L->count; i++){
		printf("%c ", L->elem[i]);
	}
}

int main(){
	List L;
	initList(&L);
	
	insertFirst(&L, 'H');
	insertFirst(&L, 'G');
	insertFirst(&L, 'F');
	insertFirst(&L, 'B');
	insertFirst(&L, 'A');
	
	displayList(L); printf("\n");
	
	deleteFirst(&L);

	displayList(L); printf("\n");
	
	insertSort(&L, 'C');
	
	displayList(L); printf("\n");
	
	printf("%d = ", locate(L, 'F'));
	printf("%c", retrieve(L, locate(L, 'F')));
	

	return 0;
}
