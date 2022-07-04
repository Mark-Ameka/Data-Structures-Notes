#include <stdio.h>
#include <stdlib.h>

#define MAX 10
#define EMPTY '-'
#define DELETED '!'

typedef struct{
	char elem;
	int hashV;
}Alpha;

typedef struct{
	Alpha data[MAX];
	int count;
}Dictionary;

void initDictionary(Dictionary *D);
void insertDictionary(Dictionary *D, Alpha newVal);
void displayDictionary(Dictionary D);
 

int main(){
	Alpha elem[8] = {{'A', 1}, {'B', 4}, {'C', 9}, {'D', 9}, {'E', 0}, {'F', 3}, {'G', 4}, {'H', 3}};
	Dictionary D;
	initDictionary(&D);
	int i;
	
	for(i = 0; i < 8; i++) insertDictionary(&D, elem[i]);
	displayDictionary(D);

	return 0;
}

void insertDictionary(Dictionary *D, Alpha newVal){
	int loc, hash;
	
	if(D->count < MAX){
		hash = newVal.hashV;
		if(D->data[hash].elem == EMPTY){
			D->data[hash] = newVal;
		} else{
			for(loc = (hash+1)%MAX; D->data[loc].elem != EMPTY && D->data[loc].elem != DELETED; loc = (loc+1)%MAX){}
			D->data[loc] = newVal;
			D->count++;
		}
	}
}

void initDictionary(Dictionary *D){
	int i;
	for(i = 0; i < MAX; i++){
		D->data[i].elem = EMPTY;
		D->data[i].hashV = -1;
	}
	D->count = 0;
}

void displayDictionary(Dictionary D){
	int i, sl = 0;
	printf("index:\tdata:\thash:\tsearch length:\n");
	for(i = 0; i < MAX; i++){
		//SL = (index+SIZE-hashValue+1)%SIZE
		/*
			since 9 man ang hash sa D, pero ni move man kausa adto sa index 0, so na 10, so ang D: 10-9+1 = 2
		*/
		if(D.data[i].elem == EMPTY){
			printf("[%d] =>\t", i);
			printf("%c ->\t", EMPTY);
			printf(" %d\t", -1);
			printf(" sl = %d\n", -1);
		} else{
			sl = ((i+MAX)-D.data[i].hashV+1)%MAX;
			
			printf("[%d] =>\t", i);
			printf("%c ->\t", D.data[i].elem);
			printf(" %d\t", D.data[i].hashV);
			printf(" sl = %d\n", sl);
		}
	}
	printf("\n\nCount: %d\n\n", D.count);
}
