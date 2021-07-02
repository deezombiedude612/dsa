#ifndef DOUBLYLINKEDLIST_CPP
#define DOUBLYLINKEDLIST_CPP

#include <iostream>

using namespace std;

/**
 * @brief Node structure to be used in DLL
 */
struct Node {
	int item;
	Node *next;
	Node *prev;
};

class DLL {
 private:
	Node *head;
	bool isEmpty();

 public:
	DLL();
	DLL(int item);
	~DLL();
	unsigned int getSize();

	void addHead(int newItem);
	void addTail(int newItem);
	void addNodeAt(int item, unsigned int index);
	void removeHead();
	void removeTail();
	void removeNodeAt(unsigned int index);
	void displayList();
	void displayReverse();
	int getIndexOf(int searchedItem);
	bool contains(int searchedItem);
};

/**
 * @brief Check if DLL is empty
 * 
 * @return true 
 * @return false 
 */
bool DLL::isEmpty() {
	return head == NULL;
}

DLL::DLL() {
	head = NULL;
}

DLL::DLL(int item) {
	addHead(item);
}

DLL::~DLL() {
	while (getSize() > 0) removeHead();
	head = NULL;
	delete head;
}

/**
 * @brief Retrieve size of DLL (number of Nodes currently in DLL)
 * 
 * @return unsigned int 
 */
unsigned int DLL::getSize() {
	if (isEmpty()) return 0;

	int numNodes;
	Node *cur = head;
	for (numNodes = 0; cur; cur = cur->next) numNodes++;

	cur = NULL;
	delete cur;

	return numNodes;
}

/**
 * @brief Add a new head Node in the DLL
 * 
 * @param newItem - New item to be added into DLL
 */
void DLL::addHead(int newItem) {
	Node *newHead = new Node;
	newHead->item = newItem;
	newHead->prev = NULL;

	if (isEmpty())
		newHead->next = NULL;
	else {
		newHead->next = head;
		head->prev = newHead;
	}

	head = newHead;

	newHead = NULL;
	delete newHead;

	cout << "\nInserted new head to DLL: " << newItem << endl;
}

/**
 * @brief Add a new tail Node in the DLL
 * 
 * @param newItem - New item to be added into DLL
 */
void DLL::addTail(int newItem) {
	if (isEmpty())
		addHead(newItem);
	else {
		Node *newNode = new Node;
		newNode->item = newItem;
		newNode->next = NULL;

		Node *cur = head;
		while (cur->next)
			cur = cur->next;

		cur->next = newNode;
		newNode->prev = cur;

		cur = NULL;
		delete cur;

		newNode = NULL;
		delete newNode;

		cout << "\nInserted new tail to DLL: " << newItem << endl;
	}
}

/**
 * @brief Add a new Node to DLL at given index
 * 
 * @param newItem - New item to be added into DLL
 * @param index - Position in DLL where new item is to occupy
 */
void DLL::addNodeAt(int newItem, unsigned int index) {
	if (index == 0)
		addHead(newItem);
	else if (index < getSize()) {
		Node *newNode = new Node;
		newNode->item = newItem;

		Node *cur = head;
		for (unsigned int i = 1; i < index; ++i) cur = cur->next;
		cur->next->prev = newNode;
		newNode->next = cur->next;
		newNode->prev = cur;
		cur->next = newNode;

		cur = NULL;
		delete cur;

		newNode = NULL;
		delete newNode;

		cout << "\nInserted new Node to DLL: " << newItem << " (at index " << index << ")\n";

	} else
		cout << "Illegal array index!\n";
}

/**
 * @brief Removes current head Node in the DLL
 */
void DLL::removeHead() {
	if (isEmpty())
		cout << "No more nodes to delete!\n";
	else if (!(head->next)) {
		cout << "\nDeleting head from DLL: " << head->item << endl;
		head = NULL;
		delete head;

		cout << "DLL is now empty.\n";
	} else {
		Node *oldHead = head;
		head = oldHead->next;
		head->prev = NULL;

		cout << "\nDeleting head from DLL: " << oldHead->item << endl;
		delete oldHead;
		oldHead = NULL;
	}
}

