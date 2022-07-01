#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef char String[30];

typedef struct{
	String fname;
	String mname;
	String lname;
	char gender;
}Student;

typedef struct node{
	Student stdnts;
	struct node *link;
}*List;

void populateStudent(List *head);

void insertStudentFirst(List *head, Student newStudent);
void insertStudentLast(List *head, Student newStudent);
void insertStudentSortedUnique(List *head, Student newStudent);
void insertStudentAfter(List *head, Student newStudent, String name);
void insertStudentBefore(List *head, Student newStudent, String name);

void deleteStudentFirst(List *head);
void deleteStudentAfter(List *head, String name);
void deleteStudentBefore(List *head, String name);
void deleteStudentLast(List *head);

void displayStudentList(List head);

int main(){
	List head = NULL;
	
	populateStudent(&head);
	
	printf("\nDelete First: Stacy\n");
	deleteStudentFirst(&head);
	displayStudentList(head);
	
	printf("\nDelete After: Bryan\n");
	deleteStudentAfter(&head, "Bryan");
	displayStudentList(head);
	
	printf("\nDelete Before: Bryan\n");
	deleteStudentBefore(&head, "Bryan");
	displayStudentList(head);
	
	printf("\nDelete Last: Steven\n");
	deleteStudentLast(&head);
	displayStudentList(head);
	
	
	return 0;
}

void displayStudentList(List head){
	printf("Last Name:\tFirst Name:\tInitial:\tGender:\n");
	while(head != NULL){
		printf("%s\t\t", head->stdnts.lname);
		printf("%s\t\t", head->stdnts.fname);
		printf("%c.\t\t", head->stdnts.mname[0]);
		printf("'%c'\n", head->stdnts.gender);
		head = head->link;
	}
}

void insertStudentFirst(List *head, Student newStudent){
	List temp = (List) malloc(sizeof(struct node));
	if(temp != NULL){
		temp->stdnts = newStudent;
		temp->link = *head;
		*head = temp;
	}
}

void insertStudentLast(List *head, Student newStudent){
	for(; *head != NULL; head = &(*head)->link){}
	*head = (List) malloc(sizeof(struct node));
	if(*head != NULL){
		(*head)->stdnts = newStudent;
		(*head)->link = NULL;
	}
}

void insertStudentSortedUnique(List *head, Student newStudent){
	List temp, *trav;
	for(trav = head; *trav != NULL && strcmp((*trav)->stdnts.lname, newStudent.lname) != 0; trav = &(*trav)->link){}
	if(*trav == NULL){
		for(trav = head; *trav != NULL && strcmp((*trav)->stdnts.lname, newStudent.lname) < 0; trav = &(*trav)->link){}
		temp = malloc(sizeof(struct node));
		if(temp != NULL){
			temp->stdnts = newStudent;
			temp->link = *trav;
			*trav = temp;
		}
	}
}

void insertStudentAfter(List *head, Student newStudent, String name){
	List temp = (List) malloc(sizeof(struct node));
	
	temp->stdnts = newStudent;
	if(*head != NULL){
		for(; *head != NULL && strcmp((*head)->stdnts.fname, name) != 0; head = &(*head)->link){}
		if(*head != NULL){
			temp->link = (*head)->link;
			(*head)->link = temp;
		}
	}
}

void insertStudentBefore(List *head, Student newStudent, String name){
	List temp = (List) malloc(sizeof(struct node));
	temp->stdnts = newStudent;
	
	for(; *head != NULL && strcmp((*head)->stdnts.fname, name) != 0; head = &(*head)->link){}
	if(*head != NULL){
		temp->link = *head;
		*head = temp;
	}
}

void deleteStudentFirst(List *head){
	List temp;
	if(*head != NULL){
		temp = *head;
		*head = temp->link;
		free(temp);
	}
}

void deleteStudentAfter(List *head, String name){
	List temp;

	for(; *head != NULL && strcmp((*head)->stdnts.fname, name) != 0; head = &(*head)->link){}
	if(*head != NULL){
		temp = (*head)->link;
		(*head)->link = temp->link;
		free(temp);
	}
}

void deleteStudentBefore(List *head, String name){
	List temp;
	List *prev;
	
	for(; *head != NULL && strcmp((*head)->stdnts.fname, name) != 0; prev = head, head = &(*head)->link){}
	if(*head != NULL){
		temp = *prev;
		*prev = *head;
		free(temp);
	}
}

void deleteStudentLast(List *head){
	for(; *head != NULL && (*head)->link != NULL; head = &(*head)->link){}
	*head = NULL;
}
  
void populateStudent(List *head){
	Student stud1 = {"Mark", "Dupio", "Mendoza", 'M'};
	Student stud2 = {"Stacy", "Greece", "Cruz", 'F'};
	Student stud3 = {"Kia", "Lopez", "Simmons", 'F'};
	Student stud4 = {"Steven", "Zomez", "Ralf", 'M'};
	Student stud5 = {"Bryan", "Inigo", "Ola", 'M'};
	Student stud6 = {"Jane", "Ola", "Azenya", 'M'};
	Student stud7 = {"Kivian", "Kay", "Jillian", 'M'};
	
	printf("Insert Sample Info:\n");
	insertStudentFirst(head, stud1);
	insertStudentFirst(head, stud2);
	insertStudentLast(head, stud3);
	insertStudentLast(head, stud4);
	displayStudentList(*head);
	
	printf("\nInsert Student Sorted Unique: Kivian\n");
	insertStudentSortedUnique(head, stud7);
	displayStudentList(*head);
	
	printf("\nInsert Student After Mark: Bryan\n");
	insertStudentAfter(head, stud5, "Mark");
	displayStudentList(*head);

	printf("\nInsert Student Before Steven: Jane\n");
	insertStudentBefore(head, stud6, "Steven");
	displayStudentList(*head);
}
