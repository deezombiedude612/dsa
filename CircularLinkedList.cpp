#ifndef CIRCULARLINKEDLIST_CPP
#define CIRCULARLINKEDLIST_CPP

#include <iostream>

using namespace std;

/**
 * @brief Node structure to be used in CLL
 */
struct Node {
	int item;
	Node *next;
};

class CLL {
 private:
	Node *head;
	bool isEmpty();

 public:
	CLL();
	CLL(int item);
	~CLL();
	unsigned int getSize();

	void addHead(int newItem);
	void addTail(int newItem);
	void removeHead();
	void removeTail();
	void displayList();
	int getIndexOf(int searchedItem);
	bool contains(int searchedItem);
};

/**
 * @brief Check if CLL is empty
 * 
 * @return true 
 * @return false 
 */
bool CLL::isEmpty() {
	return head == NULL;
}

CLL::CLL() {
	head = NULL;
}

CLL::CLL(int item) {
	addHead(item);
}

CLL::~CLL() {
	while (getSize() > 0) removeHead();
	head = NULL;
	delete head;
}

/**
 * @brief Retrieve size of CLL (number of Nodes currently in CLL)
 * 
 * @return unsigned int 
 */
unsigned int CLL::getSize() {
	if (isEmpty()) return 0;

	int numNodes = 0;
	Node *cur = head;

	do {
		numNodes++;
		cur = cur->next;
	} while (cur != head);

	cur = NULL;
	delete cur;

	return numNodes;
}

/**
 * @brief Add a new Node to CLL at given index
 * 
 * @param newItem - New item to be added into CLL
 */
void CLL::addHead(int newItem) {
	Node *newHead = new Node;
	newHead->item = newItem;

	if (isEmpty())
		newHead->next = newHead;
	else {
		newHead->next = head;

		Node *cur = head;
		do {
			cur = cur->next;
		} while (cur->next != head);

		cur->next = newHead;
	}

	head = newHead;

	newHead = NULL;
	delete newHead;

	cout << "\nInserted new head to CLL: " << newItem << endl;
}

/**
 * @brief Add a new tail Node in the CLL
 * 
 * @param newItem - New item to be added into CLL
 */
void CLL::addTail(int newItem) {
	if (isEmpty())
		addHead(newItem);
	else {
		Node *newNode = new Node;
		newNode->item = newItem;
		newNode->next = head;

		Node *cur = head;
		do {
			cur = cur->next;
		} while (cur->next != head);

		cur->next = newNode;

		cur = NULL;
		delete cur;

		newNode = NULL;
		delete newNode;

		cout << "\nInserted new tail to CLL: " << newItem << endl;
	}
}

/**
 * @brief Removes current head Node in the CLL
 */
void CLL::removeHead() {
	if (isEmpty())
		cout << "No more nodes to delete!\n";
	else if (head->next == head) {
		cout << "\nDeleting head from CLL: " << head->item << endl;
		delete head;
		head = NULL;

		cout << "CLL is now empty.\n";
		// cout << "Deleting last node not implemented yet.\n";
	} else {
		Node *cur = head;
		do {
			cur = cur->next;
		} while (cur->next != head);

		head = head->next;

		cout << "\nDeleting head from CLL: " << cur->next->item << endl;
		delete cur->next;
		cur->next = head;

		cur = NULL;
		delete cur;
	}
}

/**
 * @brief Removes current tail Node in the CLL
 */
void CLL::removeTail() {
	if (isEmpty())
		cout << "No more nodes to delete!\n";
	else if (head->next == head)
		removeHead();
	else {
		Node *cur = head;
		do {
			cur = cur->next;
		} while (cur->next->next != head);

		cout << "\nDeleting tail from CLL: " << cur->next->item << endl;
		delete cur->next;
		cur->next = head;
	}
}

/**
 * @brief Display full list
 */
void CLL::displayList() {
	Node *cur = head;
	if (isEmpty()) {
		cout << "CLL is currently empty.\n";
		return;
	}

	do {
		cout << cur->item << " ";
		cur = cur->next;
	} while (cur != head);

	cout << "END\n";
	cur = NULL;
	delete cur;
}

/**
 * @brief Retrieve index of first occurrence of item in CLL
 * Returns -1 if not found
 * 
 * @param searchedItem - Item to be searched in CLL
 * @return int 
 */
int CLL::getIndexOf(int searchedItem) {
	int index = 0;

	Node *cur = head;
	do {
		if (cur->item == searchedItem) return index;
		cur = cur->next;
	} while (cur != head);

	return -1;
}

/**
 * @brief Returns true if item is found in CLL, false otherwise
 * 
 * @param searchedItem - Item to be searched in CLL
 * @return true 
 * @return false 
 */
bool CLL::contains(int searchedItem) {
	return getIndexOf(searchedItem) != -1;
}

int main(int argc, char **argv) {
	CLL l(50);
	l.displayList();
	l.addHead(40);
	l.displayList();
	l.addHead(30);
	l.displayList();
	l.addHead(20);
	l.displayList();
	l.addTail(60);
	l.displayList();
	l.addTail(70);
	l.displayList();
	cout << "30 in position: " << l.getIndexOf(30) << " (Found: " << l.contains(30) << ")" << endl;
	cout << "10 in position: " << l.getIndexOf(10) << " (Found: " << l.contains(10) << ")" << endl;

	l.removeHead();
	l.displayList();
	cout << "\nCurrent size: " << l.getSize() << endl;
	l.removeHead();
	l.displayList();
	cout << "\nCurrent size: " << l.getSize() << endl;
	l.removeTail();
	l.displayList();
	cout << "\nCurrent size: " << l.getSize() << endl;

	return 0;
}

#endif
