/*
Queue FIFO : First In First Out
A queue in C is basically a linear data structure to 
store and manipulate the data elements.
enqueue and dequeue are O(1) Constant time
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 10

typedef int SET[MAX];
typedef int Type;
typedef struct{
	Type data[MAX];
	Type front;
	Type rear;
}Queue;

void initQueue(Queue *Q);
Queue createQueue();
void enqueueQueue(Queue *Q, Type newData);			//O(1)
void enqueueQueueSorted(Queue *Q, Type newData);	//O(n)

void dequeueQueue(Queue *Q);						//O(1)

int front(Queue Q);									//O(1)
int find(Queue Q, Type data);						//O(n/2)
bool isEmpty(Queue Q);
bool isFull(Queue Q);

void displayQueue(Queue Q);

int main(){
	SET x = {1, 3, 5, 7, 9};
	Queue Q = createQueue();
	initQueue(&Q);
	int i;
	
	for(i = 0; i < MAX/2; i++) enqueueQueue(&Q, x[i]);
	displayQueue(Q);
	
	return 0;
}

void initQueue(Queue *Q){
	Queue q = createQueue();
}

Queue createQueue(){
	Queue q;
	q.front = 0;
	q.rear = MAX-1;
	return q;
}

void enqueueQueue(Queue *Q, Type newData){
	if(!isFull(*Q)){
		Q->rear = (Q->rear+1)%MAX;
		Q->data[Q->rear] = newData;
	}
}

void enqueueQueueSorted(Queue *Q, Type newData){
	Type newFront = (Q->rear+1)%MAX;
	if(!isFull(*Q)){
		while(Q->front != newFront && Q->data[Q->front] < newData){
			Q->rear = (Q->rear+1)%MAX;
			Q->data[Q->rear] = Q->data[Q->front];
			Q->front = (Q->front+1)%MAX;
		}
		
		Q->rear = (Q->rear+1)%MAX;
		Q->data[Q->rear] = newData;
		
		while(Q->front != newFront){
			Q->rear = (Q->rear+1)%MAX;
			Q->data[Q->rear] = Q->data[Q->front];
			Q->front = (Q->front+1)%MAX;
		}
	}
}

void dequeueQueue(Queue *Q){
	if(!isEmpty(*Q)){
		Q->front = (Q->front+1)%MAX;
	}
}

int front(Queue Q){
	return (Q.rear+1)%MAX != Q.front ? Q.data[Q.front] : -1;
}

int find(Queue Q, Type data){
	for(; Q.front != (Q.rear+1)%MAX && data != Q.data[Q.front]; Q.front = (Q.front+1)%MAX);
	return (Q.front != (Q.rear+1)%MAX) ? Q.data[Q.front] : -1;
}

void displayQueue(Queue Q){
	Type newFront = (Q.rear+1)%MAX;
	if(!isEmpty(Q)){
		while(Q.front != newFront){
			printf("%d ", front(Q));
			Q.rear = (Q.rear+1)%MAX;
			Q.data[Q.rear] = Q.data[Q.front];
			Q.front = (Q.front+1)%MAX;
		}
	}
	printf("\n");
}

bool isEmpty(Queue Q){
	return (Q.rear+1)%MAX == Q.front ? true : false;
}

bool isFull(Queue Q){
	return (Q.rear+2)%MAX == Q.front ? true : false;
}
