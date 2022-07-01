// Computer Word or Bit array is an implementation of Bit-Vector

// we used an integer to hold a boolean value 0 or 1
// an interger can be 4 bytes or 32 bits
// a char can be 1 byte or 8 bits
// however, 1 bit is enough to hold a boolean value

// in computer word we use a char datatype to store a set
// 1 char = 8 bits
// word size is 8
// boolean values (0,1)
// 2^8 = 256 or 0 - 255 values

#include <stdio.h>
#include <stdlib.h>
#define MAX 8

typedef char SET;

SET getUnion(SET A, SET B){
	return A|B;
}

SET getIntersect(SET A, SET B){
	return A&B;
}

SET getDifference(SET A, SET B){
	return A&~B;
}

void insertSET(SET *S, int val){
	if(val <= (sizeof(*S)*8)){
		*S = *S | (1 << val);
	}
}

void deleteSET(SET *S, int val){
	if(val <= (sizeof(*S)*8));
	*S = (*S) & ~(1 << val);
}

SET *setToBitVector(SET val){
	SET *S = malloc(sizeof(SET));
	int bits = (sizeof(val) * 8)-1; // (sizeof(val) << 3)-1
	unsigned int mask = 1 << bits;
	int i = 0;
	
	if(S != NULL){
		for(; mask > 0; mask >>= 1){
			S[i] = (mask & val) ? 1 : 0;
			i++;
		}
	}
	return S;
}

SET bitVectorToSet(SET *A){
	SET x = 0;
	int i = 0;
	int bits = (sizeof(*A) * 8)-1;
	printf("%d ", bits);
	unsigned int mask = 1 << bits;
	
	for(; mask > 0; mask >>= 1){
		if(A[i] == 1){
			x |= mask;
		}
		i++;
	}
	
	return x;
}

int numOfBits(SET x){
	int sum = 0;
	int bits = (sizeof(x) * 8)-1;
	unsigned int mask = 1 << bits;
	
	for(; mask > 0; mask >>= 1){
		sum += (mask & x) ? 1 : 0;
	}
	return sum;
}

void displayPlaceValue(SET A){
	int bits = (sizeof(A) * 8)-1;
	unsigned int mask;
	int x = 0;
	printf("{");
	for(mask = 1; x != MAX; mask <<= 1){
		if((A & mask) != 0){
			printf("%d, ", x);
		}
		x++;
	}
	printf("}");
	printf("\n");
}

void displaySET(SET A){
	int bits = (sizeof(A) * 8)-1;
	unsigned int mask = 1 << bits;
	int x = 0;

	for(; mask > 0; mask >>= 1){
		printf("%-5d", (mask & A) ? 1 : 0);
	}
	
	displayPlaceValue(A);
	
	printf("\n");
}

int main(){
	SET A = 10;
	SET B = 7;
	int i;
	
	printf("SET A:\t"); displaySET(A);
	printf("SET B:\t"); displaySET(B);

	SET U = getUnion(A, B);
	printf("\nSET U:\t"); displaySET(U);
	
	SET I = getIntersect(A, B);
	printf("SET I:\t"); displaySET(I);
	
	SET D = getDifference(A, B);
	printf("SET D:\t"); displaySET(D);
	
	SET *V = setToBitVector(A);
	printf("\nSet to Vector [A]:\t");
	for(i = 0; i < 8; i++){
		printf("%-5d", V[i]);
	}
	
	printf("\nVector to Set [V]:\t");
	SET S = bitVectorToSet(V);
	printf("%d", S);
	
	printf("\nNumber of Bits [B]:\t%d", numOfBits(A));
	
	return 0;
}
