#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 10
#define STR_MAX 30
#define Type int

typedef char String[STR_MAX];
typedef struct{
	String fname, mname, lname;
	Type age;
}People;

typedef struct AL{
	People *info;				//Dynamic Array
	Type count;
}*ArrayList;					//Dynamic ArrayList Structure

typedef struct pnode{
	People info;
	struct pnode *next_p;
}PNode, *PList;					//Linked List Structure

typedef struct{
	ArrayList minor;
	PList non_minor;
}ComboList;

/*
	This function will just initialize ArrayList and LinkedList inside ComboList respectively.
	> If allocation is successful, return a string containing this value: "8SHHX7"
	> otherwise if allocation fails, return a string containing "XXXXX"
*/
char* init_combo(ComboList *L){
	char* ret_val = malloc(sizeof(char)*6);
	
	L->minor = calloc(1, sizeof(struct AL));
	if(L->minor != NULL){
		L->minor->info = malloc(sizeof(People)*MAX);
		L->minor->count = 0;
		if(L->minor->info != NULL){
			L->non_minor = NULL;
			strcpy(ret_val, "8SHHX7");
		}
	} else{
		strcpy(ret_val, "XXXXX");
	}
	
	return ret_val;
}

/*
	This function insert_people() will insert persons depending on their age:
	> If the person is a minor, insert in ArrayList (InsertLast: O(1))
	> otherwise, if the person is above minor age, insert in LinkedList (InsertLast: O(n))
*/
void insert_people(ComboList *L, People new_person){
	PList temp, *trav;
	if(new_person.age < 18){
		if(L->minor->count < MAX){
			L->minor->info[L->minor->count++] = new_person;
		}
	} else if(new_person.age > 18){
		for(trav = &L->non_minor; *trav != NULL; trav = &(*trav)->next_p){}
		if(*trav == NULL){
			*trav = malloc(sizeof(PNode));
			if(*trav != NULL){
				(*trav)->info = new_person;
				(*trav)->next_p = NULL;
			}
		}
	}
}

/*
	This function will populate people.
*/
void populate_people(ComboList *L){
	People info[MAX] = {{"Mark", "Dupio", "Mendoza", 21}, {"Stacy", "Greece", "Cruz", 14}, 
						{"Kia", "Lopez", "Simmons", 19}, {"Steven", "Zomez", "Ralf", 10}, 
						{"Bryan", "Inigo", "Ola", 13}, {"Jane", "Ola", "Azenya", 17}, 
						{"Kivian", "Kay", "Jillian", 14}, {"Steven", "Zomez", "Ralf", 34},
						{"Marie", "Lee", "Chang", 24}, {"Sofia", "Bray", "Sommi", 15}};
	int i;
	for(i = 0; i < MAX; i++){
		insert_people(L, info[i]);
	}
}

//Utility Function: This will only display the content fields.
void display_all(ComboList L){
	//ArrayList
	printf("Array List:\n");
	printf("%-15s|%-15s|%-15s|%-15s\n", "First Name", "Last Name", "Middle Initial", "Age");
	printf("==========================================================\n");
	int i;
	if(L.minor->count == 0){
		printf("List is Empty!\n");
	} else{
		for(i = 0; i < L.minor->count; i++){
			printf("%-15s|", L.minor->info[i].fname);
			printf("%-15s|", L.minor->info[i].lname);
			printf("%-15c|", L.minor->info[i].mname[0]);
			printf("%-15d", L.minor->info[i].age);
			printf("\n");
		}
		printf("\n\n");
	}
	
	//Linked List
	printf("Linked List:\n");
	printf("%-15s|%-15s|%-15s|%-15s\n", "First Name", "Last Name", "Middle Initial", "Age");
	printf("==========================================================\n");
	if(L.non_minor == NULL){
		printf("List is Empty!\n");
	} else{
		while(L.non_minor != NULL){
			printf("%-15s|", L.non_minor->info.fname);
			printf("%-15s|", L.non_minor->info.lname);
			printf("%-15c|", L.non_minor->info.mname[0]);
			printf("%-15d", L.non_minor->info.age);
			printf("\n");
			L.non_minor = L.non_minor->next_p;
		}
	}
}

int main(){
	ComboList L;
	
	// Given a ret_val pointer char, in order to call populate, 
	// > check if ret_val contains the string "8SHHX7"
	// > else exit(0) the program.
	char* ret_val = init_combo(&L);
	
	if(strcmp(ret_val, "8SHHX7") == 0){
		populate_people(&L);
	} else{
		printf("Allocation unsuccessful!");
		exit(0);
	}
	display_all(L);
	return 0;
}

