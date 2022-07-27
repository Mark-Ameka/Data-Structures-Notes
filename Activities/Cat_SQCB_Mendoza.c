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
	Type FC;			//Default value: -1
	Type RC;			//Default value: -1
}CQueue;					//Queue Structure

typedef struct{
	CatHeap CH;
	Type StackHead;		//Stack Head	Default value: -1
	Type MainHead;		//Heap Head		Default value: -1
	CQueue Q;			//Queue Head
}VirtualMain;

void init_everything(VirtualMain *VH){
	//Main Heap
	VH->MainHead = -1;
	
	//Stack Heap
	VH->StackHead = -1;
	
	VH->CH = calloc(1, sizeof(struct CC));
	if(VH->CH != NULL){
		(VH->CH)->Data = malloc(sizeof(NodeCat)*H_MAX);
		int i;
		for(i = H_MAX-1; i >= 0; i--){
			strcpy((VH->CH)->Data[i].Info.catBreed, "xxxxx");
			(VH->CH)->Data[i].nextCat = i-1;
		}
		(VH->CH)->catAvail = H_MAX-1;
	}
	
	//Queue Heap
	(VH->Q).FC = -1;
	(VH->Q).RC = -1;
}

/*
	function inserts cat into the main virtual head at first.
*/
void insert_cat(VirtualMain *VH, CatDetails newCat){
	Type temp = (VH->CH)->catAvail;
	
	if(temp != -1){
		(VH->CH)->catAvail = (VH->CH)->Data[temp].nextCat;
		
		(VH->CH)->Data[temp].Info = newCat;
		(VH->CH)->Data[temp].nextCat = VH->MainHead;
		VH->MainHead = temp;
	}
}

/*
	function populates cat information into the main virtual heap.
*/
void populateCats(VirtualMain *VH){
	CatDetails Cats[H_MAX/2] = {{"Abyssinian", "Fawn", 10, 15}, {"Ragamuffin", "Cream", 20, 13}, 
								{"Maine Coon", "Tabby", 15, 13}, {"Norwegian Forest", "Silver", 16, 16},
								{"Pixiebob", "Tabby", 17, 14}, {"Manx", "Black", 13, 14},
								{"Turkish Van", "tortoiseshell", 20, 10}, {"Japanese Bobtail", "White", 10, 12},
								{"Scottish Fold", "Brown", 13, 15}, {"LaPerm", "Chocolate", 10, 10}};
	int i;					
	for(i = 0; i < H_MAX/2; i++){
		insert_cat(VH, Cats[i]);
	}
}

/*
	bigger_weight returns a Stack containing data which weights' greater than the threshold
	and delete and move the elements in the MainHead to the StackHead.
	Note: StachHead and MainHead shares THE SAME Heap.
*/
Type bigger_weight(VirtualMain *VH, Type threshold){ //Threshold: 13
	Type ret_stack = VH->StackHead;
	Type temp, *trav;
	
	for(trav = &VH->MainHead; *trav != -1;){
		if(VH->CH->Data[*trav].Info.cat_W > threshold){
			temp = (VH->CH)->catAvail;
			(VH->CH)->catAvail = (VH->CH)->Data[temp].nextCat;
			
			if(temp != -1){
				(VH->CH)->Data[temp].Info = (VH->CH)->Data[*trav].Info;
				(VH->CH)->Data[temp].nextCat = ret_stack;
				ret_stack = temp;
			}
			
			temp = *trav;
			*trav = (VH->CH)->Data[temp].nextCat;
			(VH->CH)->Data[temp].nextCat = (VH->CH)->catAvail;
			(VH->CH)->catAvail = temp;
		} else{
			trav = &(VH->CH)->Data[*trav].nextCat;
		}
	}
	return ret_stack;
}

