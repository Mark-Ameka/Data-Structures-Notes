#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MAX 0xA
#define Type int

#define EMPTY "xxxxx"
#define DELETED "vvvvv"

typedef char String[40];
typedef struct{
	String catBreed;
	String catColor;
	Type cat_W;					//Cat Weight
	Type cat_LS;				//Cat Life Span
}CatDetails;

typedef struct AA{
	CatDetails *c_elem;			//Dynamic Array
	int ctr;	
}*ArrayList;					//Dynamic AL Structure

/*Closed Hashing: Circular*/
typedef struct CH{
	CatDetails c_data[MAX];
	int cat_ctr;
}*ClosedCircular;				//Dynamic CH Structure

/*Open Hashing: Chaining*/
typedef struct node{
	CatDetails cat_data;
	struct node *n_cat;
}NodeList, *NodeCat;

typedef NodeCat Dictionary[MAX];		//Dictionary Array

/*
	This function will initialize all the contents from all the implementation given.
	Return a string containing "0S99XJ" if there's no error for initializing.
	if there's an error, return a string containing "xxxxx"
*/
char* init_all(ClosedCircular *CC, Dictionary C, ArrayList *A){
	
}

/*
	This function will add a new cat into the ArrayList if there is an available space to insert.
	NOTE: Insert all data at last O(1)
*/
void insert_to_array(ArrayList *A, CatDetails new_cat){
	
}

/*
	This function will populate an array of Cats to store in the ArrayList 
*/
void populateCats(ArrayList *A){
	CatDetails Cats[MAX] = {{"Abyssinian", "Fawn", 10, 15}, {"Ragamuffin", "Cream", 20, 13}, 
							{"Maine Coon", "Tabby", 15, 13}, {"Norwegian Forest", "Silver", 16, 16},
							{"Pixiebob", "Tabby", 17, 14}, {"Manx", "Black", 13, 14},
							{"Turkish Van", "tortoiseshell", 20, 10}, {"Japanese Bobtail", "White", 10, 12},
							{"Scottish Fold", "Brown", 13, 15}, {"LaPerm", "Chocolate", 10, 10}};
	int i;					
	for(i = 0; i < MAX; i++){
		//Call here...
	}
}

/*
	hash function will sum up the ASCII values given in the parameter and multiply it
	by 8.
	Note: Return the hash value using modulo to MAX
*/
int cat_hash(String catColor){
	
}

/*
	This function will transfer all cats in the ArrayList containing cat weight lesser than the
	threshold and remove the data after insertion.
*/
void insert_to_oh(Dictionary C, ArrayList *A, Type threshold){ //Threshold value will be given as: 16'

}

/*
	This function wiil transfer all cats from the OPEN HASH DICTIONARY to the CLOSED CIRCULAR
	and remove all contents from the open hash dictionary. After moving all the contents,
	transfer also all the data from the ArrayList and remove all its content.
	
	Return a boolean expression to determine if there has been a collision from insertion.
	if it's perfect hashing return true, otherwise false
*/
bool insert_to_circular(ClosedCircular *CC, Dictionary C, ArrayList *A){
	
}

void display_contents(ClosedCircular CC, Dictionary C, ArrayList A){
	int i;
	NodeCat trav;
	
	printf("Dictionary:\n");
	printf("=========================================================\n");
	printf("%-2s %-17s %-16s %-15s %16s\n", "I", "[CAT BREED]", "[CAT COLOR]", "[CAT WEIGHT]", "[CAT LIFE SPAN]");
	for(i = 0; C[i] != NULL; i++){}
	if(i != 0){
		for(i = 0; i < MAX; i++){
			for(trav = C[i]; trav != NULL; trav = trav->n_cat){
				printf("%-2d |", i);
				printf("%-16s |", trav->cat_data.catBreed);
				printf("%-15s |", trav->cat_data.catColor);
				printf("%-15d |", trav->cat_data.cat_W);
				printf("%-15d", trav->cat_data.cat_LS);
				printf("\n");
			}
		}
	} else{
		printf("C is Empty\n\n");
	}
	
	printf("Closed Circular:\n");
	printf("=========================================================\n");
	printf("%-2s %-17s %-16s %-15s %16s\n", "I", "[CAT BREED]", "[CAT COLOR]", "[CAT WEIGHT]", "[CAT LIFE SPAN]");
	if(CC->cat_ctr != 0){
		for(i = 0; i < CC->cat_ctr; i++){
			printf("%-2d |", i);
			printf("%-16s |", CC->c_data[i].catBreed);
			printf("%-15s |", CC->c_data[i].catColor);
			printf("%-15d |", CC->c_data[i].cat_W);
			printf("%-15d", CC->c_data[i].cat_LS);
			printf("\n");
		}
	} else{
		printf("CC is Empty\n\n");
	}
	
	printf("ArrayList:\n");
	printf("=========================================================\n");
	printf("%-2s %-17s %-16s %-15s %16s\n", "I", "[CAT BREED]", "[CAT COLOR]", "[CAT WEIGHT]", "[CAT LIFE SPAN]");
	if(A->ctr != 0){
		for(i = 0; i < A->ctr; i++){
			printf("%-2d |", i);
			printf("%-16s |", A->c_elem[i].catBreed);
			printf("%-15s |", A->c_elem[i].catColor);
			printf("%-15d |", A->c_elem[i].cat_W);
			printf("%-15d", A->c_elem[i].cat_LS);
			printf("\n");
		}
	} else{
		printf("AL is Empty\n");
	}
	
	system("pause"); system("cls");
}

int main(){
	
	return 0;
}
