/*	AVL tree is a self-balancing Binary Search Tree (BST) 
	where the difference between heights of left and right subtrees cannot be more than one for all nodes. 
	
	Most of the BST operations (e.g., search, max, min, insert, delete.. etc) 
	take O(h) time where h is the height of the BST. The cost of these operations may become 
	O(n) for a skewed Binary tree. If we make sure that height of the tree remains 
	O(Logn) after every insertion and deletion, then we can guarantee an upper bound of 
	O(Logn) for all these operations. The height of an AVL tree is always O(Logn) where n 
	is the number of nodes in the tree (See this video lecture for proof). 
*/

/* The constructed AVL Tree would be
*
*             30
*           /   \
*         20    40
*        /  \     \
*       10  25    50
*/

#include <stdio.h>
#include <stdlib.h>
#define MAX 7

typedef int SET[MAX];
typedef struct node{
	int data;
	int height;
	struct node *left;
	struct node *right;
}NodeList, *AVL;

int height(AVL A){
	return A == NULL ? 0 : A->height;
}

int max(int a, int b){
	return a > b ? a : b;
}

//right rotate subtree rooted with y
void right_rotate(AVL *A){
	AVL *y = A;
	AVL x = (*y)->left;
	AVL T2 = x->right;
	
	//Rotation
	x->right = *y;
	(*y)->left = T2;
	
	//Update heights
	(*y)->height = max(height((*y)->left), height((*y)->right)) + 1;
	x->height = max(height(x->left), height(x->right)) + 1;
	
	//Since we are not returning let *A point to x
	*A = x;
}

//right rotate subtree rooted with x
void left_rotate(AVL *A){
	AVL *x = A;
	AVL y = (*x)->right;
	AVL T2 = y->left;
	
	//Rotation
	y->left = *x;
	(*x)->right = T2;
	
	//Update heights
	(*x)->height = max(height((*x)->left), height((*x)->right)) + 1;
	y->height = max(height(y->left), height(y->right)) + 1;
	
	//Since we are not returning let *A point to y
	*A = y;
}

//An AVL Tree is balance if the returned value will not be less than to -1
//		:1 is Balance
//		:-1 is Balance	
//		:0 is Balance	
int get_balance(AVL A){
	return A == NULL ? 0 : height(A->left) - height(A->right);
}

//insert_avl recursive function
//O(Logn)
void insert_avl(AVL *A, int new_vl){
	if(*A == NULL){
		*A = calloc(1, sizeof(NodeList));
		if(*A != NULL && (*A)->data != new_vl){
			(*A)->data = new_vl;
			(*A)->height = 1;
		}
		return;
	}
	
	//returned if (*A)->data == new_vl
	//A BST Tree cannot have the same values
	if(new_vl < (*A)->data){
		insert_avl(&(*A)->left, new_vl);
	} else if(new_vl > (*A)->data){
		insert_avl(&(*A)->right, new_vl);
	} else{
		return;
	}
	
	(*A)->height = 1 + max(height((*A)->left), height((*A)->right));
	
	//Will be excecuted if the tree is unbalanced.
	int bl = get_balance(*A);
	
	//LEFT LEFT
	/*							
	*
	*		         z                                      y 
	*		        / \                                   /   \
	*		       y   T4      Right Rotate (z)          x      z
	*		      / \          - - - - - - - - ->      /  \    /  \ 
	*		     x   T3                               T1  T2  T3  T4
	*		    / \
	*		  T1   T2
	*/
	if(bl > 1 && new_vl < (*A)->left->data){
		right_rotate(A);
		return;
	}
	
	//RIGHT RIGHT
	/*
	*			  z                                y
	*			 /  \                            /   \ 
	*			T1   y     Left Rotate(z)       z      x
	*			    /  \   - - - - - - - ->    / \    / \
	*			   T2   x                     T1  T2 T3  T4
	*			       / \
	*			     T3  T4
	*/
	if(bl < -1 && new_vl > (*A)->right->data){
		left_rotate(A);
		return;
	}
	
	//LEFT RIGHT
	/*
	*		     z                               z                           x
	*		    / \                            /   \                        /  \ 
	*		   y   T4  Left Rotate (y)        x    T4  Right Rotate(z)    y      z
	*		  / \      - - - - - - - - ->    /  \      - - - - - - - ->  / \    / \
	*		T1   x                          y    T3                    T1  T2 T3  T4
	*		    / \                        / \
	*		  T2   T3                    T1   T2
	*/
	if(bl > 1 && new_vl > (*A)->left->data){
		left_rotate(&(*A)->left);
		right_rotate(A);
		return;
	}
	
	//RIGHT LEFT
	/*
	*		   z                            z                            x
	*		  / \                          / \                          /  \ 
	*		T1   y   Right Rotate (y)    T1   x      Left Rotate(z)   z      y
	*		    / \  - - - - - - - - ->     /  \   - - - - - - - ->  / \    / \
	*		   x   T4                      T2   y                  T1  T2  T3  T4
	*		  / \                              /  \
	*		T2   T3                           T3   T4
	*/
	if(bl < -1 && new_vl < (*A)->right->data){
		right_rotate(&(*A)->right);
		left_rotate(A);
		return;
	}
}

void delete_avl(AVL *A, int val){
	AVL temp, *trav;
	if(*A == NULL) return;
	
	if(val < (*A)->data){
		delete_avl(&(*A)->left, val);
	} else if(val > (*A)->data){
		delete_avl(&(*A)->right, val);
	} else{
		trav = A;
		if(*trav != NULL){
			temp = *trav;
			if((*trav)->left == NULL){
				*trav = (*trav)->right;
			} else if((*trav)->right == NULL){
				*trav = (*trav)->left;
			} else{
				for(trav = &(*trav)->left; (*trav)->right != NULL; trav = &(*trav)->right){}
				temp->data = (*trav)->data;
				
				temp = *trav;
				*trav = temp->left;
			}
			free(temp);
		}
	}
	
	if(*A == NULL) return;
	(*A)->height = 1 + max(height((*A)->left), height((*A)->right));
	
	//Will be excecuted if the tree is unbalanced.
	int bl = get_balance(*A);
	
	//LEFT LEFT
	if(bl > 1 && get_balance((*A)->left) >= 0){
		right_rotate(A);
		return;
	}
	
	//RIGHT RIGHT
	if(bl < -1 && get_balance((*A)->right) <= 0){
		left_rotate(A);
		return;
	}
	
	//LEFT RIGHT
	if(bl > 1 && get_balance((*A)->left) < 0){
		left_rotate(&(*A)->left);
		right_rotate(A);
		return;
	}
	
	//RIGHT LEFT
	if(bl < -1 && get_balance((*A)->right) > 0){
		right_rotate(&(*A)->right);
		left_rotate(A);
		return;
	}
}

//Function will return the node of the smallest value which traveses to the leftmost
AVL min_node(AVL A){
	AVL temp = A;
	while(temp->left != NULL){
		temp = temp->left;
	}
	return temp;
}

void pre_order(AVL A){
	if(A != NULL){
		printf("%d ", A->data);
		pre_order(A->left);
		pre_order(A->right);
	}
}

int main(){
	SET data = {2, 1, 7, 4, 5, 3, 8};
	AVL A = NULL;
	int i;
	
	for(i = 0; i < MAX; i++){
		insert_avl(&A, data[i]);
	}
	printf("[insertion]:\n");
	pre_order(A); printf("\n\n");
	
	printf("[deletion]: 3\n");
	delete_avl(&A, 3);
	pre_order(A); printf("\n");
	
	
	return 0;
}
