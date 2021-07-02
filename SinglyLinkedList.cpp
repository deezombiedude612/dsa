#ifndef SINGLYLINKEDLIST_CPP
#define SINGLYLINKEDLIST_CPP

#include <iostream>

using namespace std;

/**
 * @brief Node structure to be used in SLL
 */
struct Node {
	int item;
	Node *next;
};

class SLL {
 private:
	Node *head;
	bool isEmpty();

 public:
	SLL();
	SLL(const int item);
	~SLL();
	unsigned int getSize();

	void addHead(int newItem);
	void addTail(int newItem);
	void addNodeAt(int item, unsigned int index);
	void removeHead();
	void removeTail();
	void removeNodeAt(unsigned int index);
	void displayList();
	int getIndexOf(int searchedItem);
	bool contains(int searchedItem);
};

/**
 * @brief Check if SLL is empty
 * 
 * @return true 
 * @return false 
 */
bool SLL::isEmpty() {
	return head == NULL;
}

SLL::SLL() {
	head = NULL;
}

SLL::SLL(const int item) {
	addHead(item);
}

SLL::~SLL() {
	while (getSize() > 0) removeHead();
	head = NULL;
	delete head;
}

/**
 * @brief Retrieve size of SLL (number of Nodes currently in SLL)
 * 
 * @return unsigned int 
 */
unsigned int SLL::getSize() {
	if (isEmpty()) return 0;

	int numNodes;
	Node *cur = head;
	for (numNodes = 0; cur; cur = cur->next) numNodes++;

	cur = NULL;
	delete cur;

	return numNodes;
}

/**
 * @brief Add a new head Node in SLL
 * 
 * @param newItem 
 */
void SLL::addHead(int newItem) {
	Node *newHead = new Node;
	newHead->item = newItem;

	if (isEmpty())
		newHead->next = NULL;
	else
		newHead->next = head;

	head = newHead;

	newHead = NULL;
	delete newHead;

	cout << "\nInserted new head to SLL: " << newItem << endl;
}

/**
 * @brief Add a new tail Node in SLL
 * 
 * @param newItem - New item to be added into SLL
 */
void SLL::addTail(int newItem) {
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

		cur = NULL;
		delete cur;

		newNode = NULL;
		delete newNode;

		cout << "\nInserted new tail to SLL: " << newItem << endl;
	}
}

/**
 * @brief Add a new Node to SLL at given index
 * 
 * @param newItem - New item to be added into SLL
 * @param index - Position in SLL where new item is to occupy
 */
void SLL::addNodeAt(int newItem, unsigned int index) {
	if (index == 0)
		addHead(newItem);
	else if (index < getSize()) {
		Node *newNode = new Node;
		newNode->item = newItem;

		Node *cur = head;
		for (unsigned int i = 1; i < index; ++i) cur = cur->next;
		newNode->next = cur->next;
		cur->next = newNode;

		cur = NULL;
		delete cur;

		cout << "\nInserted new Node to SLL: " << newItem << " (at index " << index << ")\n";

	} else
		cout << "Illegal array index!\n";
}

/**
 * @brief Removes current head Node in SLL
 */
void SLL::removeHead() {
	if (isEmpty())
		cout << "No more nodes to delete!\n";
	else if (!(head->next)) {
		cout << "\nDeleting head from SLL: " << head->item << endl;
		head = NULL;
		delete head;

		cout << "SLL is now empty.\n";
	} else {
		Node *oldHead = head;
		head = oldHead->next;

		cout << "\nDeleting head from SLL: " << oldHead->item << endl;
		delete oldHead;
		oldHead = NULL;
	}
}

/**
 * @brief Removes current tail Node in SLL
 */
void SLL::removeTail() {
	if (isEmpty())
		cout << "No more nodes to delete!\n";
	else if (!(head->next))
		removeHead();
	else {
		Node *cur = head;
		while (cur->next->next) cur = cur->next;

		cout << "\nDeleting tail from SLL: " << cur->next->item << endl;
		delete cur->next;
		cur->next = NULL;
	}
}

/**
 * @brief Removes Node from SLL at given index
 * 
 * @param index - Index in SLL whose item is to be removed
 */
void SLL::removeNodeAt(unsigned int index) {
	if (isEmpty())
		cout << "No more nodes to delete!\n";
	else if (!(head->next))
		removeHead();
	else if (index < getSize()) {
		Node *cur = head;
		for (unsigned int i = 1; i < index; ++i) cur = cur->next;

		Node *oldNode = cur->next;
		cur->next = oldNode->next;

		cout << "\nDeleting Node from SLL: " << oldNode->item << " (at index " << index << ")\n";
		delete oldNode;
		oldNode = NULL;

		cur = NULL;
		delete cur;
	} else
		cout << "Illegal array index!\n";
}

/**
 * @brief Display full list
 */
void SLL::displayList() {
	Node *cur = head;
	if (isEmpty()) {
		cout << "SLL is currently empty.\n";
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
 * @brief Retrieves index of item's first occurrence in SLL
 * Returns -1 if not found
 * Best Case Complexity: O(1)
 * Worst Case Complexity: O(n)
 * 
 * @param searchedItem - Item to be searched in SLL
 * @return int 
 */
int SLL::getIndexOf(int searchedItem) {
	int index;

	Node *cur = head;
	for (index = 0; cur; index++, cur = cur->next) {
		if (cur->item == searchedItem) return index;
	}

	return -1;
}

/**
 * @brief Returns true if item is found in SLL, false otherwise
 * 
 * @param searchedItem - Item to be searched in SLL
 * @return true 
 * @return false 
 */
bool SLL::contains(int searchedItem) {
	return getIndexOf(searchedItem) != -1;
}

int main(int argc, char **argv) {
	SLL l;
	// SLL l(0);
	l.displayList();
	cout << "Size: " << l.getSize() << endl;
	l.addHead(20);
	l.displayList();
	cout << "Size: " << l.getSize() << endl;
	l.addHead(10);
	l.displayList();
	cout << "Size: " << l.getSize() << endl;
	l.addTail(30);
	l.displayList();
	cout << "Size: " << l.getSize() << endl;
	l.addNodeAt(50, 2);
	l.displayList();
	cout << "Size: " << l.getSize() << endl;
	l.addNodeAt(60, 7);
	cout << "Size: " << l.getSize() << endl;

	cout << "20 in position: " << l.getIndexOf(20) << " (Found: " << l.contains(20) << ")" << endl;
	cout << "40 in position: " << l.getIndexOf(40) << " (Found: " << l.contains(40) << ")" << endl;

	l.removeHead();
	cout << "Size: " << l.getSize() << endl;
	l.removeTail();
	l.displayList();
	cout << "Size: " << l.getSize() << endl;

	l.addTail(60);
	l.addTail(70);
	l.addTail(80);
	l.addTail(90);
	l.addTail(100);
	l.displayList();

	l.addNodeAt(40, 1);
	l.displayList();

	l.removeNodeAt(2);
	l.displayList();

	return 0;
}

#endif
