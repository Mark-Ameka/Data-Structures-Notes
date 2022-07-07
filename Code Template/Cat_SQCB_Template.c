#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define H_MAX 20
#define Type int

typedef char String[40];
typedef struct{
	String catBreed;
	String catColor;
	Type cat_W;				//Cat Weight
	Type cat_LS;			//Cat Life Span
}CatDetails;

typedef struct CC{
	CatDetails Info;
	Type nextCat;
}NodeCat;

typedef struct{
	NodeCat *Data;			//Dynamic Array with H_MAX size
	Type catAvail;
}*CatHeap;					//Dynamic Structure

typedef struct{
	Type FC;
	Type RC;
}CQueue;					//Queue Structure

typedef Type CStack;		//Stack Head
typedef Type CatHead;		//Heap Head

void initEverything(){
	//Code here...
}

void InsertCat(CatHeap *C, CatHead *H, CatDetails newCat){
	//Code here...
}

void populateCats(CatHeap *C, CatHead *H){
	CatDetails Cats[H_MAX/2] = {{"Abyssinian", "Fawn", 10, 15}, {"Ragamuffin", "Cream", 20, 13}, 
								{"Maine Coon", "Tabby", 15, 13}, {"Norwegian Forest", "Silver", 16, 16},
								{"Pixiebob", "Tabby", 17, 14}, {"Manx", "Black", 13, 14},
								{"Turkish Van", "tortoiseshell", 20, 10}, {"Japanese Bobtail", "White", 10, 12},
								{"Scottish Fold", "Brown", 13, 15}, {"LaPerm", "Chocolate", 10, 10}};
	int i;					
	for(i = 0; i < HMAX/2; i++){
		//Call here...
	}
}

/*
	biggerWeight returns a Stack containing data which weights' greater than the threshold
	and delete and move the elements in the pointer C to the Stack.
	Note: The Stack and pointer C shares THE SAME Heap.
*/
CStack biggerWeight(CatHeap *C, CatHead *H, Type threshold){ //Threshold: 13
	//Code here...
}

/*
	lesserLS function will move all elements containing lesser Cat Life Span (lesser than the threshold).
	Function will delete and move all the elements from *C into the Queue
*/
void lesserLS(CQueue *CQ, CatHeap *C, CatHead *H, Type threshold){ //Threshold: 14
	//Code here...
}

int main(){
	
	
	
	return 0;
}
