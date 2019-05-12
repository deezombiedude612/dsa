// ver 041016_1245
#include <iostream>
using namespace std;

// Define the structure of a single linked list
struct Node {
	int data;
	Node *next;
};

// Initialize the first node created in a linked list
void initNode(Node *tmpHead, int n) {
	tmpHead->data = n;
	tmpHead->next = NULL;
}

// Display all nodes in a linked list
void displayList(Node *cur) {
	while (cur) {  // or while (cur != NULL)
		cout << cur->data << " ";
		cur = cur->next;
	}
	cout << endl;
}

// Add a new node at the end of a linked list
void addNode(Node *cur, int n) {
	Node *newNode = new Node;
	newNode->data = n;
	newNode->next = NULL;
	while (cur->next)  // or while (cur->next != NULL)
		cur = cur->next;
	cur->next = newNode;
}

// Add a new node at the front of a linked list
void addFront(Node **tmpHead, int n) {
	Node *newNode = new Node;
	newNode->data = n;
	newNode->next = *tmpHead;
	*tmpHead = newNode;
}

// Remove a node from the front of a linked list
void removeFront(Node **tmpHead) {
	if ((*tmpHead)->next == NULL)
		cout << "Single Node! removeFront() aborted!\n";
	else {
		Node *oldHead= *tmpHead;
		*tmpHead = oldHead->next;
		delete oldHead;
	}
}

// Remove a node at the end of a linked list
void removeNode(Node *cur) {
	if (cur->next == NULL)
		cout << "Single Node! renoveNode() aborted!\n";
	else {
		while (cur->next->next)
			cur = cur->next;
		delete cur->next;
		cur->next = NULL;
	}
}

// Return total nodes counted in a linked list 
int getTotNodes(Node *cur) {
	int count = 0;
	while (cur) {  // or while (cur != NULL)
		count++;
		cur = cur->next;
	}
	return count;
}

// Return a position of a node which content matches 
// the searched value. Position 1 for the first node.
// Return -1 if matching value is not found.
int getSearchPos(Node *cur, int searchedData) {
	int pos = 0;
	while (cur) {  // or while (cur != NULL)
		pos++;
		if (cur->data == searchedData) 
			break;
		cur = cur->next;
	}
	if (cur == NULL)
		pos = -1;
	return pos;
}

// Add a new node at any valid position. Position 1 is the first node.
void addNodeAt(int pos, Node **tmpHead, int n) {
	if (pos == 1)
		addFront(tmpHead, n);
	else if ((pos > 1) && (pos <= getTotNodes(*tmpHead))) {
		Node *newNode = new Node;
		newNode->data = n;
		Node *cur = *tmpHead;
		int k = 1;
		while (k < (pos-1)) {
			k++;
			cur = cur->next;
		}
		newNode->next = cur->next;
		cur->next = newNode;
	}
	else
		cout << "Position to add is out of bound!\n";
}

// Remove a node at any valid position. Position 1 is the first node.
void removeNodeAt(int pos, Node **tmpHead) {
	if ((*tmpHead)->next == NULL)
		cout << "Single Node! removeNodeAt() aborted!\n";
	else if (pos == 1) 
		removeFront(tmpHead);
	else if ((pos > 1) && (pos <= getTotNodes(*tmpHead))) {
		Node *cur = *tmpHead;
		int k = 1;
		while (k < (pos-1)) {
			k++;
			cur = cur->next;
		}
		Node *oldNode = cur->next;
		cur->next = oldNode->next;
		delete oldNode;
	}
	else
		cout << "Position to add is out of bound!\n";
}


void main() {
	Node *head = new Node;
	initNode(head, 22);		// list becomes 22
	addNode(head, 33);		// list becomes 22 33
	addNode(head, 44);		// list becomes 22 33 44
	addFront(&head, 11);		// list becomes 11 22 33 44
	displayList(head);
	removeFront(&head);		// list becomes 22 33 44
	removeNode(head);		// list becomes 22 33
	displayList(head);
	cout << "Total nodes is " << getTotNodes(head) << endl;
	cout << "Data 33 position is " << getSearchPos(head, 33) << endl;
	addNodeAt(2, &head, 99);	// list becomes 22 99 33
	displayList(head);			
	removeNodeAt(3, &head);		// list becomes 22 99
	displayList(head);
}

