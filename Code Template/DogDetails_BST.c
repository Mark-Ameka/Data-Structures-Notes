#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef char String[40];
typedef struct{
	String DogBreed;
	String DogColor;
	String DogHealth;
	int DogH, DogW;				//DogH = Dog Height : DogW = Dog Weight
	int DogLS;					//Dog Life Span
	String DogQ;				//Dog Quality
}DogDetails;

typedef struct node{
	DogDetails Info;
	struct node *next;
}NodeList, *NodeLink;

int main(){
	
	return 0;
}
