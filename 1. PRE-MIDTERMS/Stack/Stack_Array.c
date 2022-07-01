/*
Stack LIFO : Last In First Out
A stack is a linear data structure, collection of items of the same type.
push and pop are O(1) Constant time
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 10

typedef int SET[MAX];
typedef int Type;
typedef struct{
	Type data[MAX];
	Type count;
}Stack;

Stack initializeStack();

void push(Stack *S, Type newData);				//O(1)
void pushSorted(Stack *S, Type newData);		//O(1)
void pushBottom(Stack *S, Type newData);		//O(n)

void pop(Stack *S);								//O(1)

int front(Stack S);								//O(1)
int find(Stack S, Type val);					//O(n/2)
bool isEmpty(Stack S);
bool isFull(Stack S);

void displayStack(Stack S);

int main(){
	SET x = {1, 3, 5, 7, 9};
	Stack S = initializeStack();
	int i;
	
	for(i = 0; i < MAX/2; i++) push(&S, x[i]);
	displayStack(S);
	
	return 0;
}

Stack initializeStack(){
	Stack S;
	S.count = -1;
	return S;
}

void push(Stack *S, Type newData){
	if(S->count != MAX-1){
		S->count++;
		S->data[S->count] = newData;
	}
}

void pushSorted(Stack *S, Type newData){
	Stack temp;
	temp.count = -1;
	if(S->count != MAX-1){
		while(S->count != -1 && newData < S->data[S->count]){
			temp.count++;
			temp.data[temp.count] = S->data[S->count];
			S->count--;
		}
		if(S->count == -1 || S->data[S->count] != newData){
			S->count++;
			S->data[S->count] = newData;
		}
		while(temp.count != -1){
			S->count++;
			S->data[S->count] = temp.data[temp.count];
			temp.count--;
		}
	}
}

void pushBottom(Stack *S, Type newData){
	Stack temp;
	temp.count++;
	while(S->count != -1){
		temp.count++;
		temp.data[temp.count] = S->data[S->count];
		S->count--;
	}
	
	S->count++;
	S->data[S->count] = newData;
	
	while(temp.count != -1){
		S->count++;
		S->data[S->count] = temp.data[temp.count];
		temp.count--;
	}
}

void pop(Stack *S){
	if(S->count != -1){
		S->count--;
	}
}

int front(Stack S){
	return S.count != -1 ? S.data[S.count] : -1;	
}

int find(Stack S, Type val){
	for(; S.count != -1 && val != S.data[S.count]; S.count--);
	return S.count != -1 ? S.count : -1;
}

void displayStack(Stack S){
	Stack temp;
	temp = initializeStack();
	while(!isEmpty(S)){
		push(&temp, front(S));
		pop(&S);
	}
	while(!isEmpty(temp)){
		printf("%d ", temp.data[temp.count]);
		push(&S, front(temp));
		pop(&temp);
	}
	printf("\n");
}

bool isEmpty(Stack S){
	return (S.count == -1) ? true : false;
}

bool isFull(Stack S){
	return (S.count == MAX) ? true : false;
}
