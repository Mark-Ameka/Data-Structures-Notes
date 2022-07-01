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

typedef struct{
	Type front;
	Type rear;
}QueueCursor;

void initializeHeap(VSpace *vs);
void createCursorQueue(QueueCursor *q);
void enqueueCursorQueue(VSpace *vs, QueueCursor *q, int newData);
void enqueueCursorQueueSorted(VSpace *vs, QueueCursor *q, int newData);

void dequeueCursorQueue(VSpace *vs, QueueCursor *q);

int front(VSpace vs, QueueCursor q);
int find(VSpace vs, QueueCursor q, Type data);
bool isEmpty(QueueCursor q);
bool isFull(QueueCursor q);

void displayCursorQueue(VSpace vs, QueueCursor q);

int main(){
	SET x = {1, 3, 5, 7, 9};
	VSpace myQueueSpace;
	QueueCursor myQueueList;
	initializeHeap(&myQueueSpace);
	createCursorQueue(&myQueueList);
	int i;
	
	for(i = 0; i < MAX/2; i++) enqueueCursorQueue(&myQueueSpace, &myQueueList, x[i]);
	
	displayCursorQueue(myQueueSpace, myQueueList);
	
	return 0;
}

void initializeHeap(VSpace *vs){
	Type i;
	for(i = MAX-1; i >= 0; i--){
		vs->data[i].next = i-1;
		vs->data[i].elem = 0;
	}
	vs->avail = MAX-1;
}

void createCursorQueue(QueueCursor *q){
	q->front = -1;
	q->rear = -1;
}

void enqueueCursorQueue(VSpace *vs, QueueCursor *q, int newData){
	Type temp;
	if(vs->avail != -1){
		temp = vs->avail;
		vs->avail = vs->data[temp].next;
		vs->data[temp].elem = newData;
		vs->data[temp].next = -1;
		if(q->front == -1){
			q->front = temp;
		} else{
			vs->data[q->rear].next = temp;
		}
		q->rear = temp;
	}
}

void enqueueCursorQueueSorted(VSpace *vs, QueueCursor *q, int newData){
	Type temp;
	QueueCursor qq;
	createCursorQueue(&qq);
	if(vs->avail != -1){
		while(q->front != -1 && newData > vs->data[q->front].elem){
			temp = q->front;
			q->front = vs->data[q->front].next;
			if(qq.rear == -1){
				qq.front = temp;
			} else{
				vs->data[qq.rear].next = temp;
			}
			qq.rear = temp;
		}
		
		temp = vs->avail;
		if(temp != -1){
			vs->avail = vs->data[temp].next;
			vs->data[temp].elem = newData;
			vs->data[temp].next = -1;
			if(qq.rear == -1){
				qq.front = temp;
			} else{
				vs->data[qq.rear].next = temp;
			}
			qq.rear = temp;
		}
		
		while(q->front != -1){
			temp = q->front;
			q->front = vs->data[temp].next;
			vs->data[qq.rear].next = temp;
			qq.rear = temp;
		}
		
		while(qq.front != -1){
			temp = qq.front;
			qq.front = vs->data[temp].next;
			if(q->front == -1){
				q->front = temp;
			} else{
				vs->data[q->rear].next = temp;
			}
			q->rear = temp;
		}
	}
}

void dequeueCursorQueue(VSpace *vs, QueueCursor *q){
	Type temp;
	if(q->front != -1){
		temp = q->front;
		q->front = vs->data[temp].next;
		vs->data[temp].elem = 0;
		
		if(temp != -1 && temp < MAX){
			if(q->front == -1){
				q->rear = -1;
			}
			vs->data[temp].next = vs->avail;
			vs->avail = temp;
		}
	}
}

int front(VSpace vs, QueueCursor q){
	return vs.data[q.front].elem;
}

int find(VSpace vs, QueueCursor q, Type data){
	for(; q.front != -1 && data != vs.data[q.front].elem; q.front = vs.data[q.front].next);
	return q.front != -1 ? vs.data[q.front].elem : -1;
}

void displayCursorQueue(VSpace vs, QueueCursor q){
	QueueCursor tempQueue;
	createCursorQueue(&tempQueue);
	
	while(q.front != -1){
		printf("%d ", front(vs , q));
		enqueueCursorQueue(&vs, &tempQueue, front(vs , q));
		dequeueCursorQueue(&vs, &q);
	}
	while(tempQueue.front != -1){
		enqueueCursorQueue(&vs, &q, front(vs , tempQueue));
		dequeueCursorQueue(&vs, &tempQueue);
	}
	
//	for(; q.front != -1; q.front = vs.data[q.front].next){
//		printf("%d ", vs.data[q.front].elem);
//	}
}

bool isEmpty(QueueCursor q){
	return q.front != -1 ? true : false;
}

bool isFull(QueueCursor q){
	return q.front == -1 ? true : false;
}
