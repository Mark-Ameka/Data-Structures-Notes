#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 10

typedef int SET[MAX];
typedef int Type;
typedef struct{
	Type elem;
	Type next;
}Info;

typedef struct{
	Info data[MAX];
	Type avail;
}VSpace;

typedef int Stack;

void initStackHeap(VSpace *vs, Stack* L);
void pushStackHeap(VSpace *vs, Stack *L, Type newData);
void pushHeapSorted(VSpace *vs, Stack *L, Type newData);
void pushStackHeapBottom(VSpace *vs, Stack *L, Type newData);

void popStackHeap(VSpace *vs, Stack *L);

int top(VSpace vs, Stack L);
int find(VSpace vs, Stack L, Type data);
bool isEmpty(VSpace vs);
bool isFull(VSpace vs);

void displayStackHeap(VSpace vs, Stack L);

int main(){
	SET x = {1, 3, 5, 7, 9};
	VSpace mySpace;
	Stack myList;
	int i;
	
	initStackHeap(&mySpace, &myList);
	for(i = 0; i < MAX/2; i++) pushStackHeap(&mySpace, &myList, x[i]);
	
	displayStackHeap(mySpace, myList);
	
	return 0;
}

void initStackHeap(VSpace *vs, Stack*L){
	*L = -1;
	int i;
	for(i = MAX-1; i >= 0; i--){
		vs->data[i].next = i-1;
		vs->data[i].elem = 0;
	}
	vs->avail = MAX-1;
}

void pushStackHeap(VSpace *vs, Stack *L, Type newData){
	Stack temp;
	if(vs->avail != -1){
		temp = vs->avail;
		vs->avail = vs->data[temp].next;
		vs->data[temp].elem = newData;
		vs->data[temp].next = *L;
		*L = temp;
	}
}

void pushHeapSorted(VSpace *vs, Stack *L, Type newData){
	Stack temp;
	Stack LL;
	temp = LL = -1;
	if(vs->avail != -1){
		while(*L != -1 && newData < vs->data[*L].elem){
			temp = *L;
			*L = vs->data[temp].next;
			vs->data[temp].next = LL;
			LL = temp;
		}
		
		temp = vs->avail;
		if(temp != -1 && newData != vs->data[*L].elem){
			vs->avail = vs->data[temp].next;
			vs->data[temp].elem = newData;
			vs->data[temp].next = *L;
			*L = temp;
		}
		
		while(LL != -1){
			temp = LL;
			LL = vs->data[temp].next;
			vs->data[temp].next = *L;
			*L = temp;
		}
	}
}

void pushStackHeapBottom(VSpace *vs, Stack *L, Type newData){
	Stack temp;
	Stack LL;
	temp = LL = -1;
	if(vs->avail != -1){
		while(*L != -1){
			temp = *L;
			*L = vs->data[temp].next;
			vs->data[temp].next = LL;
			LL = temp;
		}
		
		temp = vs->avail;
		vs->avail = vs->data[temp].next;
		vs->data[temp].elem = newData;
		vs->data[temp].next = *L;
		*L = temp;
		
		while(LL != -1){
			temp = LL;
			LL = vs->data[temp].next;
			vs->data[temp].next = *L;
			*L = temp;
		}
	}
}

void popStackHeap(VSpace *vs, Stack *L){
	Stack temp;
	if(*L != -1){
		temp = *L;
		*L = vs->data[temp].next;
		vs->data[temp].next = vs->avail;
		vs->avail = temp;
	}
}

int top(VSpace vs, Stack L){
	return vs.avail != -1 ? vs.data[L].elem : -1;
}

int find(VSpace vs, Stack L, Type data){
	for(; L != -1 && data != vs.data[L].elem; L = vs.data[L].next);
	return L != -1 ? vs.data[L].elem : -1;
}

void displayStackHeap(VSpace vs, Stack L){
	Stack temp;
	temp = -1;
	while(L != -1){
		pushStackHeap(&vs, &temp, top(vs, L));
		popStackHeap(&vs, &L);
	}
	while(temp != -1){
		printf("%d ", top(vs, temp));
		pushStackHeap(&vs, &L, top(vs, temp));
		popStackHeap(&vs, &temp);
	}
	printf("\n");
}

bool isEmpty(VSpace vs){
	return vs.avail == -1 ? true : false;
}

bool isFull(VSpace vs){
	return vs.avail != -1 ? true : false;
}
