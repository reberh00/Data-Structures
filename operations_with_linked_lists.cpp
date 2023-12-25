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
void push_sort(nodeposition);
void print_list(nodeposition);
void pop_front(nodeposition);
void pop_all(nodeposition);
void pop_back(nodeposition);
void search(nodeposition);
void deleteNode(nodeposition, int);
void reverseList(nodeposition);

bool is_good = true;

int main() {
	Node head;
	head.next = NULL;

	int choice = 0;



	srand((unsigned)time(NULL));

	while (true) {

		cout << "****************************" << endl;
		cout << "Press: " << endl;
		cout << "1 to insert number at the beginning of the list" << endl;
		cout << "2 to insert number at the end of the list" << endl;
		cout << "3 to insert number and sort it in the list" << endl;
		cout << "4 to print list" << endl;
		cout << "5 to search for certain number from the list" << endl;
		cout << "6 to delete first number from the list" << endl;
		cout << "7 to delete last number from the list" << endl;
		cout << "8 to delete the list" << endl;
		cout << "9 to reverse the list" << endl;
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
			push_sort(&head);
			break;
		case 4:
			print_list(head.next);
			break;
		case 5:
			search(head.next);
			break;
		case 6:
			pop_front(&head);
			break;
		case 7:
			pop_back(&head);
			break;
		case 8:
			pop_all(&head);
			break;
		case 9:
			reverseList(&head);
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
	ne->number = (rand() % (120 - 100 + 1)) + 100;
	cout << "Added number is: " << ne->number << endl;

	ne->next = p->next;
	p->next = ne;

	return true;
}
void push_sort(nodeposition p) {

	nodeposition ne;

	ne = new Node();
	if (ne == NULL) {
		cout << "Dyn alloc mistake" << endl;
		exit(0);
	}

	cout << "Add number to list" << endl;

	//for user input validation
	while (!(cin >> ne->number)) {
		cout << "Invalid input. Please enter a valid number." << endl;
		cin.clear(); //clears error flag
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); //discards invalid input
	}

	if (p->next == NULL || ne->number <= p->next->number) {

		ne->next = p->next;
		p->next = ne;
	}
	else {
		while (p->next != NULL && ne->number > p->next->number) {
			p = p->next;
		}

		ne->next = p->next;
		p->next = ne;

	}

}
void print_list(nodeposition p) {
	cout << "printed list: ";

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
	nodeposition head = p;


	cout << "Enter the number you want to search " << endl;

	//for user input validation
	while (!(cin >> number_to_search)) {
		cout << "Invalid input. Please enter a valid number." << endl;
		cin.clear(); //clears error flag
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); //discards invalid input
	}

	while (p->number != number_to_search && p != NULL) {
		p = p->next;

	}
	if (p == NULL) {
		cout << "Haven't found your number" << endl;
		return;
	}

	cout << "You searched for number: " << p->number << endl;

	cout << "Press d if you want to delete the number, press a if you want to add number after the searched number,";
	cout << " or anything else if you just wanted to search the number" << endl;
	cin >> choice;

	if (choice == 'a') {
		is_good = push_front(p);
		if (!is_good) {
			cout << "Dyn alloc mistake" << endl;
			exit(0);
		}	
	}
	else if (choice == 'd') {
		deleteNode(head, number_to_search);
	}

}
void deleteNode(nodeposition p, int value) {

	while (p->next != NULL && p->next->number != value) {
		p = p->next;
	}

	if (p->next != NULL) {
		nodeposition temp = p->next;
		p->next = temp->next;
		free(temp);
		cout << value << " has been deleted." << endl;
	}
	else {
		cout << "Value was not found" << endl;
	}


}
void reverseList(nodeposition head) {

	if (head->next == NULL || head->next->next == NULL) {
		cout << "List is empty or has only one element" << endl;
		return;
	}

	nodeposition current = head->next;
	nodeposition prev = NULL;
	nodeposition forward;
	
	while (current != NULL) {
		forward = current->next;
		current->next = prev;

		prev = current;
		current = forward;
		

	}
	head = prev;

	cout << "Reversed ";
	print_list(head);
}
