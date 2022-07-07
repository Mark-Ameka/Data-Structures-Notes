#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 10

typedef int SET[MAX];
typedef int Type;
typedef struct node{
	Type data;
	struct node *link;
}NodeList, *NodeLink;

typedef struct{
	NodeLink front;
	NodeLink rear;
}QueueList;

void initQueueList(QueueList *Q);
QueueList createQueueList();
void enqueueQueueList(QueueList *Q, Type newData);
void enqueueQueueSortedList(QueueList *Q, Type newData);

void dequeueQueueList(QueueList *Q);

int find(QueueList Q, Type data);
int front(QueueList Q);
bool isEmpty(QueueList Q);
bool isFull(QueueList Q);

void displayQueueList(QueueList Q);

int main(){
	SET x = {1, 3, 5, 7, 9};
	QueueList QLL = createQueueList();
	initQueueList(&QLL);
	int i;
	
	for(i = 0; i < MAX/2; i++) enqueueQueueList(&QLL, x[i]);
	
	displayQueueList(QLL);
	
	return 0;
}

void initQueueList(QueueList *Q){
	*Q = createQueueList();
}

QueueList createQueueList(){
	QueueList q;
	q.front = NULL;
	q.rear = NULL;
	return q;
}

void enqueueQueueList(QueueList *Q, Type newData){
	NodeLink temp = malloc(sizeof(NodeList));
	if(temp != NULL){
		temp->data = newData;
		temp->link = NULL;
		if(Q->rear == NULL){
			Q->front = temp;
		} else{
			Q->rear->link = temp;
		}
		Q->rear = temp;
	}
}

void enqueueQueueSortedList(QueueList *Q, Type newData){
	NodeLink temp;
	QueueList QQ;
	QQ.front = QQ.rear = NULL;
	
	//Move contents of Q to QQ until condition satisfies
	while(Q->front != NULL && newData > Q->front->data){
		temp = Q->front;
		Q->front = temp->link;
		if(QQ.front == NULL){
			QQ.front = temp;
		} else{
			QQ.rear->link = temp;
		}
		QQ.rear = temp;
	}
	
	//malloc temp for inserting the newData into QQ
	temp = malloc(sizeof(NodeList));
	if(temp != NULL){
		temp->data = newData;
		if(QQ.rear == NULL){
			QQ.front = temp;
		} else{
			QQ.rear->link = temp;
		}
		QQ.rear = temp;
	}
	
	//Finish moving the contents of Q into QQ
	while(Q->front != NULL){
		temp = Q->front;
		Q->front = temp->link;
		QQ.rear->link = temp;
		QQ.rear = temp;
	}
	
	//After, return all the contents including the newData inserted back into the original QueueList which is Q.
	while(QQ.front != NULL){
		temp = QQ.front;
		QQ.front = temp->link;
		if(Q->front == NULL){
			Q->front = temp;
		} else{
			Q->rear->link = temp;
		}
		Q->rear = temp;
	}
}

void dequeueQueueList(QueueList *Q){
	NodeLink temp;
	if(Q->front != NULL){
		temp = Q->front;
		Q->front = temp->link;
		if(Q->front == NULL){
			Q->rear = NULL;
		}
		free(temp);
	}
}

int front(QueueList Q){
	return (Q.rear != NULL) ? Q.front->data : -1;
}

int find(QueueList Q, Type data){
	for(; Q.front != NULL && data != Q.front->data; Q.front = Q.front->link);
	return (Q.front != NULL) ? Q.front->data : -1;
}

void displayQueueList(QueueList Q){
	QueueList QQ;
	initQueueList(&QQ);
	
	while(Q.front != NULL){
		printf("%d ", front(Q));
		enqueueQueueList(&QQ, front(Q));
		dequeueQueueList(&Q);
	}
	while(QQ.front != NULL){
		enqueueQueueList(&Q, front(QQ));
		dequeueQueueList(&QQ);
	}
	printf("\n");
	
	/*
	TRAVERSAL: 
	while(Q.front != NULL){
		printf("%d ", Q.front->data);
		Q.front = Q.front->link;
	}
	printf("\n");
	*/
	
	/*
	NOT CALLING USER-DEFINED FUNCTION:
	while(Q.front != NULL){
		printf("%d ", Q.front->data);
		temp = Q.front;
		Q.front = temp->link;
		if(QQ.front == NULL){
			QQ.front = temp;
		} else{
			QQ.rear->link = temp;
		}
		QQ.rear = temp;
	}
	while(QQ.front != NULL){
		temp = QQ.front;
		QQ.front = temp->link;
		if(Q.front == NULL){
			Q.front = temp;
		} else{
			Q.rear->link = temp;
		}
		Q.rear = temp;
	}
	*/
	
	
}

bool isEmpty(QueueList Q){
	return Q.rear == NULL ? true : false;
}
bool isFull(QueueList Q){
	return Q.rear != NULL ? false : true;
}
