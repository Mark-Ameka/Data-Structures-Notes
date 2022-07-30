/*
	Binary Search Tree: is a node-based binary tree data structure which has the following properties:
		* The left subtree of a node contains only nodes with keys lesser than the node’s key.
		* The right subtree of a node contains only nodes with keys greater than the node’s key.
		* The left and right subtree each must also be a binary search tree.					(GeeksForGeeks)
*/

/*       Given Tree Structure:
*
*					  	  77
*					   /      \
*                    28        90 
*                  /   \      /   \
*                8    39     89   95
*                \   /  \   /    /  \
*                10 29 76  85   94  98
*
*		Pre-Order:      77 28 8 10 18 39 29 76 90 89 85 95 94 98
*		In-Order:       8 10 18 28 29 39 76 77 85 89 90 94 95 98
*		Post-Order:     18 10 8 29 76 39 28 85 89 94 98 95 90 77
*/
	
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 14

typedef int SET[MAX];
typedef struct node{
	int data;
	struct node *left;
	struct node *right;
}BSTList, *BST;

void initTree(BST *T);

void insertTree_R(BST *T, int newData); //Recursive
void deleteTree_R(BST *T, int data); //Recursive

void displayAllOrder(BST T);
void displayInOrder(BST T);
void displayPreOrder(BST T);
void displayPostOrder(BST T);

int main(){
	BST T;
	SET x = {77, 28, 8, 10, 18, 39, 29, 76, 90, 89, 85, 95, 94, 98};
	int i, toFind;
		
	initTree(&T);
	for(i = 0; i < MAX; i++) insertTree_NR(&T, x[i]);
	
	displayAllOrder(T);
	
	return 0;
}

void initTree(BST *T){
	*T = NULL;
}

void insertTree_R(BST *T, int newData){
	if(*T != NULL && (*T)->data != newData){
		T = ((*T)->data < newData) ? &(*T)->right : &(*T)->left;
		insertTree_R(T, newData);
	} else{
		*T = calloc(1, sizeof(BSTList));
		if(*T != NULL){
			(*T)->data = newData;
		}
	}
}

void deleteTree_R(BST *T, int data){
	BST temp, *trav;
	if(*T != NULL && (*T)->data != data){
		T = ((*T)->data < data) ? &(*T)->right : &(*T)->left;
		deleteTree_R(T, data);
	} else{
		temp = *T;
		if((*T)->left == NULL){
			*T = (*T)->right;
		} else if((*T)->right == NULL){
			*T = (*T)->left;
		} else{
			for(trav = &(*T)->left; (*trav)->right != NULL; trav = &(*trav)->right){}
			temp->data = (*trav)->data;
			
			temp = *trav;
			*trav = temp->left;
		}
		free(temp);
	}
}

void displayInOrder(BST T){
	if(T != NULL){
		displayInOrder(T->left);
		printf("%d ", T->data);
		displayInOrder(T->right);
	}
}

void displayPreOrder(BST T){
	if(T != NULL){
		printf("%d ", T->data);
		displayPreOrder(T->left);
		displayPreOrder(T->right);
	}
}

void displayPostOrder(BST T){
	if(T != NULL){
		displayPostOrder(T->left);
		displayPostOrder(T->right);
		printf("%d ", T->data);
	}
}

void displayAllOrder(BST T){
	printf("Pre-Order:\t");
	displayPreOrder(T); printf("\n");
	printf("In-Order:\t");
	displayInOrder(T); printf("\n");
	printf("Post-Order:\t");
	displayPostOrder(T); printf("\n");
}
