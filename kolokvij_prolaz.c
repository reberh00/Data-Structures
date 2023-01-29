
//iz filea 1_kolokvij.txt cita ime prezime i bodove iz prvog kolokvija i sve to zapisat u vezanu listu
//
//iz filea 2_kolokvij.txt cita ime prezime i bodove iz drugog kolokvija i sve to zapisat u vezanu listu
// 
//ispisat sve studente koji su prosli ispit odnosno sve koji su oba kolokvija imali preko 50%
//


#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<ctype.h>

struct _student;
typedef struct _student student;
typedef student* studentPosition;
struct _student {
	int maticni_broj;
	char ime[20], prezime[20];
	int prvi_kolokvij, drugi_kolokvij, ukupni_bodovi;
	studentPosition next;
};

int prviKolRezultati(studentPosition,char[]);
void delAll(studentPosition);
void printList(studentPosition);
int drugiKolRezultati(studentPosition, char[]);

int main(){
	student head;
	head.next = NULL;

	int povratna = 0;

	char ime_filea[20] = {'\0'};


	printf("Unesi ime filea za rezultate prvog kol:\n");
	scanf("%s", ime_filea);

	povratna = prviKolRezultati(&head, ime_filea);
	if (povratna == -1) {
		delAll(&head);
		return 0;
	}

	printf("Unesi ime filea za rezultate drugog kol:\n");
	scanf("%s", ime_filea);

	povratna = drugiKolRezultati(&head, ime_filea);
	if (povratna == -1) {
		delAll(&head);
		return 0;
	}
	printList(head.next);


	delAll(&head);





	return 0;
}
int prviKolRezultati(studentPosition p, char ime_filea[20]) {

	FILE* pF = NULL;
	studentPosition ne = NULL;
	/*studentPosition head = NULL;
	head= p;*/


	pF = fopen(ime_filea, "r");
	if (pF == NULL) {
		printf("greska s otvaranjem filea %s\n", ime_filea);
		return -1;
	}
	
	while (!feof(pF)) {
		ne = (studentPosition)malloc(sizeof(student));
		if (ne == NULL) {
			printf("greska u din alloc\n");
			return -1;
		}
		

		fscanf(pF, "%s %s %d", ne->ime, ne->prezime, &ne->prvi_kolokvij);

		/*p = head;*/

		//while (p->next != NULL && strcmp(p->next->prezime, ne->prezime)<0) {

		//	/*if (strcmp(p->next->prezime, ne->prezime) == 0) {

		//		while (p->next != NULL && strcmp(p->next->ime, ne->ime) < 0) {
		//			p = p->next;
		//		}
		//	}*/
		//	
		//		p = p->next;
		//	

		//	
		//}

		ne->next = NULL;
		p->next = ne;
		p = p->next;

		/*printList(&p);*/
		
	}

	return 0;
}
void delAll(studentPosition p) {
	studentPosition temp = NULL;

	while (p->next != NULL) {
		temp = p->next;
		p->next = temp->next;
		free(temp);
	}
	printf("lista je izbrisana\n");
}
void printList(studentPosition p) {

	while (p != NULL) {
		if(p->prvi_kolokvij>=50 && p->drugi_kolokvij>=50)
		printf("%s %s %d %d\n", p->ime, p->prezime, p->prvi_kolokvij,p->drugi_kolokvij);

		p = p->next;

	}
	printf("\n");
}
int drugiKolRezultati(studentPosition p, char ime_filea[20]) {
	FILE* pF = NULL;

	pF = fopen(ime_filea, "r");
	if (pF == NULL) {
		printf("greska s otvaranjem filea %s\n", ime_filea);
		return -1;
	}

	while (!feof(pF)) {
		p = p->next;

		fscanf(pF, "%s %s %d", p->ime, p->prezime, &p->drugi_kolokvij);

		
		
		

	}

	return 0;
}