/**
 * @brief Removes current tail Node in the DLL
 */
void DLL::removeTail() {
	if (isEmpty())
		cout << "No more nodes to delete!\n";
	else if (!(head->next))
		removeHead();
	else {
		Node *cur = head;
		while (cur->next->next) cur = cur->next;
		cur->next->prev = NULL;

		cout << "\nDeleting tail from DLL: " << cur->next->item << endl;
		delete cur->next;
		cur->next = NULL;
	}
}

/**
 * @brief Removes Node from DLL at given index
 * 
 * @param index - Index in DLL whose item is to be removed
 */
void DLL::removeNodeAt(unsigned int index) {
	if (isEmpty())
		cout << "No more nodes to delete!\n";
	else if (!(head->next))
		removeHead();
	else if (index < getSize()) {
		Node *cur = head;
		for (unsigned int i = 1; i < index; ++i) cur = cur->next;

		Node *oldNode = cur->next;
		cur->next = oldNode->next;
		oldNode->next->prev = cur;

		oldNode->next = NULL;
		oldNode->prev = NULL;

		cout << "\nDeleting Node from DLL: " << oldNode->item << " (at index " << index << ")\n";
		delete oldNode;
		oldNode = NULL;
	} else
		cout << "Illegal array index!\n";
}

/**
 * @brief Display full list
 */
void DLL::displayList() {
	Node *cur = head;
	if (isEmpty()) {
		cout << "DLL is currently empty.\n";
		return;
	}

	while (cur) {
		cout << cur->item << " ";
		cur = cur->next;
	}

	cout << "END\n";
	delete cur;
}

/**
 * @brief Display full list in reverse
 */
void DLL::displayReverse() {
	Node *cur = head;
	if (isEmpty()) {
		cout << "DLL is currently empty.\n";
		return;
	}

	while (cur->next) cur = cur->next;

	while (cur) {
		cout << cur->item << " ";
		cur = cur->prev;
	}

	cout << "END\n";
	delete cur;
}

/**
 * @brief Retrieve index of first occurrence of item in DLL
 * Returns -1 if not found
 * 
 * @param searchedItem - Item to be searched in DLL
 * @return int 
 */
int DLL::getIndexOf(int searchedItem) {
	int index;

	Node *cur = head;
	for (index = 0; cur; index++, cur = cur->next) {
		if (cur->item == searchedItem) return index;
	}

	return -1;
}

/**
 * @brief Returns true if item is found in DLL, false otherwise
 * 
 * @param searchedItem - Item to be searched in DLL
 * @return true 
 * @return false 
 */
bool DLL::contains(int searchedItem) {
	return getIndexOf(searchedItem) != -1;
}

int main(int argc, char **argv) {
	DLL l(10);
	cout << "Size of DLL: " << l.getSize() << endl;
	l.displayList();
	l.displayReverse();
	l.addHead(9);
	cout << "Size of DLL: " << l.getSize() << endl;
	l.displayList();
	l.displayReverse();
	l.addHead(8);
	cout << "Size of DLL: " << l.getSize() << endl;
	l.displayList();
	l.displayReverse();
	l.addTail(11);
	cout << "Size of DLL: " << l.getSize() << endl;
	l.displayList();
	l.displayReverse();
	l.addTail(12);
	cout << "Size of DLL: " << l.getSize() << endl;
	l.displayList();
	l.displayReverse();
	l.addNodeAt(10, 2);
	cout << "Size of DLL: " << l.getSize() << endl;
	l.displayList();
	l.displayReverse();
	l.removeTail();
	cout << "Size of DLL: " << l.getSize() << endl;
	l.displayList();
	l.displayReverse();
	l.removeNodeAt(3);
	cout << "Size of DLL: " << l.getSize() << endl;
	l.displayList();
	l.displayReverse();

	return 0;
}

#endif
