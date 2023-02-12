
//napisati program koji cita podatke o artiklima na racunu. Iz datoteke procitati podatke o artiklima (identifikator artikla, naziv,cijena artikla bez PDV, postotak PDV, kolicina) i zapisati ih sortirano (prema nazivu artikla) u vezanu listu
//Za svaki procitani artikl treba izracunati iznos PDV, jedinicnu cijenu s PDV-om i ukupnu cijenu s PDv-om i zapisati u listu. Ispisi listu sa svim podacima

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>


struct _artikl;
typedef struct _artikl artikl;
typedef artikl* position;

struct _artikl {
	char ID_artikla[10];
	char naziv_artikla[20];
	float jedinicna_cijena_bez_PDV;
	int PDV_postotak;
	int iznos_PDV;
	int kolicina;
	float jedinicna_cijena_s_PDV;
	float ukupna_cijena_s_PDV;
	position next;
};

int readFile(position, char[]);
void delAll(position);
void printList(position);

int main() {

	artikl head;
	head.next = NULL;

	char ime_filea[20];
	int result = 0;

	printf("unesi koji file zelis ucitat\n");
	scanf("%s", ime_filea);

	result = readFile(&head, ime_filea);
	if (result == -1) {
		delAll(&head);
		return 0;
	}

	printList(head.next);

	delAll(&head);

	return 0;
}
int readFile(position p, char ime_filea[20]) {

	FILE* pF = NULL;

	position ne = NULL;
	position head = p;

	pF = fopen(ime_filea, "r");
	if (pF == NULL) {
		printf("greska u otvaranju filea:\n");
		return -1;
	}

	while (!feof(pF)) {
		ne = (position)malloc(sizeof(artikl));
		if (ne == NULL) {
			printf("greska u malloc\n");
			return -1;
		}

		fscanf(pF, "%s %s %f %d %d", ne->ID_artikla, ne->naziv_artikla, &ne->jedinicna_cijena_bez_PDV, &ne->PDV_postotak, &ne->kolicina);

		ne->iznos_PDV = ne->jedinicna_cijena_bez_PDV * ne->PDV_postotak / 100;

		ne->jedinicna_cijena_s_PDV = ne->iznos_PDV + ne->jedinicna_cijena_bez_PDV;

		ne->ukupna_cijena_s_PDV = ne->jedinicna_cijena_s_PDV * ne->kolicina;


		p = head;
		while (p->next != NULL && strcmp(p->next->naziv_artikla, ne->naziv_artikla) < 0) {
			p = p->next;
		}

		ne->next = p->next;
		p->next = ne;


	}
	fclose(pF);

	return 0;
}

void delAll(position p) {
	position temp = NULL;

	while (p->next != NULL) {
		temp = p->next;
		p->next = temp->next;
		free(temp);
	}
	printf("lista je izbrisana\n");
}
void printList(position p) {
	printf("ID_artikla  jedinicna_bez_PDV jedinicna_s_PDV ukupna_s_PDV PDV_postotak iznos_PDV  kolicina\tnaziv_artikla\n");
	while (p != NULL) {

		printf("%s\t %f\t %f\t %f\t %d\t  %d\t \t%d\t \t%s\n", p->ID_artikla, p->jedinicna_cijena_bez_PDV, p->jedinicna_cijena_s_PDV, p->ukupna_cijena_s_PDV, p->PDV_postotak, p->iznos_PDV, p->kolicina, p->naziv_artikla);

		p = p->next;
	}



}
