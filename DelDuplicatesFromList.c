//Napisati program koji generira 20 slučajnih brojeva u opsegu od 10 - 20 i sprema ih u vezanu listu, po
//redoslijedu generiranja, a ne sortirano.
//a) Korisnik unosi jedan broj i potrebno je iz vezane liste izbrisati sva pojavljivanja tog broja i
//ispisati vezanu listu.
//b) Potrebno je izbrisati sve duple vrijednosti i ispisati vezanu listu.

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<ctype.h>


struct _element;
typedef struct _element element;
typedef element* position;
struct _element {
	int num;
	position next;
};

int addList(position);
void delAll(position);
void printList(position);
void delNumber(position, int);
void delDuplicates(position);


int main() {
	element head;
	head.next = NULL;

	int result = 0;
	int choice = 0;

	srand((unsigned)time(NULL));

	result = addList(&head);
	if (result != 0) {
		delAll(&head);
		return 0;
	}

	printf("DODANA RANDOM LISTA:\n");
	printList(head.next);

	printf("Unesi broj koji zelis izbrisat iz liste:\n");
	scanf("%d", &choice);
	
	delNumber(&head, choice);
	
	printf("LISTA BEZ %d:\n", choice);
	printList(head.next);


	delDuplicates(&head);
	printf("Lista bez duplikata:\n");
	printList(head.next);

	delAll(&head);
	printList(head.next);

	return 0;
}
int addList(position p) {
	position ne = NULL;

	for (int i = 0; i < 20; i++) {

		ne = (position)malloc(sizeof(element));
		if (ne == NULL) {
			printf("greska u dyn alloc!");
			return -1;
		}

		ne->num = (rand() % (20 - 10 + 1)) + 10;

		ne->next = NULL;
		p->next = ne;

		p = p->next;

	}

	return 0;
}
void delAll(position p) {
	position temp = NULL;

	while (p->next != NULL) {
		temp = p->next;
		p->next = temp->next;
		free(temp);

	}

	printf("lista je izbrisana!\n");
}
void printList(position p) {

	while (p != NULL) {
		printf("%d\n",p->num);
		p = p->next;
	}
	printf("\n");
}
void delNumber(position p, int value) {
	position temp = NULL;

	while (p->next != NULL) {

		if (p->next->num == value) {
			temp = p->next;
			p->next = temp->next;
			free(temp);
		}
		else
			p = p->next;
	}


	
}
void delDuplicates(position p) {

	while (p != NULL) {
		delNumber(p, p->num);
		p = p->next;

	}



	
}
