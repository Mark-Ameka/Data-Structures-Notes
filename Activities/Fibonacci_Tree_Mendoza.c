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
	*F = NULL;
}

//utility func that checks if the given parameter is a perfect square
//NOTE: use math.h
int is_perfect_square(Type data){
	int s = sqrt(data);
	return (s*s) == data;
}

//checks whether the given parameter is a fibonacci value. Return -1 if false
int is_fibonacci(Type data){
	return is_perfect_square(5*data*data+4) || is_perfect_square(5*data*data-4) ? data : -1;
}

//insert data that are within the fibonacci sequence
void insert_fibonacci(BST *F, data fibo, int size){
	BST *trav;
	int i, ret_val;

	for(i = 0; i < size; i++){
		//checks if fibo[i] is a fibonacci value
		ret_val = is_fibonacci(fibo[i]);

		//checks if re_val is not -1
		if(ret_val != -1){
			//traverse in bst
			for(trav = F; *trav != NULL && (*trav)->data != ret_val;){
				trav = (*trav)->data < ret_val ? &(*trav)->right : &(*trav)->left;
			}
			
			//insert in bst
			if(*trav == NULL){
				*trav = calloc(1, sizeof(NodeList));
				if(*trav != NULL){
					(*trav)->data = ret_val;
				}
			}
		}
	}
}

//display inorder traversal
void in_order(BST F){
	if(F != NULL){
		in_order(F->left);
		printf("%d ", F->data);
		in_order(F->right);
	}
}

int main(){
	BST F;
	data fibo = {233, 199, 4, 6, 8, 12, 13, 21, 9, 34, 25, 144, 47, 89, 2, 1, 3, 62, 55, 5};
	
	init_tree(&F);
	insert_fibonacci(&F, fibo, 20);
	in_order(F);
	return 0;
}
