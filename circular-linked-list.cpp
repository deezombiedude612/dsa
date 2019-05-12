#include <iostream>
using namespace std;

// define the structure of a circular linked List (CLL)
struct Node {
	int data;
	Node *next;
};

// initialize the first node created in a CLL
void initNode(Node *tmpHead, int n) {
	tmpHead->data = n;
	tmpHead->next = tmpHead;
}

// display all nodes in the a CLL
void displayNodes(Node *tmpHead) {
	Node *cur = tmpHead;
	do {
		cout << cur->data << " ";
		cur = cur->next;
	} while (cur != tmpHead);
	cout << endl;
}

// add a new node at the end of a CLL (size > 0)
void addNode(Node *tmpHead, int n) {
	Node *newNode = new Node;
	newNode->data = n;
	newNode->next = tmpHead;
	Node *cur = tmpHead;
	do {
		cur = cur->next;
	} while (cur->next != tmpHead);
	cur->next = newNode;
}

// remove a node at the end of a CLL
void removeNode(Node *tmpHead) {
	if ((tmpHead)->next == tmpHead)
		cout << "RemoveNode() of a single node not allowed!\n";
	else {
		Node *cur = tmpHead;
		do {
			cur = cur->next;
		} while (cur->next->next != tmpHead);
		delete cur->next;
		cur->next = tmpHead;
	}
}

// add a new node at the front of a CLL (size > 0)
void addFront(Node **tmpHead, int n) {
	Node *newNode = new Node;
	newNode->data = n;
	newNode->next = *tmpHead;
	Node *cur = newNode->next;
	do {
		cur = cur->next;
	} while (cur->next != *tmpHead);
	cur->next = newNode;
	*tmpHead = newNode;
}

// remove a node at the front of a CLL
void removeFront(Node **tmpHead) {
	if ((*tmpHead)->next == *tmpHead)
		cout << "RemoveFront() of a single node not allowed!\n";
	else {
		Node *cur = *tmpHead;
		do {
			cur = cur->next;
		} while (cur->next != *tmpHead);
		*tmpHead = (*tmpHead)->next;
		delete cur->next;
		cur->next = *tmpHead;
	}
}
	
void main() {
	Node *head = new Node;
	initNode(head, 33); 
	addNode(head, 44); 
	addNode(head, 55);
	displayNodes(head);		// Should display 33 44 55
	removeNode(head);
	displayNodes(head);		// Should display 33 44
	removeNode(head);
	displayNodes(head);		// Should display 33
	removeNode(head);		   // This should be disallowed
	displayNodes(head);		// Should display 33
	addFront(&head, 22);	
	displayNodes(head);		// Should display 22 33
	removeFront(&head);	
	displayNodes(head);		// Should display 33
	removeFront(&head);		// This should be disallowed
	displayNodes(head);		// Should display 33
}