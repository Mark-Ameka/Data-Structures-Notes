#include <stdio.h>
#include <windows.h>
#define SIZE 10

#define EMPTY -1
#define DELETED -2

typedef int SET[SIZE];
typedef struct{
	int elem;
	int next;
}Hash;

typedef struct{
	Hash HTable[SIZE];
	int avail;
}Dictionary;

void initDictionary(Dictionary *D){
	int i;
	int HLF = SIZE/2;
	for(i = 0; i < SIZE; i++){
		if(i < HLF){
			D->HTable[i].next = EMPTY;
		} else{
			D->HTable[i].next = i+1;
		}
		D->HTable[i].elem = EMPTY;
	}
	D->HTable[SIZE-1].next = EMPTY;
	D->avail = HLF;
}

void insertDictionary(Dictionary *D, int newVal){
	int temp;
	int hash = hashValue(newVal);
	
	if(D->HTable[hash].elem == EMPTY || D->HTable[hash].elem == DELETED){
		D->HTable[hash].elem = newVal;
	} else{
		temp = D->avail;
		D->avail = D->HTable[temp].next;
		if(temp != -1){
			D->HTable[temp].elem = newVal;
			D->HTable[temp].next = D->HTable[hash].next;
			D->HTable[hash].next = temp;
		}
	}
}

void deleteDictionary(Dictionary *D, int val){
	int temp, *trav;
	int hash = hashValue(val);
	
	if(D->HTable[hash].elem == val){
		D->HTable[hash].elem = DELETED;
	} else{
		for(trav = &D->HTable[hash].next; *trav != -1 && D->HTable[*trav].elem != val; trav = &D->HTable[hash].next){}
		if(*trav != -1){
			temp = *trav;
			*trav = D->HTable[temp].next;
			D->HTable[temp].next = D->avail;
			D->avail = D->HTable[temp].next;
		}
	}
}

int hashValue(int num){
	return num%SIZE;
}

void displayDictionary(Dictionary D){
	int i;
	int HLF = SIZE/2;
	
	for(i = 0; i < SIZE; i++){
		if(i < HLF){
			printf("\n[%d] == Elem: %-2c%3d%3c  Link: [%d]", i, 174, D.HTable[i], 175, D.HTable[i].next);
			printf("\t\t[%d] == Elem: %-2c%3d%3c  Link: [%d]\n", i+HLF, 174, D.HTable[i+HLF], 175, D.HTable[i+HLF].next);
		}
	}
	printf("\nAvail: %d\n\n", D.avail);
	
	//to get the search length: (index + 1) - hash value
	//to get the average search length: divide it to the search length of all elements
	
	system("pause");
	system("cls");
}

int main(){
	SET data = {99, 25, 16, 63, 75, 43, 72, 78, 45, 10};
	Dictionary D;
	initDictionary(&D);
	int i;
	
	printf("Visualization:\n");
	displayDictionary(D);
	
	printf("Insertion:\n");
	for(i = 0; i < SIZE; i++) insertDictionary(&D, data[i]);
	displayDictionary(D);
	
	printf("Delete: [75]\n");
	deleteDictionary(&D, 75);
	displayDictionary(D);
	
	return 0;
}
