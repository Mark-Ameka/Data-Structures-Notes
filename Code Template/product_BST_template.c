/************************************************************************************
*																					*
*	ABC Restaurant has a program which tracks the inventory of their menu			*
*	items using an internal binary search tree, organized by item_ID. 				*
*	See the data structure definition on the right.									*
*	
*************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct product{
	char prod_ID[10];
	char prod_name[50];
	int qty_remaining;
}prodType; /*Item record*/

typedef struct node{
	prodType prod;
	struct node *LChild, *RChild;
}nodeType, *BST;

typedef prodType p_data[10];
//Util Functions

void insert_bst(BST *T, prodType new_val){
	BST *trav;
	for(trav = T; *trav != NULL && strcmp((*trav)->prod.prod_ID, new_val.prod_ID) != 0;){
		trav = strcmp((*trav)->prod.prod_ID, new_val.prod_ID) < 0 ? &(*trav)->RChild : &(*trav)->LChild;
	}
	if(*trav == NULL){
		*trav = calloc(1, sizeof(nodeType));
		if(*trav != NULL){
			(*trav)->prod = new_val;
		}
	}
}

void populate_prod(BST *T){
	p_data p = {{"A1006", "Fish", 266}, {"A1008", "Kodiak Cakes", 22}, 
				{"A1003", "Milk", 251}, {"A1005", "Eggs", 1732},
				{"A1014", "Onions", 522}, {"A1031", "Garlic", 599},
				{"A1007", "Pepper", 672}, {"A1002", "Cheese", 93},
				{"A1022", "Sugar", 340}, {"A1011", "Salt", 600}};
	int i;
	for(i = 0; i < 10; i++){
		insert_bst(T, p[i]);
	}
}

//Given Functions
/************************************************************************
*	the non-recursive function will return a pointer to a				*
*	pointer to the node containing the given item ID. 					*
*	If the item is not found, the pointer returned points a pointer		*
*	variable with a value of NULL. 										*
*************************************************************************/
BST* findMemberPos(BST *B, char prod_ID[]){

}

/************************************************************************************
*	The non-recursive function deletes the node holding the product record with		*
*	the smallest product ID and returns the item record contained in the node.		*
*************************************************************************************/
prodType deleteMinProd(BST *T){
	
}

/****************************************************************************************
*	Given the BST and the item record, the function searches for the product			*
*	using findMemberPos(). If the record is found, the function decreases the 			*
*	item quantity of the record in BST by the quantity of the item given as 			*
*	parameter in the function, if the item quantity in the BST is larger than the		*
*	latter quantity. Otherwise, the item record shall be removed from the inventory. 	*
*	Invoke functiondeleteMinProd() whenever necessary. 									*
*****************************************************************************************/
void decreaseInventory(BST *T, prodType item, int threshold){

}

//Util Function
void pre_order(BST T){
	if(T != NULL){
		printf("%-2s |", T->prod.prod_ID);
		printf("%-12s |", T->prod.prod_name);
		printf("%d\n", T->prod.qty_remaining);
		pre_order(T->LChild);
		pre_order(T->RChild);
	}
}

int main(){
	BST T = NULL;
	
	prodType p = {"A1006", "Fish", 266};
	
	//Display
	populate_prod(&T);
	printf("%-2s %8s %10s\n", "[ID]", "[PNAME]", "[PQ]");
	printf("===========================\n");

	//Call findMemberPos()
	pre_order(T); printf("\n\n"); system("pause"); system("cls"); 
	
	printf("[Delete Min:]\n");
	//Call deleteMinProd()
	pre_order(T); printf("\n\n"); system("pause"); system("cls"); 
	
	printf("[Decrease Inv:]\n");
	//Call decreaseInventory();
	pre_order(T); printf("\n\n"); system("pause"); system("cls");
	
	return 0;
}
