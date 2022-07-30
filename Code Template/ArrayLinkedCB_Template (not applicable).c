/*
	Data Structures and Algorithm:
		ArrayList, LinkedList, Cursor-Based Implementation
		July 28, 2022
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 0xA
#define STRING_SIZE 0x1E

typedef char String[STRING_SIZE];
typedef struct{
	String prodID;
	String prodName;
	float price;
	int stocks;
}Product;

//AL
typedef struct AA{
	Product *DataPAA;		//Dynamic Array containing 10 Items
	int prodCount;
}*ProdArrayList;			//Dynamic ArrayList Structure

//LL
typedef struct P{
	Product *prodInfo;
	ProdArrayList ProdAAList; //ArrayList Structure
	struct P *nextProdList;
}PNode, *PList;

//CB
typedef struct PLL{
	PList *ProdLL;			//Linked List Structure
	int nextProdHeap;
}NodeProd;

typedef struct{
	NodeProd *ProdHeap; 	//Dynamic Array containing 10 Items
	int availProduct;
}*VHeapProd;				//Dynamic CB Structure

typedef int headList;

void initProdHeap(VHeapProd *VSP, headList *HP){
	//Code here...
}

PList initProdList(){ //Return NULL if allocating is unsuccessful
	//Code here...
}

ProdArrayList initProdAList(){
	//Code here...
}

void insertSortedUnique(VHeapProd *VSP, headList *HP, Product newProd){
	//Code here...
}
void populateProducts(VHeapProd *VSP, headList *HP){
	Product prod[MAX] = {{"1001", "Fish", 98.23, 90}, {"1002", "Meat", 154.92, 10},
					    {"1003", "Steak", 293.22, 25}, {"1004", "Kimchi", 200.24, 555},
					    {"1005", "Butter", 50.23, 445}, {"1006", "Shrimp", 353.77, 75},
					    {"1007", "Salad", 60.66, 30}, {"1008", "Apple", 105.27, 48},
					    {"1009", "Banana", 133.52, 205}, {"1010", "Hotdogs", 112.32, 295}};
					    
	int i;
	for(i = 0; i < MAX; i++){
		//InsertSortedUnique function here...
	}
}

//Move product containing stocks less than the threshold to the ArrayList and return the number of items passed.
//NOTE: Insert in a constant time O(1)
int moveProductContaining(VHeapProd *VSP, headList *HP, int threshold){
	//Code here...
}

void displayProdFunc(VHeapProd VSP, headList HP){
	//Code here...
	printf("%15s%20s%15s\n", "PRODUCT ID", "PRODUCT NAME", "STOCKS");
	printf("----------------------------------------------------------\n");
}

int main(){
	//Call here...
	return 0;
}
