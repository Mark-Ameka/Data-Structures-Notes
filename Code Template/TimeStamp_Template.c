#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STR_MAX 4
#define ARR_MAX 10
#define Type int

typedef char String[STR_MAX];
typedef struct{
	String ID;
	Type hour;
	Type minute;
	Type seconds;
}TimeStamp;

typedef struct AL{
	TimeStamp *time_info;				//Dynamic Array for AL
	int count;
}*ArrayList;							//Dynamic Structure

typedef struct time{
	TimeStamp time_info;
	struct time *next_id;
}TNode, *TList;							//Definition of Linked List

typedef struct time_cb{
	TimeStamp time_info;
	Type next;
}TimeNode;								//Definition of TimeNode Structure {Container}

typedef struct{
	TimeNode *time_details;				//Dynamic Array for CB
	Type head;							//Head of the list
	Type avail;
}*VirtualTime;							//Dynamic Cursor-Based

struct Container{
	TList LL;
	VirtualTime CB;
	ArrayList AL;
};

//Will initialize AL, CB and LL respectively.
void init_container(struct Container *ComboList){
	//Code here...
}

/*
	will insert id details according to as follows:
	> if the hour of the account id is greater than 6 hours, insert data into the CB (Insert Last: O(n))
	> otherwise, if lesser than 6 hours, insert into the LL (Insert First: O(1));
*/
void insert_id(struct Container *ComboList, TimeStamp new_time){
	//Code here...
}

//Will populate data to the ComboList
void populate_id(struct Container *ComboList){
	TimeStamp data[ARR_MAX] = {{"A90", 2, 34, 31},  {"A40", 7, 27, 23}, {"A30", 5, 36, 62},
							   {"A10", 11, 21, 12}, {"A10", 4, 18, 12}, {"A80", 8, 29, 42},
							   {"A50", 2, 22, 27},  {"A20", 1, 25, 12}, {"A60", 8, 42, 46},
							   {"A70", 10, 19, 51}};
	int i;
	for(i = 0; i < ARR_MAX; i++){
		//Call here...
	}
}

/*
	Will transfer all account IDs contained from the CB and LL to the AL
*/
void transfer_all_id(struct Container *ComboList){
	//Code here...
}

void display_all(struct Container ComboList){
	//ArrayList
	printf("Array List:\n");
	printf("%-15s|%15s\n", "Account ID", "TimeStamp");
	printf("=========================================\n");
	int i;
	if(ComboList.AL->count == 0){
		printf("AL is Empty!\n\n");
	} else{
		for(i = 0; i < ComboList.AL->count; i++){
			printf("%-15s|", ComboList.AL->time_info[i].ID);
			printf("%9d:%d:%d", ComboList.AL->time_info[i].hour, ComboList.AL->time_info[i].minute, ComboList.AL->time_info[i].seconds);
			printf("\n");
		}
	}
	
	//Cursor-Based
	printf("Cursor-Based:\n");
	printf("%-15s|%15s\n", "Account ID", "TimeStamp");
	printf("=========================================\n");
	if(ComboList.CB->head == -1){
		printf("CB is Empty\n\n");
	} else{
		for(i = ComboList.CB->head; i != -1; i = ComboList.CB->time_details[i].next){
			printf("%-15s|", ComboList.CB->time_details[i].time_info);
			printf("%9d:%d:%d", ComboList.CB->time_details[i].time_info.hour, ComboList.CB->time_details[i].time_info.minute, ComboList.CB->time_details[i].time_info.seconds);
			printf("\n");
		}
	}
	
	//Linked List
	printf("Linked List:\n");
	printf("%-15s|%15s\n", "Account ID", "TimeStamp");
	printf("=========================================\n");
	if(ComboList.LL == NULL){
		printf("LL is Empty\n\n");
	} else{
		while(ComboList.LL != NULL){
			printf("%-15s|", ComboList.LL->time_info.ID);
			printf("%9d:%d:%d", ComboList.LL->time_info.hour, ComboList.LL->time_info.minute, ComboList.LL->time_info.seconds);
			printf("\n");
			ComboList.LL = ComboList.LL->next_id;
		}
	}
	printf("\n\n");
	system("pause"); system("cls");
}

int main(){
	struct Container ComboList;
	
//	init_container(&ComboList);
//	populate_id(&ComboList);
	
//	display_all(ComboList);

//	transfer_all_id(&ComboList);
//	display_all(ComboList);
	
	return 0;
}
