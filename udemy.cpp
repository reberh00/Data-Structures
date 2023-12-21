#include<iostream>
#include<time.h>
#include<stdlib.h>

using namespace std;

typedef struct Node_ Node;
typedef Node* nodeposition;

struct Node_ {
	int number;
	nodeposition next;
};

bool push_front(nodeposition);
bool push_back(nodeposition);
void print_list(nodeposition);
void pop_front(nodeposition);
void pop_all(nodeposition);
void pop_back(nodeposition);
void search(nodeposition);
//add reverse list, sort add, myb add front searched num
//delete searched number NE RADI

bool is_good = true;

int main() {
	Node head;
	head.next = NULL;

	int choice = 0;

	

	srand((unsigned)time(NULL));

	while (choice != 14) {

		cout << "****************************" << endl;
		cout << "Press: " << endl;
		cout << "1 to insert number at the beginning of the list" << endl;
		cout << "2 to insert number at the end of the list" << endl;
		cout << "3 to print list" << endl;
		cout << "4 to search for certain number from the list" << endl;
		cout << "5 to delete first number from the list" << endl;
		cout << "6 to delete last number from the list" << endl;
		cout << "7 to delete the list" << endl;
		cout << "anything else to end program" << endl;
		cout << "****************************" << endl;

		cin >> choice;

		switch (choice)
		{
		case 1:
			is_good = push_front(&head);
			if (!is_good) {
				cout << "Dyn alloc mistake" << endl;
				return 0;
			}
			break;
		case 2:
			is_good = push_back(&head);
			if (!is_good) {
				cout << "Dyn alloc mistake" << endl;
				return 0;
			}
			break;
		case 3:
			print_list(head.next);
			break;
		case 4:
			search(head.next);
			break;
		case 5:
			pop_front(&head);
			break;
		case 6:
			pop_back(&head);
			break;
		case 7:
			pop_all(&head);
			break;
		default:
			pop_all(&head);
			print_list(head.next);
			return 0;
		}
	}

	

	return 0;
}
bool push_front(nodeposition p) {

	nodeposition ne;

	
		ne = new Node();
		if (ne == NULL) {
			return false;
		}
		ne->number = (rand() % (120 - 100 + 1) + 100);
		cout << "Added number is: " << ne->number << endl;

		ne->next = p->next;
		p->next = ne;

	
	return true;
}
bool push_back(nodeposition p) {
	nodeposition ne, p_head;
	

	p_head = p;

	
		ne = new Node();
		if (ne == NULL)
			return false;

		p = p_head;

		while (p->next != NULL) {
			p = p->next;
		}
		ne->number = (rand()%(120 - 100 + 1)) + 100;
		cout << "Added number is: " << ne->number << endl;

		ne->next = p->next;
		p->next = ne;

	

	return true;
}
void print_list(nodeposition p) {
	cout << "Printed list: ";

	if (p == NULL) {
		cout << "there are no elements in this list" << endl;
		return;
	}


	while (p != NULL) {
		cout << p->number << " ";
		p = p->next;
	}
	cout << endl;
}
void pop_front(nodeposition p) {
	
	nodeposition temp;

	cout << "Number " << p->next->number << " is about to be deleted." << endl;

		temp = p->next;
		p->next = temp->next;
		free(temp);

}
void pop_back(nodeposition p) {

	nodeposition temp;

	while (p->next->next != NULL)
		p = p->next;

	cout << "Number " << p->next->number << " is about to be deleted." << endl;

	temp = p->next;
	p->next = temp->next;
	free(temp);

}
void pop_all(nodeposition p) {
	nodeposition temp;

	while (p->next != NULL) {

		temp = p->next;
		p->next = temp->next;
		free(temp);

	}
	cout << "List deleted" << endl;

}
void search(nodeposition p) {

	int number_to_search;
	char choice;
	

	cout << "Enter the number you want to search " << endl;
	cin >> number_to_search;

	while (p->number != number_to_search && p!=NULL) {
		p = p->next;

	}
	if (p == NULL) {
		cout << "Haven't found your number" << endl;
		return;
	}

	cout << "You searched for number: " << p->number << endl;
	cout << "Press d if you want to delete the number, press a if you want to add number after searched number, or anything else if you just wanted to search number" << endl;
	cin >> choice;
	if (choice == 'a') {
		is_good = push_front(p);
		if (!is_good) {
			cout << "Dyn alloc mistake" << endl;
			exit(0);
		}
		else if (choice == 'd') {
			pop_front(p);
		}
	}
	
}
