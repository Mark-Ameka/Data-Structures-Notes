#include <stdio.h>
#define MAX 10
#define SET_MAX 5
#define EMPTY '-'
#define DELETED '='

typedef char Set[MAX];
typedef char Dictionary[MAX];

void init_dic(Dictionary D){
	int i;
	for(i = 0; i < MAX; i++){
		D[i] = EMPTY;
	}
}

int hash_val(char nval){
	return (nval)%MAX;
}

void insert_dic(Dictionary D, Set nval){
	int i, hash, loc;
	
	for(i = 0; i < SET_MAX; i++){
		hash = hash_val(nval[i]);
		for(loc = hash; D[loc] != EMPTY && D[loc] != DELETED; loc = (loc+1)%MAX){}
		D[loc] = nval[i];
	}
}

void delete_dic(Dictionary D, Set nval, int size){
	int i, hash, loc;
	
	for(i = 0; i < size; i++){
		hash = hash_val(nval[i]);
		if(D[i] == hash){
			D[i] = DELETED;
		} else{
			for(loc = hash; D[loc] != EMPTY && D[loc] != nval[i]; loc = (loc+1)%MAX){}
			D[loc] = DELETED;
		}
	}
}

void display_dic(Dictionary D){
	int i, sl = 0;
	int hash;
	int ctr = 0;
	float asl = 0;
	
	printf("%11s | %2s | %3s\n", "Value", "Hash", "SL");
	for(i = 0; i < MAX; i++){
		printf("D[%d]: ", i);
		if(D[i] == EMPTY){
			printf("%3c", EMPTY);
			printf("%7c", '.');
			printf("%7c", '.');
		} else if(D[i] == DELETED){
			printf("%3c", DELETED);
			printf("%7c", '.');
			printf("%7c", '.');
		} else{
			hash = hash_val(D[i]);
			sl += (i-hash)+1;
			asl += sl;
			ctr++;
			
			printf("%3c", D[i]);
			printf("%7d", hash);
			printf("%7d", sl);
		}
		printf("\n");
	}
	printf("Average SL: %.2f", (asl/ctr));
	printf("\n\n");
}

int main(){
	Dictionary D;
	Set insert = {'A', 'B', 'Z', 'M', 'G', 'Z', 'W', '@', 'U', 'S'};
	
	init_dic(D);
	
	//insert
	insert_dic(D, insert);
	display_dic(D);
	
	//delete
	delete_dic(D, (Set){'G', 'B'}, 2);
	display_dic(D);
	
	return 0;
}
