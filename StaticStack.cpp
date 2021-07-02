#ifndef STATICSTACK_CPP
#define STATICSTACK_CPP

#include <iostream>
#define MAX_CAP 5	 // Size of stack

using namespace std;

class StaticStack {
 private:
	int items[MAX_CAP];
	unsigned int count;

 public:
	StaticStack();
	unsigned int getCount();

	bool isEmpty();
	bool isFull();
	void displayStack();
	void push(int newItem);
	int pop();
	int peek();
	void invert();
};

StaticStack::StaticStack() {
	count = 0;
}

/**
 * @brief Retrieves number of occupying items in stack
 * 
 * @return unsigned int 
 */
unsigned int StaticStack::getCount() {
	return count;
}

/**
 * @brief Checks if stack is empty
 * 
 * @return true 
 * @return false 
 */
bool StaticStack::isEmpty() {
	return count == 0;
}

/**
 * @brief Checks if stack is full
 * 
 * @return true 
 * @return false 
 */
bool StaticStack::isFull() {
	return count == MAX_CAP;
}

/**
 * @brief Displays all contents in stack
 */
void StaticStack::displayStack() {
	if (isEmpty())
		cout << "Stack is currently empty.\n";
	else {
		for (unsigned int i = 0; i < count; ++i) cout << items[i] << " ";
		cout << "TOP\n";
	}
}

/**
 * @brief Pushes item to stack
 * 
 * @param newItem - New item to be added into stack
 */
void StaticStack::push(int newItem) {
	if (isFull())
		cout << "Stack too full! Remove some items first.\n";
	else {
		items[count] = newItem;
		count++;
	}
}

/**
 * @brief Pops item from stack
 * 
 * @return int 
 */
int StaticStack::pop() {
	if (isEmpty()) {
		cout << "Stack is currently empty.\n";
		return -1;
	}

	int poppedItem = items[count];
	count--;

	return poppedItem;
}

/**
 * @brief Peeks top item in stack
 * 
 * @return int 
 */
int StaticStack::peek() {
	return items[count - 1];
}

/**
 * @brief Inverts stack contents
 */
void StaticStack::invert() {
	int newItems[MAX_CAP];
	for (unsigned int i = 0; i < count; ++i) newItems[i] = items[count - i - 1];
	for (unsigned int i = 0; i < count; ++i) items[i] = newItems[i];
}

int main(int argc, char **argv) {
	StaticStack s;
	cout << "Empty? " << s.isEmpty() << endl;
	cout << "Full? " << s.isFull() << endl;
	s.displayStack();
	cout << "Size of stack: " << s.getCount() << endl;
	s.push(1);
	s.displayStack();
	cout << "Size of stack: " << s.getCount() << endl;
	s.push(2);
	s.displayStack();
	cout << "Size of stack: " << s.getCount() << endl;
	s.push(10);
	s.push(20);
	s.push(30);
	s.push(40);
	s.displayStack();
	s.invert();
	s.displayStack();
	cout << "Top item: " << s.peek() << endl;
	cout << "Size of stack: " << s.getCount() << endl;
	cout << "Popped " << s.pop() << endl;
	s.displayStack();
	cout << "Top item: " << s.peek() << endl;
	return 0;
}

#endif
