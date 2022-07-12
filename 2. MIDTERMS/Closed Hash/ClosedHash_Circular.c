#include <stdio.h>
#include <stdlib.h>

#define MAX 10
#define EMPTY -1
#define DELETED 0

typedef int DATA[6];
typedef struct{
	int data[MAX];
	int count;
}Dictionary;

void initDictionary(Dictionary *D);
void insertDictionary(Dictionary *D, int newVal);
void deleteDictionary(Dictionary *D, int newVal);
int hashValue(int newVal);
void displayDictionary(Dictionary D);

int main(){
	DATA elem = {31, 32, 33, 43, 39, 99};
	Dictionary D;
	initDictionary(&D);
	int i;
	
	for(i = 0; i < 6; i++) insertDictionary(&D, elem[i]);
	printf("curr:\t");
	for(i = 0; i < 6; i++){
		printf("%d\t", elem[i]);
	}
	printf("\n\n\n");
	displayDictionary(D);

	printf("Delete: [43]\n\n");
	deleteDictionary(&D, 43);
	displayDictionary(D);

	return 0;
}

int hashValue(int newVal){
	return newVal%10;
}

void insertDictionary(Dictionary *D, int newVal){
	int hash, i;
	if(D->count < MAX){
		hash = hashValue(newVal);
		if(D->data[hash] == newVal){
			D->data[hash] = newVal;
		} else{
			//using i variable if data collides newVal's hash value is added by 1
			/*
				DATA:   99      31      32      33      43      -1      -1      -1      -1      39
				INDEX:  [0]     [1]     [2]     [3]     [4]     [5]     [6]     [7]     [8]     [9]
				
					This table shows that 33 and 43 collides with their hash values '3'
					hash = hash + (the index) % MAX is just added by 1
					that's why 43 was inserted at index 4
					
				Other for loop for closed hashing circular:
				
				NOTE: hash is added by 1 since its current value has an element that stored.
				for(loc = (hash+1)%MAX; D->data[loc] != EMPTY && D->data[loc] != DELETED; loc = (loc+1)%MAX){}
			*/
			for(i = 1; D->data[hash] != EMPTY && D->data[hash] != DELETED; i++){
				hash = (hash+i)%MAX;
			}
			D->data[hash] = newVal;
			D->count++;
		}
	}
}

void deleteDictionary(Dictionary *D, int val){
	int hash, i;
	
	hash = hashValue(val);
	if(D->data[hash] == val){
		D->data[hash] = DELETED;
	} else{
		//using i variable if data collides newVal's hash value is added by 1
		/*
			Delete: [43]
			DATA:   99      31      32      33      -1      -1      -1      -1      -1      39
			INDEX:  [0]     [1]     [2]     [3]     [4]     [5]     [6]     [7]     [8]     [9]
			
				This table shows that deleting an element with the same hash value increments the hash value
				to determine that the [elem == val]
				the data[hash] gets the value of the data[count] which is -1
		*/
		for(i = 1; D->data[hash] != val; i++){
			hash = (hash+i)%MAX;
		}
		D->data[hash] = D->data[D->count];
		D->count--;
	}
}

void initDictionary(Dictionary *D){
	int i;
	for(i = 0; i < MAX; i++){
		D->data[i] = EMPTY;
	}
	D->count = 0;
}

void displayDictionary(Dictionary D){
	int i, sl = 0;
	float asl = 0;
	int hash;
	printf("DATA:\t");
	for(i = 0; i < MAX; i++){
		printf("%d\t", D.data[i]);
	}
	/*
		Search Length Formula V1:
		//SL = (index+1)-hashValue
		//SL = (index-hashValue)+1
		
		Search Length Formula V2:
		//SL = (index+SIZE-hashValue+1)%SIZE
	*/
	printf("\nINDEX:\t");
	for(i = 0; i < MAX; i++){
		printf("[%d]\t", i);
	}
	
	printf("\nSL:\t");
	for(i = 0; i < MAX; i++){
		if(D.data[i] != EMPTY){
			hash = hashValue(D.data[i]);
			sl = ((i+MAX)-hash+1)%MAX;
			asl += sl;
			printf("%d\t", sl);
		} else{
			printf("-2\t");
		}
	}
	printf("\n\nCount: %d\n", D.count);
	printf("Average SL: %.2f\n\n", asl/D.count);
}

int isMember(Dictionary D, int newVal){
	int hash, i;

	hash = hashValue(newVal);
	for(i = 1; D.data[hash] != EMPTY && D.data[hash] != newVal; i++){
		hash = (hash+i)%MAX;
	}
	
	return (D.data[hash] != EMPTY) ? newVal : -1;
}
