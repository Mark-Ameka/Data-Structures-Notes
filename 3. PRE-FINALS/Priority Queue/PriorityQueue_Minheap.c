//Minheap
/*
	Formula:
	Left 	= (P*2)+1
	Right 	= (P*2)+2			Alternatives: LC+1 / (P*2+1)+1
	
	Parent  = (child-1)/2
*/

#include <stdio.h>
#include <stdlib.h>
#define SIZE 15

typedef int Info[SIZE];
typedef struct{
    int data[SIZE];
    int lastNdx;
}Heap;

void initializeHeap(Heap *H);
void insert(Heap *H, int num);

int deleteMin(Heap *H);				//O(logn)
void minHeapify(Heap *H);			//O(n)

int is_minheap(Heap H);
void heapSort(Heap *H);				//O(2nlogn) - O(nlogn)
void display(Heap H);

int main(){
    Heap H;
    Info x = {20, 5, 9, 8, 6, 9, 10, 10, 18, 9};
    int i, len = 10, toFind;
    
    initializeHeap(&H);
    
    for(i = 0; i < len; i++) insert(&H, x[i]);
	
    printf("\nHeapsort:\n"); heapSort(&H); display(H);
    
    minHeapify(&H);
    printf("\n%s", is_minheap(H) == 1 ? "array is in minheap" : "array is not in minheap");
	
    return 0;
}

void initializeHeap(Heap *H){
    H->lastNdx = -1;
}

void insert(Heap *H, int num){
    int childndx = 0, parentndx = 0;
	
    if (H->lastNdx < SIZE-1){
        H->lastNdx++;
        childndx = H->lastNdx;
        parentndx = (childndx-1)/2;

        while (childndx > 0 && H->data[parentndx] > num){
            H->data[childndx] = H->data[parentndx];
            childndx = parentndx;
            parentndx = (childndx-1)/2;
        }
        H->data[childndx] = num;
    }
}

int deleteMin(Heap *H){
    int min, parent, child, swap;
	
	//Get the root
    min = H->data[0];
    H->data[0] = H->data[H->lastNdx--];
    parent = 0;
    child = (parent*2)+1;

    while(child <= H->lastNdx){
		//Identify the greater ? right or left
        if(child+1 <= H->lastNdx && H->data[child+1] < H->data[child]){
			//child + 1 is right and child is left
            child++;
        }

		//Swapping time
        if(H->data[parent] > H->data[child]){
            swap = H->data[parent];
            H->data[parent] = H->data[child];
            H->data[child] = swap;
            //moving parent
            parent = child;
            //moving child to Info left of current parent
            child = (parent*2)+1;
        } else{
            child = H->lastNdx+1;
        }
    }
    return min;
}

void minHeapify(Heap *H){
	int lowPar, down, child, swap;
	
	if(H->lastNdx != -1){
		lowPar = (H->lastNdx-1)/2;
		while(lowPar >= 0){
			down = lowPar;
			child = (down*2)+1;

			while(child <= H->lastNdx){
				if(child+1 <= H->lastNdx && H->data[child] > H->data[child+1]){
					child++;
				}
				if(H->data[down] > H->data[child]){
					swap = H->data[down];
					H->data[down] = H->data[child];
					H->data[child] = swap;
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

int is_minheap(Heap H){
	int parent;
	
	//root to last interval node
	int child = 0, flag = 1;
	for(parent = 0; parent < (H.lastNdx-1)/2; parent++){
		child = (parent*2)+1;
		// If left child is greater than its parent then return false
		if (H.data[child] < H.data[parent]){
			flag = 0;
			break;			
		}
		// If right child is greater its parent then return false
		if(child+1 <= H.lastNdx && H.data[child+1] < H.data[parent]){
			flag = 0;
			break;			
		}
	}
	
	/*
	*			Given min-heap : 
	*		
	*		       10 - root is the minimum element
	*		      /  \
	*		     15   30
	*		    /  \  /  \		
	*		   40  50 100 40 - There is no condition where child is greater than its parent, So it is a min-heap.
	*/
	
	return flag;
}

void heapSort(Heap *H){

    int i, oldLast, min;

	/*
	    // call insert function to populate the heap//
	    for(i = 0; i < H->lastNdx; i++){
	    	insert(H, H->data[i]);
		}
	*/
	minHeapify(H);

    oldLast = H->lastNdx;
    while (H->lastNdx != -1){
        min = deleteMin(H);
        H->data[H->lastNdx+1] = min;
    }
    H->lastNdx = oldLast;
}

void display(Heap H){
    int x;
    for (x = 0; x < H.lastNdx+1; x++){
        printf("[%d]\t", H.data[x]);
    }
    printf("\n");
    for (x = 0; x < H.lastNdx+1; x++){
        printf(" %d\t", x);
    }
    printf("\nLast Index: %d\n", H.lastNdx);
}
