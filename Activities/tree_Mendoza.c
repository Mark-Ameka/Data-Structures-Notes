/************************************************************************************
*																					*
*	ABC Restaurant has a program which tracks the inventory of their menu			*
*	items using an internal binary search tree, organized by item_ID. 				*
*	See the data structure definition on the right.									*
*																					*
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

BST* findMemberPos(BST *B, char prod_ID[]){
	BST* ret_val = NULL, *trav, temp;
	
	for(trav = B; *trav != NULL && strcmp((*trav)->prod.prod_ID, prod_ID) != 0;){
		trav = strcmp((*trav)->prod.prod_ID, prod_ID) < 0 ? &(*trav)->RChild : &(*trav)->LChild;
	}
	if(*trav != NULL && strcmp((*trav)->prod.prod_ID, prod_ID) == 0){
		ret_val = trav;
	} else{
		ret_val = trav;
	}
		
	return ret_val;
}

prodType deleteMinProd(BST *T){
	prodType ret_val;
	BST *trav, temp;
	
	for(trav = T; *T != NULL && (*trav)->LChild != NULL; trav = &(*trav)->LChild){}
	temp = *trav;
	*trav = temp->RChild;
	ret_val = temp->prod;
	free(temp);

	return ret_val;
}

void decreaseInventory(BST *T, prodType item, int threshold){
	BST *val = findMemberPos(T, item.prod_ID);
	BST temp, *trav;
	if(*val){
		if((*val)->prod.qty_remaining > threshold){
			(*val)->prod.qty_remaining -= threshold;
		} else{
			if(*T != NULL){
				trav = val;
				temp = *trav;
				if((*val)->LChild == NULL){
					*val = (*val)->RChild;
				} else if((*val)->RChild == NULL){
					*val = (*val)->LChild;
				} else{
					for(trav = &(*val)->LChild; (*trav)->RChild != NULL; trav = &(*trav)->RChild){}
					temp->prod = (*trav)->prod;
					
					temp = *trav;
					*trav = temp->LChild;
				}
				free(temp);
			}
		}
	}
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
	
	populate_prod(&T);
	printf("%-2s %8s %10s\n", "[ID]", "[PNAME]", "[PQ]");
	printf("===========================\n");
	pre_order(T); printf("\n\n");

	BST *ret = findMemberPos(&T, "A1002");
	
	printf("[Delete Min:]\n");
	prodType prod = deleteMinProd(&T);
	pre_order(T); printf("\n\n");
	
	printf("[Decrease Inv:]\n");
	decreaseInventory(&T, p, 245);
	pre_order(T); printf("\n\n");
	return 0;
}
