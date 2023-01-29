//Napisati program koji generira 20 sluèajnih brojeva u opsegu od 10 - 20 i sprema ih u vezanu listu, po
//redoslijedu generiranja, a ne sortirano.
//a) Korisnik unosi jedan broj i potrebno je iz vezane liste izbrisati sva pojavljivanja tog broja i
//ispisati vezanu listu.
//b) Potrebno je izbrisati sve duple vrijednosti i ispisati vezanu listu.

#define _CRT_SECURE_NO_WARNIGNS


#include<stdio.h>
#include<stdlib.h>
#include<time.h>


struct _element;
typedef struct _element element;
typedef element* position;
struct _element {
	int num;
	position next;
};

int Add_Number(position);
int Delete_List(position);
int Print_List(position);
int Delete_Number(position, int);
int Delete_Duplicates(position);

int main() {
	element head;
	head.next = NULL;

	int result = 0;
	int choice = 0;

	srand((unsigned)time(NULL));

	result = Add_Number(&head);
	if (result != 0) {
		result = Delete_List(&head);
		return 0;
	}
	printf("Random lista:\n");
	result = Print_List(head.next);


	printf("Unesi broj koji bi izbacia iz liste:\n");
	scanf("%d", &choice);
	
	result = Delete_Number(&head, choice);
	if (result != 0) {
		result = Delete_List(&head);
		return 0;
	}
	printf("Lista bez broja %d:\n", choice);
	result = Print_List(head.next);

	printf("Lista bez duplih brojeva:\n");
	result = Delete_Duplicates(&head);
	if (result != 0) {
		result = Delete_List(&head);
		return 0;
	}
	result = Print_List(head.next);

	result = Delete_List(&head);



	return 0;
}
int Add_Number(position p) {
	position new_element = NULL;

	for (int i = 0; i < 20; i++) {

		new_element = (position)malloc(sizeof(element));
		if (new_element == NULL) {
			printf("Greska u dyn alloc\n");
			return -1;
		}

		new_element->num = (rand() % (20 - 10 + 1)) + 10;

		new_element->next = NULL;
		p->next = new_element;

		p = p->next;
	}

	return 0;
}
int Delete_List(position p) {
	position temp = NULL;

	while (p->next != NULL) {
		temp = p->next;
		p->next = temp->next;
		free(temp);
	}
	printf("\n");
	printf("Lista je izbrisana.\n");

	return 0;
}
int Print_List(position p) {

	while (p != NULL) {
		printf("%d\n", p->num);
		p = p->next;
	}

	return 0;
}
int Delete_Number(position p, int value) {
	position temp = NULL;

	while (p->next != NULL) {

		if (p->next->num == value) {
			temp = p->next;
			p->next = temp->next;
			free(temp);
		}
		else {
			p = p->next;
		}
		
	}

	return 0;
}
int Delete_Duplicates(position p) {
	int result = 0;

	p = p->next;

	while (p != NULL) {
		result = Delete_Number(p, p->num);
		p = p->next;

	}

	return 0;
}