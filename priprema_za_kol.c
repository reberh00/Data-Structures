
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
#include<ctype.h>
#include<string.h>

struct _student;
typedef struct _student student;
typedef student* studentPosition;

struct _student {
	int maticni_broj;
	char ime[20], prezime[20];
	int prvi_kolokvij, drugi_kolokvij, ukupniBodovi;
	studentPosition *next;

};

int rezultatiKolokvija1(studentPosition, char[]);
void printList(studentPosition);
int rezultatiKolokvija2(studentPosition, char[]);
void delAll(studentPosition);

int main() {

	student head;
	head.next = NULL;

	char ime_filea[20] = { '\0' };
	int povratna = 0;

	printf("Unesi ime filea za prvi kol:\n");
	scanf("%s", ime_filea);

	
	povratna = rezultatiKolokvija1(&head, ime_filea);
	if (povratna == -1) {
		delAll(&head);
		return 0;
	}
	

	printf("Unesi ime filea za drugi kol:\n");
	scanf("%s", ime_filea);
	povratna = rezultatiKolokvija2(&head, ime_filea);
	if (povratna == -1) {
		delAll(&head);
		return 0;
	}

	printf("Imena i bodovi studenata za prvi i drugi kol:\n");
	printList(head.next);

	delAll(&head);

	return 0;
}
int rezultatiKolokvija1(studentPosition p, char ime_filea[20]) {
	FILE* pF = NULL;

	studentPosition ne = NULL;

	pF = fopen(ime_filea, "r");

	

	if (pF == NULL) {
		printf("greska kod otvaranja:\n");
		return -1;
	}

	while (!feof(pF)) {

		ne = (studentPosition)malloc(sizeof(student));
		if (ne == NULL) {
			printf("greska u aloc\n");
			return -1;
		}

		fscanf(pF,"%s %s %d",ne->ime,ne->prezime,&ne->prvi_kolokvij);

		ne->next = NULL;
		p->next = ne;

		p = p->next;
	}
	fclose(pF);

	return 0;
}
void printList(studentPosition p) {
	int ukupni_bodovi=0;

	while (p != NULL) {
		if (p->prvi_kolokvij >= 50 && p->drugi_kolokvij >= 50) {
			printf("%s %s %d %d\n", p->ime, p->prezime, p->prvi_kolokvij, p->drugi_kolokvij);
		}
		p = p->next;
	}
	printf("\n");
}
int rezultatiKolokvija2(studentPosition p, char ime_filea[20]) {

	FILE* pF = NULL;

	pF = fopen(ime_filea, "r");

	if (pF == NULL) {
		printf("greska kod otvaranja:\n");
		return -1;
	}

	while (!feof(pF)) {
		p = p->next;
		

		fscanf(pF, "%s %s %d", p->ime,p->prezime,&p->drugi_kolokvij);

	}

	fclose(pF);

	return 0;
}
void delAll(studentPosition p) {
	studentPosition temp=NULL;

	while (p->next != NULL) {
		temp = p->next;
		p->next = temp->next;
		free(temp);


	}

	printf("Lista je izbrisana\n");
	printList(p);
}