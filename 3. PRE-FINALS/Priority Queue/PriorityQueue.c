#include <stdio.h>
#include <stdlib.h>
#define SIZE 15

typedef int SET[SIZE];
typedef struct{
    int Elem[SIZE];
    int lastNdx;
}Heap;

void initializeHeap(Heap *H);
void insert(Heap *H, int num);
int deleteMin(Heap *H);
int deleteMax(Heap *H);
void maxHeapify(Heap *H);
void heapSort(Heap *H);
void display(Heap H);

int main(){
    Heap H;
    SET x = {20, 5, 9, 8, 6, 9, 10, 10, 18, 9};
    int i, len = 10, toFind;
    
    initializeHeap(&H);
    
    for(i = 0; i < len; i++) insert(&H, x[i]);
    display(H);
	
	printf("\nInsert (2):\n"); insert(&H, 2); display(H);
    printf("\nInsert (3):\n"); insert(&H, 3); display(H);
    printf("\nHeapsort:\n"); heapSort(&H); display(H);
    printf("\nMax Heapify:\n"); maxHeapify(&H); display(H);
    
    printf("\nBinary Search:\n");
    toFind = 100;
	printf("%d %s", toFind,(binarySearch(H, toFind) == 1) ? "is found." : "is not found");
	
    return 0;
}

void initializeHeap(Heap *H){
    H->lastNdx = -1;
}

void insert(Heap *H, int num){
    int childndx = 0, parentndx = 0;
	
    if (H->lastNdx < SIZE - 1){
        H->lastNdx++;
        childndx = H->lastNdx;
        parentndx = (childndx - 1) / 2;

        while (childndx > 0 && H->Elem[parentndx] > num){
            H->Elem[childndx] = H->Elem[parentndx];
            childndx = parentndx;
            parentndx = (childndx - 1) / 2;
        }
        H->Elem[childndx] = num;
    }
}

int deleteMin(Heap *H){
    int min, parent, child, swap;
	
	//Get the root
    min = H->Elem[0];
    H->Elem[0] = H->Elem[H->lastNdx--];
    parent = 0;
    child = (parent * 2) + 1;

    while(child <= H->lastNdx){
		//Identify the greater ? right or left
        if(child + 1 <= H->lastNdx && H->Elem[child + 1] < H->Elem[child]){
			//child + 1 is right and child is left
            child++;
        }

		//Swapping time
        if(H->Elem[parent] > H->Elem[child]){
            swap = H->Elem[parent];
            H->Elem[parent] = H->Elem[child];
            H->Elem[child] = swap;
            //moving parent
            parent = child;
            //moving child to set left of current parent
            child = parent * 2 + 1;
        } else{
            child = H->lastNdx + 1;
        }
    }
    return min;
}

int deleteMax(Heap *H){
	int min, parent, child, swap;
	
	//Get the root
    min = H->Elem[0];
    H->Elem[0] = H->Elem[H->lastNdx--];
    parent = 0;
    child = (parent*2) + 1;

    while(child <= H->lastNdx){
		//Identify the greater ? right or left
        if(child + 1 <= H->lastNdx && H->Elem[child + 1] > H->Elem[child]){
			//child + 1 is right and child is left
            child++;
        }

		//Swapping time
        if(H->Elem[parent] < H->Elem[child]){
            swap = H->Elem[parent];
            H->Elem[parent] = H->Elem[child];
            H->Elem[child] = swap;
            //moving parent
            parent = child;
            //moving child to set left of current parent
            child = parent * 2 + 1;
        } else{
            child = H->lastNdx + 1;
        }
    }
    return min;
}

void maxHeapify(Heap *H){
	int lowPar, down, child, swap;
	
	if(H->lastNdx != -1){
		lowPar = (H->lastNdx-1)/2;
		while(lowPar >= 0){
			down = lowPar;
			child = (down*2)+1;

			while(child <= H->lastNdx){
				if(child+1 <= H->lastNdx && H->Elem[child+1] > H->Elem[child]){
					child++;
				}
				if(H->Elem[down] < H->Elem[child]){
					swap = H->Elem[down];
					H->Elem[down] = H->Elem[child];
					H->Elem[child] = swap;
					down = child;
					child = (down*2)+1;
				} else{
					child = H->lastNdx+1;
				}
			}
			lowPar--;
		}
	}
}

void heapSort(Heap *H){

    int i, oldLast, min;

    // call insert function to populate the heap//
    for(i = 0; i < H->lastNdx; i++){
    	insert(H, H->Elem[i]);
	}

    oldLast = H->lastNdx;
    while (H->lastNdx != -1){
        min = deleteMin(H);
        H->Elem[H->lastNdx + 1] = min;
    }
    H->lastNdx = oldLast;
}

void display(Heap H){
    int x;
    for (x = 0; x <= H.lastNdx; x++){
        printf("[%d]\t", H.Elem[x]);
    }
    printf("\n");
    for (x = 0; x <= H.lastNdx; x++){
        printf(" %d\t", x);
    }
    printf("\nLast Index: %d\n", H.lastNdx);
}
