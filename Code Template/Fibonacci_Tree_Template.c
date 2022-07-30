#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#define MAX 20
#define Type int

typedef Type data[MAX];
typedef struct node{
	Type data;
	struct node *left;
	struct node *right;
}NodeList, *BST;

//this function will initialize the given tree
void init_tree(BST *F){
	//Code here...
}

//utility func that checks if the given parameter is a perfect square
//NOTE: use math.h
int is_perfect_square(Type data){
	//Code here...
}

//checks whether the given parameter is a fibonacci value. Return -1 if false
int is_fibonacci(Type data){
	//Code here...
}

//insert data that are within the fibonacci sequence
void insert_fibonacci(BST *F, data fibo, int size){
	//Code here...
}

//display inorder traversal
void in_order(BST F){
	//Code here...
}

int main(){
	//Code here...
	return 0;
}
