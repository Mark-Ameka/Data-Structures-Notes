#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define max 100

/* Data structure Definition */
typedef struct {
  char ID[10];
  char FN[24], LN[16], MI; 
}nametype;

typedef struct node {
   nametype elem;
   struct node *link;
}*linkSet;  

typedef struct {
   nametype studs[max];
   int count;      /* # of  elements in the list or heap */
}arraySet, Heap;  /*Definition of a set and heap */ 

typedef struct cell {
  nametype stud;
  struct cell *LC, *RC;
}bstNode, *BST;

/* PROBLEMS with function Prototypes */
/*****************************************************************************************
 * Problem 1: Array Implementation and BST [ 25 pts]                                     *
 * Write the code of the function sortSetUsingBST(). The function will sort (in ascending*
 * according to ID) a given set of student records represented in memory using an array  *
 * implementation.  Sorting will be done by creating a BST of student records based on ID.*
 * Students records are continuously deleted from the BST from the smallest to the biggest*
 * until the BST becomes empty. Each student record that is deleted from the BST will be  *
 * put back into the given set using "insert last" technique. NOTE: NO other function is  *
 * created in this problem. Document major code fragments by writing  COMMENTS on the task*
 * each code fragment is supposed to do.                                                  *  
 ******************************************************************************************/
void displayArray(arraySet S);    /* Function is provided below */
arraySet populateArraySet();      /* Function is provided below */ 
void inorderBST(BST B);           /* Function is provided below */ 
void sortSetUsingBST(arraySet *A);

/*******************************************************************************************
 * Problem 2: Set to Priority Queue [25 pts]                                               *
 * Write the code of the function convertSetToPOT().  Given a set implemented using linked *
 * list, the function will convert the given set into a  heap (array representation of POT)*
 * of student records. The function will continuously insert a student record which is     *
 * deleted from the given set, into an initially empty heap until the given set is empty.  *
 * Heap is organized according to ID number. In addition, to make the insertion in the heap*
 * efficient, the new element is NOT swapped with the parent but rather, the parent node is*
 * shifted to the child's possible position. The root element of the heap will contain the *
 * student record with the biggest ID number. Newly created heap is returned to the calling*
 * function.                                                                               *  
 *******************************************************************************************/
linkSet populateLinkSet();         /* Function is provided below */ 
void displayLinkSet(linkSet S);
Heap convertSetToPOT(linkSet *A);

int main(){
	arraySet A;
	A = populateArraySet();
	displayArray(A);
	
	linkSet S;
	Heap H;
	
   /* Function Calls for Problem 1 */


   /* Function Calls for Problem 2 */


	return 0;
}

/************************************
 *Function Definition for Problem 1 *
 ************************************/
 
void displayArray(arraySet S){
	int x;
	printf("\n\nElements of the Array Set:: ");
	for(x = 0; x < S.count; x++){
		printf("\n%-10s", S.studs[x].ID);
		printf("%-12s", S.studs[x].FN);
		printf("%-5c", S.studs[x].MI);
		printf("%-16s", S.studs[x].LN);
	}
}

arraySet populateArraySet(){ 
	arraySet set = {{{"121010", "Jane", "Jumalon", 'J'}, {"121016", "Paul", "Perez", 'P'},
                    {"121005", "Elaine", "Englis", 'E'}, {"121008", "Holly", "Hernandez", 'H'},
					{"121001", "Abel", "Ang", 'A'}, {"121006", "Fe", "Flores", 'F'},
					{"121013", "Manny", "Mendoza", 'M'}, {"121007", "Gwen", "Go", 'G'},
					{"121019", "Susie", "Suson", 'S'}, {"121003", "Carl", "Conan", 'C'}}, 10};
							    
   return set;
}

void inorderBST(BST B){
	if (B != NULL){
		inorderBST(B->LC);
		printf("\n%-10s", B->stud.ID);
		printf("%-12s", B->stud.FN);
		printf("%-5c", B->stud.MI);
		printf("%-16s", B->stud.LN);
		inorderBST(B->RC);
	}
}

/************************************
 *Function Definition for Problem 2 *
 ************************************/
linkSet populateLinkSet(){
	arraySet set = {{{"121010", "Jane", "Jumalon", 'J'}, {"121016", "Paul", "Perez", 'P'},
                    {"121005", "Elaine", "Englis", 'E'}, {"121008", "Holly", "Hernandez", 'H'},
					{"121001", "Abel", "Ang", 'A'}, {"121006", "Fe", "Flores", 'F'},
					{"121013", "Manny", "Mendoza", 'M'}, {"121007", "Gwen", "Go", 'G'},
					{"121019", "Susie", "Suson", 'S'}, {"121003", "Carl", "Conan", 'C'}}, 10};

	linkSet L, *p;
	int x;
	
	p = &L;
	for(x = 0; x < set.count; x++){
		*p = (linkSet) malloc(sizeof(struct node));
		if (*p != NULL) {
			(*p)->elem = set.studs[x];
			p = &(*p)->link;
		}
	}
	*p = NULL;
	return L;
}

