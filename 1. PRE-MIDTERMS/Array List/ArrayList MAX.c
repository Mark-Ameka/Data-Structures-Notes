#include <stdio.h>
#include <stdlib.h>

typedef char String[30];

typedef struct{
	String fname;
	String lname;
	String mname;
}Student;

typedef struct{
	Student *students;
	int max;
	int count;
}StudentList;

void initStudent(StudentList *list){
	list->max = 8;
	list->count = 0;
	list->students = (Student*) malloc(sizeof(Student)*list->max);
}

void insertFirst(StudentList *list, Student newStudent){
	int i;
	if(list->count >= list->max){
		list->max *= 2;
		list->students = realloc(list->students, list->max);
	}
	
	for(i = list->count; i > 0; i--){
		list->students[i] = list->students[i-1];
	}
	list->students[i] = newStudent;
	list->count++;
}

void displayStudent(Student stud){
	printf("%s\t\t", stud.lname);
	printf("%s\t\t", stud.fname);
	printf("%c.\t\t", stud.mname[0]);
}
void displayStudentList(StudentList stud){
	printf("Last Name:\tFirst Name:\tInitial:\tGender:\n");
	int i;
	for(i = 0; i < stud.count; i++){
		displayStudent(stud.students[i]); printf("\n");
	}
}

int main(){
	StudentList list;
	
	Student stud1 = {"Stacy", "Greece", "Cruz"};
	
	initStudent(&list);
	
	insertFirst(&list, stud1);
	displayStudentList(list);
	
	return 0;
}
