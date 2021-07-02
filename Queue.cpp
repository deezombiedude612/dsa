#ifndef QUEUE_CPP
#define QUEUE_CPP

#include <iostream>

using namespace std;

/**
 * @brief Node structure to be used in Queue
 */
struct Node {
	int item;
	Node *next;
};

class Queue {
 private:
	Node *head;

 public:
	Queue();
	Queue(const int item);
	~Queue();
	unsigned int getSize();

	bool isEmpty();
	void enqueue(int newItem);
	void dequeue();
	void displayList();
	int getIndexOf(int searchedItem);
	bool contains(int searchedItem);
};

Queue::Queue() {
	head = NULL;
}

Queue::Queue(const int item) {
	enqueue(item);
}

Queue::~Queue() {
	while (getSize() > 0) dequeue();
	head = NULL;
	delete head;
}

/**
 * @brief Retrieve size of queue (number of Nodes currently in queue)
 * 
 * @return unsigned int 
 */
unsigned int Queue::getSize() {
	if (isEmpty()) return 0;

	int numNodes;
	Node *cur = head;
	for (numNodes = 0; cur; cur = cur->next) numNodes++;

	cur = NULL;
	delete cur;

	return numNodes;
}

/**
 * @brief Check if queue is empty
 * 
 * @return true 
 * @return false 
 */
bool Queue::isEmpty() {
	return head == NULL;
}

/**
 * @brief Add a new tail Node in queue
 * 
 * @param newItem 
 */
void Queue::enqueue(int newItem) {
	Node *newNode = new Node;
	newNode->item = newItem;
	newNode->next = NULL;

	if (isEmpty()) {
		head = newNode;

		cout << "\nStarted new queue with: " << newItem << endl;
	} else {
		Node *cur = head;
		while (cur->next)
			cur = cur->next;

		cur->next = newNode;

		cur = NULL;
		delete cur;

		cout << "\nInserted new tail to queue: " << newItem << endl;
	}
	newNode = NULL;
	delete newNode;
}

/**
 * @brief Removes current head Node in queue
 */
void Queue::dequeue() {
	if (isEmpty())
		cout << "No more nodes to delete!\n";
	else if (!(head->next)) {
		cout << "\nDeleting head from queue: " << head->item << endl;
		head = NULL;
		delete head;

		cout << "Queue is now empty.\n";
	} else {
		Node *oldHead = head;
		head = oldHead->next;

		cout << "\nDeleting head from queue: " << oldHead->item << endl;
		delete oldHead;
		oldHead = NULL;
	}
}

/**
 * @brief Display full list
 */
void Queue::displayList() {
	Node *cur = head;
	if (isEmpty()) {
		cout << "Queue is currently empty.\n";
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
 * @brief Retrieves index of item's first occurrence in queue
 * Returns -1 if not found
 * 
 * @param searchedItem - Item to be searched in queue
 * @return int 
 */
int Queue::getIndexOf(int searchedItem) {
	int index;

	Node *cur = head;
	for (index = 0; cur; index++, cur = cur->next) {
		if (cur->item == searchedItem) return index;
	}

	return -1;
}

/**
 * @brief Returns true if item is found in queue, false otherwise
 * 
 * @param searchedItem - Item to be searched in queue
 * @return true 
 * @return false 
 */
bool Queue::contains(int searchedItem) {
	return getIndexOf(searchedItem) != -1;
}

int main(int argc, char **argv) {
	// Queue l;
	Queue l(0);
	l.displayList();
	cout << "Size: " << l.getSize() << endl;
	l.enqueue(10);
	l.displayList();
	cout << "Size: " << l.getSize() << endl;
	l.enqueue(20);
	l.displayList();
	cout << "Size: " << l.getSize() << endl;
	l.enqueue(30);
	l.displayList();
	cout << "Size: " << l.getSize() << endl;
	l.enqueue(50);
	l.displayList();
	cout << "Size: " << l.getSize() << endl;

	cout << "20 in position: " << l.getIndexOf(20) << " (Found: " << l.contains(20) << ")" << endl;
	cout << "40 in position: " << l.getIndexOf(40) << " (Found: " << l.contains(40) << ")" << endl;

	l.dequeue();
	cout << "Size: " << l.getSize() << endl;
	l.displayList();
	l.dequeue();
	cout << "Size: " << l.getSize() << endl;
	l.displayList();

	l.enqueue(60);
	l.enqueue(70);
	l.enqueue(80);
	l.enqueue(90);
	l.enqueue(100);
	l.displayList();

	return 0;
}

#endif
