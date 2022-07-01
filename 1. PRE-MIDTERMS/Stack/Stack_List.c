#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 10

typedef int SET[MAX];
typedef int Type;
typedef struct node{
	Type data;
	struct node *link;
}StackList, *StackLink;

void initStackList(StackLink *S);
void pushList(StackLink *S, Type newData);
void pushListSorted(StackLink *S, Type newData);
void pushListBottom(StackLink *S, Type newData);

void popList(StackLink *S);

int frontList(StackLink S);
bool findList(StackLink S, Type newData);
bool isEmpty(StackLink S);
bool isFull(StackLink S);

void displayStackList(StackLink S);

int main(){
	SET x = {1, 3, 5, 7, 9};
	StackLink S;
	int i;
	
	initStackList(&S);
	for(i = 0; i < MAX/2; i++) pushList(&S, x[i]);
	
	displayStackList(S);
		
	return 0;
}

void initStackList(StackLink *S){
	*S = NULL;
}

void pushList(StackLink *S, Type newData){
	StackLink temp = malloc(sizeof(StackList));
	if(temp != NULL){
		temp->data = newData;
		temp->link = *S;
		*S = temp;
	}
}

void pushListSorted(StackLink *S, Type newData){
	StackLink SS;
	StackLink temp;
	temp = SS = NULL;
	while(*S != NULL && newData < (*S)->data){
		temp = *S;
		*S = temp->link;
		temp->link = SS;
		SS = temp;
	}
	
	temp = malloc(sizeof(StackList));
	if(temp != NULL && newData != (*S)->data){
		temp->data = newData;
		temp->link = *S;
		*S = temp;
	}
	
	while(SS != NULL){
		temp = SS;
		SS = temp->link;
		temp->link = *S;
		*S = temp;
	}
}

void pushListBottom(StackLink *S, Type newData){
	StackLink SS;
	StackLink temp;
	temp = SS = NULL;
	while(*S != NULL){
		temp = *S;
		*S = temp->link;
		temp->link = SS;
		SS = temp;
	}
	
	temp = malloc(sizeof(StackList));
	if(temp != NULL){
		temp->data = newData;
		temp->link = *S;
		*S = temp;
	}
	
	while(SS != NULL){
		temp = SS;
		SS = temp->link;
		temp->link = *S;
		*S = temp;
	}
}

void popList(StackLink *S){
	StackLink temp;
	if(*S != NULL){
		temp = *S;
		*S = temp->link;
		free(temp);
	}
}

int frontList(StackLink S){
	return S != NULL ? S->data : -1;
}

bool findList(StackLink S, Type newData){
	for(; S != NULL && newData != S->data; S = S->link);
	return (S != NULL) ? true : false;
}

void displayStackList(StackLink S){
	StackLink temp = NULL;
	StackLink SS = NULL;
	while(!isEmpty(S)){
		temp = S;
		S = temp->link;
		temp->link = SS;
		SS = temp;
	}
	while(!isEmpty(SS)){
		printf("%d ", frontList(SS));
		temp = SS;
		SS = temp->link;
		temp->link = S;
		S = temp;
	}
	printf("\n");
}

bool isEmpty(StackLink S){
	return (S == NULL) ? true : false;
}

bool isFull(StackLink S){
	return (S != NULL) ? false : true;
}
