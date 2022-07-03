#include <stdio.h>
#include <windows.h>
#define SIZE 10

#define EMPTY -1
#define DELETED 0

typedef char SET[SIZE];
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

void insertDictionary(Dictionary *D, char newVal){
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

int hashValue(int num){
	return num%SIZE;
}

void displayDictionary(Dictionary D){
	int i;
	int HLF = SIZE/2;
	
	for(i = 0; i < SIZE; i++){
		if(i < HLF){
			printf("\n[%d] == Elem: %-2c%3c%3c  Link: [%d]", i, 174, D.HTable[i], 175, D.HTable[i].next);
			printf("\t\t[%d] == Elem: %-2c%3c%3c  Link: [%d]\n", i+HLF, 174, D.HTable[i+HLF], 175, D.HTable[i+HLF].next);
		}
	}
	printf("\nAvail: %d\n\n", D.avail);
	
	//to get the search length: (index + 1) - hash value
	//to get the average search length: divide it to the search length of all elements
	
	system("pause");
	system("cls");
}

int main(){
	SET data = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
	Dictionary D;
	initDictionary(&D);
	int i;
	
	printf("Visualization:\n");
	displayDictionary(D);
	
	printf("Insertion:\n");
	for(i = 0; i < SIZE; i++) insertDictionary(&D, data[i]);
	displayDictionary(D);
	
	return 0;
}
