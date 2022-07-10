// Closed Hashing (Progressive Overflow)
// -kind of like chaining implemented in cursorbased environment.
#include <stdio.h>
#include <string.h>
#include <windows.h>

// use id to mark as EMPTY or DELETED
#define SIZE 11
#define EMPTY 999
#define DELETED 1000
typedef char String[15];

typedef struct{
	int id;
	String color_name; // (use color_name as key) <- important
	String hex_value;	
	String complement[3]; // list of color_name
	int complement_count;	
}Color;

typedef struct {
	Color value;
	int next; 
}Node;

typedef struct {
	Node data[SIZE];
	int avail;
}Dictionary;

// initializes prime and synonyms
void init_Dict(Dictionary *D) {
	int indx;
	int LIM = SIZE-1;
	int HLF = SIZE/2;
	
	for(indx = 0; indx < SIZE; indx++){
		if(indx < HLF){
			D->data[indx].value.id = EMPTY;
			D->data[indx].next = EMPTY;
		} else{
			D->data[indx].next = indx+1;
		}
	}
	D->data[LIM].next = EMPTY;
	D->avail = HLF;
}

// key == color_name, feel free to create your own hashing algo.
int hash_func(String key) {
	int indx, retVal = 0;
	for(indx = 0; key[indx] != '\0'; indx++){
		retVal += key[indx];
	}
	return retVal%(SIZE/2);
}

// Given a set, inserts it all to the dictionary
void Set2Dict(Dictionary *D, Color SET[], int set_count) {
	int temp;
	int indx, x;
	
	for(x = 0; x < set_count; x++){
		indx = hash_func(SET[x].color_name);
		if(D->data[indx].value.id == EMPTY || D->data[indx].value.id == DELETED){
			D->data[indx].value = SET[x];
		} else{
			if(D->avail != EMPTY){
				temp = D->avail;
				D->avail = D->data[temp].next;
				D->data[temp].value = SET[x];
				D->data[temp].next = D->data[indx].next;
				D->data[indx].next = temp;
			}
		}
	}
}

// returns the index if it is a member, returns -1 if not 
int member(Dictionary D, String key) {
	int trav, indx = hash_func(key);
	
	if(D.data[indx].value.id == EMPTY){
		return indx;
	} else{
		for(trav = D.data[indx].next; trav != EMPTY && strcmp(D.data[trav].value.color_name, key) != 0; trav = D.data[trav].next){}
	}
	
	return (trav != EMPTY) ? trav : -1;
}

// helper functions
void visualize(Dictionary D) {
    int i, k;
	for (i = 0; i < SIZE/2; i++) {
        printf("i[%d]: ", i);
        for (k = i; k != EMPTY && D.data[k].value.id != EMPTY; k = D.data[k].next) {
            printf("|%2d %2d| ", D.data[k].value.id, D.data[k].next);
        }
        printf("\n");
    }
    printf("\n");
}

// complete all the other functions before trying this
void magic(Dictionary D, String key) {
    int index, complement;
    int i;
    index = member(D, key);
    if (index != -1) {
        HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

        SetConsoleTextAttribute(h, D.data[index].value.id);
        printf("%s", D.data[index].value.color_name);

        // print the complements
        for (i = 0; i < D.data[index].value.complement_count; i++) {
            SetConsoleTextAttribute(h, 15);
            printf(" --> ");
            complement = member(D, D.data[index].value.complement[i]);
            SetConsoleTextAttribute(h, D.data[complement].value.id);
            printf("%s", D.data[complement].value.color_name);
        }

        SetConsoleTextAttribute(h, 15);
    } else {
        printf("color not found\n");
    }
}

int main() {
	Dictionary D;
	
    // Given Data
    Color SET[7] = {
        {0, "black", "#000000", {""}, 0},
        {1, "blue", "#0000FF", {"red"}, 1},
        {2, "green", "#00FF00", {"red", "violet"}, 2},
        {4, "red", "#FF0000", {"blue", "green"}, 2},
        {5, "magenta", "#FF00FF", {"green"}, 1},
        {3, "cyan", "#00FFFF", {"yellow", "magenta"}, 2},
        {14, "yellow", "#FFFF00", {"blue"}, 1}
    };
    
    init_Dict(&D);
    Set2Dict(&D, SET, 7);
    visualize(D);
    magic(D, "yellow");
    

    return 0;
}