/*
	lesser_ls function will move all elements containing lesser Cat Life Span (lesser than the threshold).
	Function will delete and move all the elements from the stack and main into the Queue RESPECTIVELY.
	NOTE: Insert at first for lesser run time.
*/
void lesser_ls(VirtualMain *VH, Type threshold){ //Threshold: 14
	Type temp;
	Type *trav_s, *trav_m;
	
	for(trav_s = &VH->StackHead; *trav_s != -1;){
		if((VH->CH)->Data[*trav_s].Info.cat_LS < threshold){
			temp = (VH->CH)->catAvail;
			(VH->CH)->catAvail = (VH->CH)->Data[temp].nextCat;
			
			if(temp != -1){
				(VH->CH)->Data[temp].Info = (VH->CH)->Data[*trav_s].Info;
				(VH->CH)->Data[temp].nextCat = -1;
				if(VH->Q.FC == -1){
					VH->Q.FC = temp;
				} else{
					(VH->CH)->Data[VH->Q.RC].nextCat = temp;
				}
				VH->Q.RC = temp;
			}
			
			temp = *trav_s;
			*trav_s = (VH->CH)->Data[temp].nextCat;
			(VH->CH)->Data[temp].nextCat = (VH->CH)->catAvail;
			(VH->CH)->catAvail = temp;
		} else{
			trav_s = &(VH->CH)->Data[*trav_s].nextCat;
		}
	}
	
	for(trav_m = &VH->MainHead; *trav_m != -1;){
		if((VH->CH)->Data[*trav_m].Info.cat_LS < threshold){
			temp = (VH->CH)->catAvail;
			(VH->CH)->catAvail = (VH->CH)->Data[temp].nextCat;
			
			if(temp != -1){
				(VH->CH)->Data[temp].Info = (VH->CH)->Data[*trav_m].Info;
				(VH->CH)->Data[temp].nextCat = -1;
				if(VH->Q.FC == -1){
					VH->Q.FC = temp;
				} else{
					(VH->CH)->Data[VH->Q.RC].nextCat = temp;
				}
				VH->Q.RC = temp;
			}
			
			temp = *trav_m;
			*trav_m = (VH->CH)->Data[temp].nextCat;
			(VH->CH)->Data[temp].nextCat = (VH->CH)->catAvail;
			(VH->CH)->catAvail = temp;
		} else{
			trav_m = &(VH->CH)->Data[*trav_m].nextCat;
		}
	}
}

//Display Function
void display_cats(VirtualMain VH){
	printf("[Main]:\n");
	int trav_m;
	printf("%2s %18s %15s %15s %15s\n", "Index", "Cat Breed", "Cat Color", "Cat W", "Cat LS");
	printf("-----------------------------------------------------------------\n");
	for(trav_m = VH.MainHead; trav_m != -1; trav_m = VH.CH->Data[trav_m].nextCat){
		printf("%2d|", trav_m);
		printf("%18s|", VH.CH->Data[trav_m].Info.catBreed);
		printf("%15s|", VH.CH->Data[trav_m].Info.catColor);
		printf("%15d|", VH.CH->Data[trav_m].Info.cat_W);
		printf("%15d\n", VH.CH->Data[trav_m].Info.cat_LS);
	}
	
	printf("\n\n[Stack]:\n");
	int trav_s;
	printf("%2s %18s %15s %15s %15s\n", "Index", "Cat Breed", "Cat Color", "Cat W", "Cat LS");
	printf("-----------------------------------------------------------------\n");
	for(trav_s = VH.StackHead; trav_s != -1; trav_s = VH.CH->Data[trav_s].nextCat){
		printf("%2d|", trav_s);
		printf("%18s|", VH.CH->Data[trav_s].Info.catBreed);
		printf("%15s|", VH.CH->Data[trav_s].Info.catColor);
		printf("%15d|", VH.CH->Data[trav_s].Info.cat_W);
		printf("%15d\n", VH.CH->Data[trav_s].Info.cat_LS);
	}
	
	printf("\n\n[Queue]:\n");
	int trav_q;
	printf("%2s %18s %15s %15s %15s\n", "Index", "Cat Breed", "Cat Color", "Cat W", "Cat LS");
	printf("-----------------------------------------------------------------\n");
	for(trav_q = VH.Q.FC; trav_q != -1; trav_q = VH.CH->Data[trav_q].nextCat){
		printf("%2d|", trav_q);
		printf("%18s|", VH.CH->Data[trav_q].Info.catBreed);
		printf("%15s|", VH.CH->Data[trav_q].Info.catColor);
		printf("%15d|", VH.CH->Data[trav_q].Info.cat_W);
		printf("%15d\n", VH.CH->Data[trav_q].Info.cat_LS);
	}
	
	printf("\n\n"); system("pause"); system("cls");
}

//util func: test case
void visual(VirtualMain VH){
	printf("\n%15s | %15s | %15s", "INDEX", "ELEM", "NEXT");
	int i;
	for(i = 0; i < H_MAX; i++){
		printf("\n%15d | %15s | %15d", i, VH.CH->Data[i].Info.catBreed, VH.CH->Data[i].nextCat);
	}
	printf("\nAvail :%d\n", VH.CH->catAvail);
	printf("\nlist :%d\n", VH.MainHead);
}

int main(){
	VirtualMain cat;
	init_everything(&cat);

	populateCats(&cat);
	display_cats(cat);
	
	cat.StackHead = bigger_weight(&cat, 13);
	display_cats(cat);
	
	lesser_ls(&cat, 14);
	display_cats(cat);
	return 0;
}
