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
	struct QueueStack QS;
	QS.NQ = calloc(1, sizeof(StudentQueue));
	QS.NS = calloc(1, sizeof(struct SS));
	
	(QS.NQ)->CS = malloc(sizeof(StudentInfo)*CS_MAX);
	(QS.NS)->IT = malloc(sizeof(StudentInfo)*IT_MAX);
	
	(QS.NS)->IT_stackCount = -1;
	
	(QS.NQ)->front = 0;
	(QS.NQ)->rear = CS_MAX-1;

	QS.totalStud = 0;
	
	return QS;
}

//If student is from IT, insert in the StudentStack otherwise, StudentQueue
//Update totalStuds every insertion
void StudentInsert(struct QueueStack *QS, StudentInfo newStudent){
	StudentStack *SS = &QS->NS;
	StudentQueue *QQ = &QS->NQ;
	
	if((*SS)->IT_stackCount != IT_MAX && ((*QQ)->rear+2)%MAX != (*QQ)->front){
		if(strcmp(newStudent.studCourse, "CS") == 0){
			(*QQ)->rear = ((*QQ)->rear+1)%CS_MAX;
			(*QQ)->CS[(*QQ)->rear] = newStudent;
		} else if(strcmp(newStudent.studCourse, "IT") == 0){
			(*SS)->IT_stackCount++;
			(*SS)->IT[(*SS)->IT_stackCount] = newStudent;
		}
		QS->totalStud++;
	}
	
}

void populateStudents(struct QueueStack *QS){
	StudentInfo studs[MAX] = {{{"Mark", "Dupio", "Mendoza"}, "IT", 2, 3.0, 0}, {{"Stacy", "Greece", "Cruz"}, "CS", 1, 1.6, 0},
								{{"Kia", "Lopez", "Simmons"}, "CS", 1, 2.4, 0}, {{"Steven", "Zomez", "Ralf"}, "IT", 2, 3.0, 0},
								{{"Bryan", "Inigo", "Ola"}, "CS", 3, 5.0, 0}, {{"Jane", "Ola", "Azenya"}, "IT", 4, 1.2, 0},
								{{"Kivian", "Kay", "Jillian"}, "IT", 1, 2.9, 0} , {{"Sofia", "Bray", "Sommi"}, "CS", 1, 2.9, 0},
								{{"Marie", "Lee", "Chang"}, "IT", 1, 3.6, 0}, {{"Frank", "Haoul", "Instein"}, "CS", 1, 3.2, 0}};
	int i;
	for(i = 0; i < MAX; i++){
		StudentInsert(QS, studs[i]);
	}
}

//Shift Student containing GPA of 3.0 or higher and change the course to their new course.
//		If an IT Student has 3.0 above, shift course to CS and insert to designated array implementation
//		Update status if the student has shifted course.
//			otherwise vice versa
//Return number of students that has successfully shifted.
int StudentShiftCourse(struct QueueStack *QS){
	StudentQueue *travQ = &QS->NQ, tQ;
	StudentStack *travS = &QS->NS, tS;
	StudentInfo tempStud;
	Type numOfShifts = 0;
	
	//Allocating Memory
	tQ = calloc(1, sizeof(StudentQueue));
	tQ->CS = malloc(sizeof(StudentInfo)*CS_MAX);
	tQ->front = 0;
	tQ->rear = CS_MAX-1;
	
	tS = calloc(1, sizeof(struct SS));
	tS->IT = malloc(sizeof(StudentInfo)*CS_MAX);
	tS->IT_stackCount = -1;
	
	Type newFront1 = ((*travQ)->rear+1)%CS_MAX;
	
	//Queue
	while((*travQ)->front != newFront1){
		if((*travQ)->CS[(*travQ)->front].GPA >= 3.0 && (*travQ)->CS[(*travQ)->front].status == false){
			strcpy((*travQ)->CS[(*travQ)->front].studCourse, "IT");
			(*travQ)->CS[(*travQ)->front].status = true;
			(*travS)->IT_stackCount++;
			(*travS)->IT[(*travS)->IT_stackCount] = (*travQ)->CS[(*travQ)->front];
			numOfShifts++;
		} else{
			tQ->rear = (tQ->rear+1)%CS_MAX;
			tQ->CS[tQ->rear] = (*travQ)->CS[(*travQ)->front];
		}
		(*travQ)->front = ((*travQ)->front+1)%CS_MAX;
	}
	
	Type newFront2 = (tQ->rear+1)%CS_MAX;
	while(tQ->front != newFront2){
		(*travQ)->rear = ((*travQ)->rear+1)%CS_MAX;
		(*travQ)->CS[(*travQ)->rear] = tQ->CS[tQ->front];
		tQ->front = (tQ->front+1)%CS_MAX;
	}
	
	//Stack
	while((*travS)->IT_stackCount != -1){
		if((*travS)->IT[(*travS)->IT_stackCount].GPA >= 3.0 && (*travS)->IT[(*travS)->IT_stackCount].status == false){
			strcpy((*travS)->IT[(*travS)->IT_stackCount].studCourse, "CS");
			(*travS)->IT[(*travS)->IT_stackCount].status = true;
			(*travQ)->rear = ((*travQ)->rear+1)%CS_MAX;
			(*travQ)->CS[(*travQ)->rear] = (*travS)->IT[(*travS)->IT_stackCount];
			numOfShifts++;
		} else{
			tS->IT_stackCount++;
			tS->IT[tS->IT_stackCount] = (*travS)->IT[(*travS)->IT_stackCount];
		}
		(*travS)->IT_stackCount--;
	}
	
	while(tS->IT_stackCount != -1){
		(*travS)->IT_stackCount++;
		(*travS)->IT[(*travS)->IT_stackCount] = tS->IT[tS->IT_stackCount];
		tS->IT_stackCount--;
	}
	
	return numOfShifts;
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
	struct QueueStack myQS;
	myQS = initQueueStack();
	populateStudents(&myQS);
	
	displayStudentList(myQS); system("pause"); system("cls");
	printf("[SHIFT COURSE]:\n\n");
	Type shift = StudentShiftCourse(&myQS);
	printf("Total Student Shifts: %d\n", shift);
	displayStudentList(myQS); system("pause"); system("cls");
	
	return 0;
}
