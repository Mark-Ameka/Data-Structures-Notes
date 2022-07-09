#include <stdio.h>
#include <stdlib.h>
#define SIZE 8

typedef int SET[SIZE];

void createSET(SET S, SET data);
void insertSET(SET S, int pos);
void deleteSET(SET S, int pos);
SET *getUnion(SET A, SET B);
SET *getIntersect(SET A, SET B);
SET *getDifference(SET A, SET B);
void displaySET(SET A);

int main(){
	SET A = {0, 1, 0, 1, 1, 1, 0, 0};
	SET B = {1, 0, 0, 1, 0, 1, 1, 1};
	
	printf("SET A:\t"); displaySET(A);
	printf("SET B:\t"); displaySET(B);
	
	SET *U;
	U = getUnion(A, B);
	printf("\nSET U:\t"); displaySET(*U);
	
	SET *I;
	I = getIntersect(A, B);
	printf("SET I:\t"); displaySET(*I);
	
	SET *D;
	D = getIntersect(A, B);
	printf("SET D:\t"); displaySET(*D);
	
	return 0;
}

void createSET(SET S, SET data){
	int i;
	for(i = 0; i < SIZE; i++){
		S[data[i]] = 1;
	}
}

void insertSET(SET S, int pos){
	if(pos < SIZE){
		S[pos] |= 1; //S[pos] = S[pos] | 1;
	}
}

void deleteSET(SET S, int pos){
	if(pos < SIZE){
		S[pos] &= 0; //S[pos] = S[pos] & 0;
	}
}

SET *getUnion(SET A, SET B){
	SET *C = NULL;
	int i;
	
	C = malloc(sizeof(SET)*SIZE);
	if(C != NULL){
		for(i = 0; i < SIZE; i++){
			(*C)[i] = A[i] | B[i];
		}
	}
}

SET *getIntersect(SET A, SET B){
	SET *C = NULL;
	int i;
	
	C = malloc(sizeof(SET)*SIZE);
	if(C != NULL){
		for(i = 0; i < SIZE; i++){
			(*C)[i] = A[i] & B[i];
		}
	}
	
	return C;
}

SET *getDifference(SET A, SET B){
	SET *C = NULL;
	int i;
	
	C = malloc(sizeof(SET)*SIZE);
	if(C != NULL){
		for(i = 0; i < SIZE; i++){
			(*C)[i] = A[i] & ~B[i];
		}
	}
	
	return C;
}

void displaySET(SET A){
	int i;
	for(i = 0; i < SIZE; i++){
		printf("%-5d", A[i]);
	}
	printf("\n");
}
