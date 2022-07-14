/*
	Open Hashing (Chaining) - allows the set to be stored in potentially unlimited
	---------------------------------------------------------------------
	D[0] =>		10  	->  	NULL
	D[1] =>		NULL
	D[2] =>		72  	->  	NULL
	D[3] =>		63  	-> 		43 		-> 		NULL
	D[4] =>		NULL
	D[5] =>		25  	-> 		75 		->		45 		->		NULL
	D[6] => 	16  	->   	NULL
	D[7] => 	NULL
	D[8] => 	78 		->  	NULL
	D[9] => 	99		->  	NULL
*/

/*
	  1010 1110
	1 0101 0001
	
	1 0101 0001
			  1 +
	1 0101 0010
*/

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define MAX 10

typedef struct node{
	int data;
	struct node *link;
}NodeList, *NodeLink;

typedef int SET[MAX];
typedef NodeLink Dictionary[MAX];

void initDictionary(Dictionary D);
void insertDictionary(Dictionary D, int newVal);
void insertSortedDictionary(Dictionary D, int newVal);
void deleteDictionary(Dictionary D, int val);
int hashValue(int num);
void displayDictionary(Dictionary D);

int main(){
	SET data = {99, 25, 16, 263, 75, 43, 72, 78, 45, 10};
	Dictionary D;
	initDictionary(D);
	int i;
	
	for(i = 0; i < MAX; i++) insertDictionary(D, data[i]);
	displayDictionary(D);
	
	printf("Insert Sorted: [35]\n");
	insertSortedDictionary(D, 35);
	displayDictionary(D);
	
	printf("Delete: [35]\n");
	deleteDictionary(D, 35);
	displayDictionary(D);
	
	return 0;
}

void initDictionary(Dictionary D){
	int i;
	for(i = 0; i < MAX; i++){
		D[i] = NULL;
	}
}

void insertDictionary(Dictionary D, int newVal){
	NodeLink *trav;
	int i;
	int hash = hashValue(newVal);
	
	for(trav = &D[hash]; *trav != NULL && (*trav)->data != newVal; trav = &(*trav)->link){}
	if(*trav == NULL){
		*trav = malloc(sizeof(NodeList));
		if(*trav != NULL){
			(*trav)->data = newVal;
			(*trav)->link = NULL;
		}
	}
}

void insertSortedDictionary(Dictionary D, int newVal){
	NodeLink *trav, temp;
	int i;
	int hash = hashValue(newVal);
	
	for(trav = &D[hash]; *trav != NULL && (*trav)->data < newVal; trav = &(*trav)->link){}
	if(*trav == NULL || (*trav)->data != newVal){
		temp = malloc(sizeof(NodeList));
		if(temp != NULL){
			temp->data = newVal;
			temp->link = *trav;
			*trav = temp;
		}
	}
}

void deleteDictionary(Dictionary D, int val){
	NodeLink *trav, temp;
	int i;
	int hash = hashValue(val);
	
	for(trav = &D[hash]; *trav != NULL && (*trav)->data != val; trav = &(*trav)->link){}
	if(*trav != NULL){
		temp = *trav;
		*trav = temp->link;
		free(temp);
	}
	
}

//Hash Values could be any algorithm
int hashValue(int num){
	return (num)%MAX;
}

void displayDictionary(Dictionary D){
	int i;
	NodeLink trav;
	
	printf("[index]\n");
	for(i = 0; i < MAX; i++){
		printf("%3s[%d] => ", "D", i);
		HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

		for(trav = D[i]; trav != NULL; trav = trav->link){
			SetConsoleTextAttribute(h, 3);
			printf("%4d", trav->data);
			SetConsoleTextAttribute(h, 15);
			printf("%4s", "->");
		}
		SetConsoleTextAttribute(h, 15);
		if(trav == NULL) printf("%4c", 254);
		printf("\n");
	}
	printf("\n");
	system("pause");
	system("cls");
}
