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
	int i;
	char *string = malloc(sizeof(char)*6);
	strcpy(string, "xxxxx");
	
	*A = calloc(1, sizeof(struct AA));
	if(*A != NULL){
		(*A)->c_elem = malloc(sizeof(CatDetails)*MAX);
		*CC = calloc(1, sizeof(struct CH));
		if(*CC != NULL){
			for(i = 0; i < MAX; i++){
				strcpy((*CC)->c_data[i].catColor, EMPTY);
				C[i] = NULL;
			}
			strcpy(string, "0S99XJ");
		}
	}
	
	return string;
}

/*
	This function will add a new cat into the ArrayList if there is an available space to insert.
	NOTE: Insert all data at last O(1)
*/
void insert_to_array(ArrayList *A, CatDetails new_cat){
	if((*A)->ctr < MAX){
		(*A)->c_elem[(*A)->ctr] = new_cat;
		(*A)->ctr++;
	}
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
		insert_to_array(A, Cats[i]);
	}
}

/*
	hash function will sum up the ASCII values given in the parameter and multiply it
	by 8.
	Note: Return the hash value using modulo to MAX
*/
int cat_hash(String catColor){
	int i, sum = 0;
	for(i = 0; catColor[i] != '\0'; i++){
		sum += catColor[i];
	}
	return (sum*8)%MAX;
}

/*
	This function will transfer all cats in the ArrayList containing cat weight lesser than the
	threshold and remove the data after insertion.
*/
void insert_to_oh(Dictionary C, ArrayList *A, Type threshold){ //Threshold value will be given as: 16
	int i, j = 0, hash, new_ctr = (*A)->ctr;
	NodeCat *trav;
	
	for(i = 0; i < new_ctr; i++){
		if((*A)->c_elem[i].cat_W < threshold){
			hash = cat_hash((*A)->c_elem[i].catColor);
			for(trav = &C[hash]; *trav != NULL && strcmp((*trav)->cat_data.catBreed, (*A)->c_elem[i].catBreed) != 0; trav = &(*trav)->n_cat){}
			if(*trav == NULL){
				*trav = malloc(sizeof(NodeList));
				if(*trav != NULL){
					(*trav)->cat_data = (*A)->c_elem[i];
					(*trav)->n_cat = NULL;
				}
				for(j = i; j < i; j++){
					(*A)->c_elem[j] = (*A)->c_elem[j+1];
				}
				(*A)->ctr--;
			}
		}
	}
}

/*
	This function wiil transfer all cats from the OPEN HASH DICTIONARY to the CLOSED CIRCULAR
	and remove all contents from the open hash dictionary. After moving all the contents,
	transfer also all the data from the ArrayList and remove all its content.
	
	Return a boolean expression to determine if there has been a collision from insertion.
	if it's perfect hashing return true, otherwise false
*/
bool insert_to_circular(ClosedCircular *CC, Dictionary C, ArrayList *A){
	bool x = false;
	int i, hash, loc, new_ctr = (*A)->ctr;
	NodeCat temp, *trav;
	
	for(i = 0; i < MAX; i++){
		for(trav = &C[i]; *trav != NULL;){
			if(trav != NULL){
				hash = cat_hash((*trav)->cat_data.catColor);
			
				if(strcmp((*CC)->c_data[hash].catColor, (*trav)->cat_data.catColor) == 0){
					(*CC)->c_data[hash] = (*trav)->cat_data;
				} else{
					for(loc = (hash+1)%MAX; strcmp((*CC)->c_data[loc].catColor, EMPTY) != 0 && 
												strcmp((*CC)->c_data[loc].catColor, DELETED) != 0; loc = (loc+1)%MAX){
					}
					(*CC)->c_data[loc] = (*trav)->cat_data;
					(*CC)->cat_ctr++;
				}
				
				temp = *trav;
				*trav = temp->n_cat;
				free(temp);
			} else{
				trav = &(*trav)->n_cat;
			}
		}
	}
	
	for(i = new_ctr; i > 0; i--){
		hash = cat_hash((*A)->c_elem[i].catColor);
		if(strcmp((*CC)->c_data[hash].catColor, (*A)->c_elem[i].catColor) == 0){
			(*CC)->c_data[hash] = (*A)->c_elem[i];
		} else{
			for(loc = (hash+1)%MAX; strcmp((*CC)->c_data[loc].catColor, EMPTY) != 0 && 
									strcmp((*CC)->c_data[loc].catColor, DELETED) != 0; loc = (loc+1)%MAX){}
			(*CC)->c_data[loc] = (*A)->c_elem[i];
			(*CC)->cat_ctr++;
		}
		(*A)->ctr--;
	}
	
	return x;
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
	Dictionary C;
	ClosedCircular CC;
	ArrayList AA;
	
	char *retString = init_all(&CC, C, &AA);
	
	if(strcmp(retString, "0S99XJ") == 0){
		populateCats(&AA);
		display_contents(CC, C, AA);
		
		insert_to_oh(C, &AA, 16);
		display_contents(CC, C, AA);
		
		insert_to_circular(&CC, C, &AA);
		display_contents(CC, C, AA);
		
	} else{
		printf("Initializing Error!\n");
		exit(0);
	}
	
	return 0;
}
