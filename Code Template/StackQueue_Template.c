/*
	Data Structures and Algorithm:
		Stack and Queue
		July 28, 2022
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MAX 0xA
#define IT_MAX 0xA
#define CS_MAX 0xA
#define STRING_SIZE 0x1E
#define Type int

typedef char String[STRING_SIZE];
typedef struct{
	String fname;
	String mname;
	String lname;
}StudentName;

typedef struct{
	StudentName StudName;
	String studCourse;
	int yrLevel;
	float GPA;
	bool status;				//1 if Shifted 0 if not
}StudentInfo;

typedef struct SS{
	StudentInfo *IT;			//Dunamic IT Array: IT_MAX
	int IT_stackCount;
}*StudentStack;					//Dynamic Stack Structure

typedef struct{
	StudentInfo *CS;			//Dynamic CS Array: CS_MAX
	Type front;
	Type rear;
}*StudentQueue;					//Dynamic Queue Structure

struct QueueStack{
	StudentQueue NQ;
	StudentStack NS;
	int totalStud;				//Total of students enrolled: Default value is 0
};

struct QueueStack initQueueStack(){
	//Code here...
}

//If student is from IT, insert in the StudentStack otherwise, StudentQueue
//Update totalStuds every insertion
void StudentInsert(struct QueueStack *QS, StudentInfo newStudent){
	//Code here...
}

void populateStudents(struct QueueStack *QS){
	StudentInfo studs[MAX] = {{{"Mark", "Dupio", "Mendoza"}, "IT", 2, 3.0, 0}, {{"Stacy", "Greece", "Cruz"}, "CS", 1, 1.6, 0},
								{{"Kia", "Lopez", "Simmons"}, "CS", 1, 2.4, 0}, {{"Steven", "Zomez", "Ralf"}, "IT", 2, 3.0, 0},
								{{"Bryan", "Inigo", "Ola"}, "CS", 3, 5.0, 0}, {{"Jane", "Ola", "Azenya"}, "IT", 4, 1.2, 0},
								{{"Kivian", "Kay", "Jillian"}, "IT", 1, 2.9, 0} , {{"Sofia", "Bray", "Sommi"}, "CS", 1, 2.9, 0},
								{{"Marie", "Lee", "Chang"}, "IT", 1, 3.6, 0}, {{"Frank", "Haoul", "Instein"}, "CS", 1, 3.2, 0}};
	int i;
	for(i = 0; i < MAX; i++){
		//Insert StudentInsert Function...
	}
}

//Shift Student containing GPA of 3.0 or higher and change the course to their new course.
//		If an IT Student has 3.0 above, shift course to CS and insert to designated array implementation
//		Update status if the student has shifted course.
//			otherwise vice versa
//Return number of students that has successfully shifted.
int StudentShiftCourse(struct QueueStack *QS){
	//Code here...
}

void displayStudentList(struct QueueStack QS){
	printf("%40s\n\n", "[STACK]");
	printf("%-24s%15s%20s%15s\n", "STUDENT NAME", "STUDENT YEAR", "STUDENT COURSE", "STUDENT GPA");
	printf("-------------------------------------------------------------------------------------\n");
	int i;
	StudentStack SS = QS.NS;
	StudentQueue QQ = QS.NQ;
	Type newFront = (QQ->rear+1)%MAX;
	
	for(i = 0; i <= SS->IT_stackCount; i++){
		printf("%-9s %6s %3c.", SS->IT[i].StudName.lname, SS->IT[i].StudName.fname, SS->IT[i].StudName.mname[0]);
		printf("%7d %18s", SS->IT[i].yrLevel, SS->IT[i].studCourse);
		printf("%20.1f\n", SS->IT[i].GPA);
	}
	
	printf("\n\n%40s\n\n", "[QUEUE]");
	printf("%-24s%15s%20s%15s\n", "STUDENT NAME", "STUDENT YEAR", "STUDENT COURSE", "STUDENT GPA");
	printf("-------------------------------------------------------------------------------------\n");
	
	while(QQ->front != newFront){
		printf("%-9s %6s %3c.", QQ->CS[QQ->front].StudName.lname, QQ->CS[QQ->front].StudName.fname, QQ->CS[QQ->front].StudName.mname[0]);
		printf("%7d %18s", QQ->CS[QQ->front].yrLevel, QQ->CS[QQ->front].studCourse);
		printf("%20.1f\n", QQ->CS[QQ->front].GPA);
		QQ->rear = (QQ->rear+1)%CS_MAX;
		QQ->CS[QQ->rear] = QQ->CS[QQ->front];
		QQ->front = (QQ->front+1)%CS_MAX;
	}
	
	printf("\n\nTotal Students Enrolled: %d\n\n", QS.totalStud);
}

int main(){
	//Call here...
	return 0;
}
