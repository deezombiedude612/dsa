#ifndef DYNAMICARRAY_CPP
#define DYNAMICARRAY_CPP

#include <iostream>

using namespace std;

class DynamicArray {
 private:
	int *items;
	unsigned int cap;
	unsigned int size;

	void enlargeArray();

 public:
	DynamicArray(unsigned int capacity);
	~DynamicArray();
	int getCap();
	void setCap(unsigned int newCapacity);
	unsigned int getSize();

	void print();
	void insert(int item);
	void insertAt(int item, unsigned int index);
	void removeAt(unsigned int index);
	int indexOf(int item);
	void itemAt(unsigned int index);
	void reverse();
	void rotate(int offset);
};

/**
 * @brief Doubles array size if cap has already been reached
 */
void DynamicArray::enlargeArray() {
	if (cap == size) {
		int *newItems = new int[cap * 2];

		for (unsigned int i = 0; i < cap; i++)
			newItems[i] = items[i];

		items = newItems;

		// dereference temporary pointer used to refer to new array item
		newItems = NULL;
		delete[] newItems;

		cout << "Array cap has been expanded to size " << cap * 2 << endl;
		cap *= 2;
	}
}

DynamicArray::DynamicArray(unsigned int capacity) {
	items = new int[capacity];
	// cap = capacity;
	setCap(capacity);
	size = 0;
}

DynamicArray::~DynamicArray() {
	while (getSize() > 0) removeAt(getSize() - 1);
	items = NULL;
	delete[] items;
}

/**
 * @brief Prints array contents
 * Complexity: O(n)
 */
void DynamicArray::print() {
	if (size >= 1) {
		for (unsigned int i = 0; i < size; ++i)
			cout << items[i] << " ";

		cout << "END\n";
	} else
		cout << "Array is currently empty.\n";
}

/**
 * @brief Add new item to the end of the array
 * 
 * @param item - New item to be added into array
 */
void DynamicArray::insert(int item) {
	enlargeArray();	 // enlarge array if cap has already been reached
	cout << "\nOccupying size: " << size << endl;

	// Add the new item at the end
	items[size] = item;
	size++;
	cout << "New size: " << size << endl;
}

/**
 * @brief Retrieves array's maximum capacity
 * 
 * @return int 
 */
int DynamicArray::getCap() {
	return cap;
}

/**
 * @brief Sets array's maximum capacity
 * Maximum capacity will always be set to 1 at minimum
 * 
 * @param newCapacity - Array's new maximum capacity
 */
void DynamicArray::setCap(unsigned int newCapacity) {
	if (newCapacity > 0)
		cap = newCapacity;
	else
		cap = 1;
}

/**
 * @brief Retrieves array's current filled capacity
 * 
 * @return unsigned int 
 */
unsigned int DynamicArray::getSize() {
	return size;
}

/**
 * @brief Add new item to a valid position in the array
 * 
 * @param item - New item to be added into array
 * @param index - Index in array the new item is to occupy
 */
void DynamicArray::insertAt(int item, unsigned int index) {
	if (index < 0 || index > size) {
		cout << "Illegal array index!\n";
		return;
	}

	enlargeArray();

	for (unsigned int i = size - 1; i >= index; --i)
		items[i + 1] = items[i];

	items[index] = item;
	size++;
}

/**
 * @brief Remove item from given valid index in array
 * 
 * @param index - Index in array whose item is to be removed
 */
void DynamicArray::removeAt(unsigned int index) {
	if (index < 0 || index >= size) {
		cout << "Illegal array index!\n";
		return;
	}

	cout << "\nRemoving item: " << items[index] << endl;

	for (unsigned int i = index; i < size; ++i)
		items[i] = items[i + 1];

	size--;

	if (getSize() == 0)
		cout << "Array is now empty.\n";
	else
		cout << "New size: " << getSize() << endl;
}

/**
 * @brief Retrieves index of item if exists in array, -1 otherwise.
 * Best Case Complexity: O(1)
 * Worse Case Complexity: O(n)
 * 
 * @param item - Item whose index is to be retrieved
 * @return int 
 */
int DynamicArray::indexOf(int item) {
	for (unsigned int i = 0; i < size; ++i) {
		if (items[i] == item) return i;
	}

	return -1;
}

/**
 * @brief Retrieves array item at given index
 * 
 * @param index - Index whose item is to be retrieved
 */
void DynamicArray::itemAt(unsigned int index) {
	if (index < size)
		cout << "Item at index " << index << " is " << items[index] << endl;
	else
		cout << "Illegal array index!\n";
}

/**
 * @brief Reverse array contents
 */
void DynamicArray::reverse() {
	int *newItems = new int[size];

	for (unsigned int i = 0; i < size; i++)
		newItems[i] = items[size - i - 1];

	items = newItems;

	// dereference temporary pointer used to refer to new array item
	newItems = NULL;
	delete[] newItems;
}

/**
 * @brief Rotates array contents based off a given offset
 * 
 * @param offset - Offset rotation
 */
void DynamicArray::rotate(int offset) {
	cout << "\nRotating with offset " << offset << "..\n";

	// reduce offset to between 0 and size
	if (offset < 0) {
		// int sizeMultiple = ((int)(-offset * 0.2) + 1);
		// offset += (getSize() * sizeMultiple);

		offset %= getSize();
		--offset;
	} else
		offset %= getSize();

	// if offset is reduced to 0, do nothing
	if (offset == 0) return;

	int *newItems = new int[size];

	for (unsigned int i = 0; i < size; ++i)
		newItems[i] = items[(i + offset) % size];

	items = newItems;

	// dereference temporary pointer used to refer to new array item
	newItems = NULL;
	delete[] newItems;
}

int main(int argc, char **argv) {
	DynamicArray da(3);
	da.print();
	cout << endl;
	da.insert(10);
	da.print();
	cout << endl;
	da.insert(20);
	da.print();
	da.insert(30);
	da.print();
	da.insert(40);
	da.print();
	da.insert(50);
	da.print();

	cout << "\nIndex of first occurrence of 10: " << da.indexOf(10) << endl;
	da.removeAt(0);
	da.print();
	cout << "\nIndex of first occurrence of 10: " << da.indexOf(10) << endl;

	da.insertAt(0, 1);
	da.print();
	da.reverse();
	da.print();

	da.itemAt(2);

	da.rotate(-5);
	da.print();

	da.itemAt(2);
	da.itemAt(3);
	da.itemAt(6);

	return 0;
}

#endif
