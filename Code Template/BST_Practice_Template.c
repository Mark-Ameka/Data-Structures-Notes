#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 15

typedef int SET[MAX];
typedef struct node{
	int data;
	struct node *left;
	struct node *right;
}*BST;

void initTree(BST *T);

void populateData(BST *T);

void insertTree_NR(BST *T, int newData); //Non-Recursive
void insertTree_R(BST *T, int newData); //Recursive

void deleteTree_NR(BST *T, int data); //Non-Recursive
void deleteTree_R(BST *T, int data); //Recursive

void displayPreOrder(BST T);
void displayInOrder(BST T);
void displayPostOrder(BST T);

BST* getMin(BST T); //Returning BST
BST* getMax(BST T); //Returning BST

int getMinElem(BST T); //Returning int
int getMaxElem(BST T); //Returning int

int deleteMin(BST *T);
int deleteMax(BST *T);

bool isMember(BST T, int val); //Returning true or false
int getHeight(BST T);
bool isBalance(BST T);

int main(){
	return 0;
}

void initTree(BST *T){
}

void insertTree_NR(BST *T, int newData){
}

void insertTree_R(BST *T, int newData){
}

void populateData(BST *T){
	SET val = {57, 54, 36, 23, 2, 19, 50, 46, 43, 39, 49, 78, 75, 73, 93};
	int i;
	
	for(i = 0; i < MAX; i++){
		//Insert here...
	}
}

void deleteTree_NR(BST *T, int data){
}

void deleteTree_R(BST *T, int data){
}

void displayPreOrder(BST T){
}

void displayInOrder(BST T){
}

void displayPostOrder(BST T){
}

BST* getMin(BST T){
}

BST* getMax(BST T){
}

int getMinElem(BST T){
}

int getMaxElem(BST T){
}

int deleteMin(BST *T){
}

int deleteMax(BST *T){
}

bool isMember(BST T, int val){
}

int getHeight(BST T){
}

bool isBalance(BST T){
}
