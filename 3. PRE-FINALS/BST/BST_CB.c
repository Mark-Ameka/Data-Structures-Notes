#include <stdio.h>
#define MAX 15

typedef int SET[MAX];
typedef struct{
	int elem;
	int left;
	int right;
}Node;

typedef struct{
	Node data[MAX];
	int avail;
}VHeap;

typedef int List;

//Version 2
void init_bst(VHeap *BST, List *T){
	int i;
	*T = -1;
	
	for(i = MAX-1; i >= 0; i--){
		BST->data[i].elem = -1;
		BST->data[i].left = i-1;
		BST->data[i].right = i-1;
	}
	BST->avail = MAX-1;
}

void insert_bst(VHeap *BST, List *T, int n_val){
	int temp, *trav;
	
	for(trav = T; *trav != -1 && BST->data[*trav].elem != n_val;){
		trav = BST->data[*trav].elem < n_val ? &BST->data[*trav].right : &BST->data[*trav].left;
	}
	
	if(*trav == -1){
		//Allocate temp
		temp = BST->avail;
		BST->data[temp].elem = n_val;
		
		//Point avail to designated link
		if(BST->data[*trav].elem < n_val){
			BST->avail = BST->data[temp].right;
			BST->data[temp].left = *trav;
			BST->data[temp].right = -1;
		} else{
			BST->avail = BST->data[temp].left;
			BST->data[temp].right = *trav;
			BST->data[temp].left = -1;
		}
		
		*trav = temp;
	}
}

void delete_bst(VHeap *BST, List *T, int n_val){
	int temp, *trav;
	
	for(trav = T; *trav != -1 && BST->data[*trav].elem != n_val;){
		trav = BST->data[*trav].elem < n_val ? &BST->data[*trav].right : &BST->data[*trav].left;
	}
	
	if(*trav != -1){
		temp = *trav;
		if(BST->data[*trav].left == -1){
			*trav = BST->data[*trav].right;
		} else if(BST->data[*trav].right == -1){
			*trav = BST->data[*trav].left;
		} else{
			for(trav = &BST->data[*trav].left; BST->data[*trav].right != -1; trav = &BST->data[*trav].right){}
			BST->data[temp].elem = BST->data[*trav].elem;
			
			//Delete Node
			temp = *trav;
			*trav = BST->data[temp].left;
		}
		//Set avail back
		BST->data[temp].elem = -1;
		BST->data[temp].left = BST->avail;
		BST->data[temp].right = BST->avail;
		BST->avail = temp;
	}
}

void visual_bst(VHeap BST, List T){
	printf("\n%15s | %15s | %15s | %15s", "INDEX", "ELEM", "LEFT", "RIGHT");

	int i;
	for(i = 0; i < MAX; i++){
		printf("\n%15d | %15d | %15d | %15d", i, BST.data[i].elem, BST.data[i].left, BST.data[i].right);
	}
	printf("\nAvailable: %d\n", BST.avail);
	printf("List: %d\n", T);
}

void pre_order(VHeap BST, List T){
	if(T != -1){
		printf("%d ", BST.data[T].elem);
		pre_order(BST, BST.data[T].left);
		pre_order(BST, BST.data[T].right);
	}
}

int main(){
	VHeap BST;
	List T;
	SET x = {77, 28, 8, 10, 18, 39, 29, 76, 90, 89, 85, 95, 94, 98};
//	SET x = {6, 2, 5, 8, 3};
	int i;
	
	init_bst(&BST, &T);
	
	for(i = 0; i < MAX; i++) insert_bst(&BST, &T, x[i]);
//	for(i = 0; i < 5; i++) insert_bst(&BST, &T, x[i]);
	
	visual_bst(BST, T);
	pre_order(BST, T);
	
	printf("\n\n[DELETE] : 39");
	delete_bst(&BST, &T, 39);
	visual_bst(BST, T);
	pre_order(BST, T);
	
	return 0;
}
