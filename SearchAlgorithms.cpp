#ifndef SEARCHALGORITHMS_CPP
#define SEARCHALGORITHMS_CPP

#include <cmath>
#include <iostream>

using namespace std;

/**
 * @brief Linear Search
 * 
 * @param items - Array of items to be searched
 * @param size - Size of searched array
 * @param target - Target value to be searched in array
 * @return int 
 */
int linearSearch(int items[], unsigned int size, int target) {
	// Iterate through array to look for item
	for (unsigned int i = 0; i < size; ++i)
		if (items[i] == target) return i;

	return -1;
}

/**
 * @brief Binary Search by Recursion
 * 
 * @param items - Array of items to be searched
 * @param size - Size of searched array
 * @param target - Target value to be searched in array
 * @param left - Left index
 * @param right - Right index
 * @return int 
 */
int binarySearchRec(int items[], unsigned int size, int target, int left, int right) {
	if (right < left) return -1;	// target is not found if left index crosses right index

	int middle = (left + right) / 2;	// middle item

	if (items[middle] == target) return middle;	 // if middle item is target

	// if target is on the left side of middle item
	if (target < items[middle]) return binarySearchRec(items, middle, target, left, middle - 1);

	// if target is on the right side of middle item
	return binarySearchRec(items, right + 1, target, middle + 1, right);
}

/**
 * @brief Short-hand Binary Search by Recursion function
 * 
 * @param items - Array of items to be searched
 * @param size - Size of searched array
 * @param target - Target value to be searched in array
 * @return int 
 */
int binarySearchRec(int items[], unsigned int size, int target) {
	return binarySearchRec(items, size, target, 0, size - 1);
}

/**
 * @brief Binary Search by Iteration
 * 
 * @param items - Array of items to be searched
 * @param size - Size of searched array
 * @param target - Target value to be searched in array
 * @return int 
 */
int binarySearchIte(int items[], unsigned int size, int target) {
	int left = 0;					 // leftmost index
	int right = size - 1;	 // rightmost index

	while (left <= right) {
		int middle = (left + right) / 2;	// middle item

		if (items[middle] == target) return middle;	 // if middle item is target

		if (target < items[middle])
			right = middle - 1;	 // if target is on left side of middle item
		else
			left = middle + 1;	// if target is on right side of middle item
	}

	return -1;	// target is not found
}

/**
 * @brief Ternary Search (done by Recursion)
 * 
 * @param items - Array of items to be searched
 * @param size - Size of searched array
 * @param target - Target value to be searched in array
 * @param left - Left index
 * @param right - Right index
 * @return int 
 */
int ternarySearch(int items[], unsigned int size, int target, int left, int right) {
	if (left > right) return -1;	// target is not found if left index crosses right index

	int partitionSize = (right - left) / 3;	 // array is split into 3
	int mid1 = left + partitionSize;				 // left partition
	int mid2 = right - partitionSize;				 // right partition

	if (items[mid1] == target) return mid1;	 // if middle item in left partition is the target
	if (items[mid2] == target) return mid2;	 // if middle item in right partition is the target

	// target is in left partition
	if (target < items[mid1]) return ternarySearch(items, mid1, target, left, mid1 - 1);

	// target is in right partition
	if (target > items[mid2]) return ternarySearch(items, right + 1, target, mid2 + 1, right);

	// target is in middle parition
	return ternarySearch(items, mid2, target, mid1 + 1, mid2 - 1);
}

/**
 * @brief Short-hand Ternary Search function
 * 
 * @param items - Array of items to be searched
 * @param size - Size of searched array
 * @param target - Target value to be searched in array
 * @return int 
 */
int ternarySearch(int items[], unsigned int size, int target) {
	return ternarySearch(items, size, target, 0, size - 1);
}

/**
 * @brief Jump Search
 * 
 * @param items - Array of items to be searched
 * @param size - Size of searched array
 * @param target - Target value to be searched in array
 * @return int 
 */
int jumpSearch(int items[], unsigned int size, int target) {
	unsigned int blockSize = (int)sqrt(size);	 // retrieve block of a size equal to square root of item array size
	unsigned int start = 0;
	unsigned int next = blockSize;

	// traverse items array block by block
	while (start < size && items[next - 1] < target) {
		start = next;

		next += blockSize;
		if (next > size) next = size;	 // for last block, if "next" goes out of bounds, pull it to last item index
	}

	// perform linear search in block containing target
	for (unsigned int i = start; i < next; ++i)
		if (items[i] == target) return i;

	return -1;	// target is not found otherwise
}

/**
 * @brief Exponential Search (uses Binary Search by Recursion)
 * 
 * @param items - Array of items to be searched
 * @param size - Size of searched array
 * @param target - Target value to be searched in array
 * @return int 
 */
int exponentialSearch(int items[], int size, int target) {
	int bound = 1;

	// Double bound size while target is not within bounds
	while (bound < size && items[bound] < target) bound *= 2;

	// Narrow down bound to contain searched item
	int left = bound / 2;													 // left bound barrier
	int right = std::min(bound, (int)(size - 1));	 // right bound barrier

	// perform Binary Search within selected bounds
	return binarySearchRec(items, right + 1, target, left, right);
}

int main(int argc, char **argv) {
	int items[] = {7, 1, 3, 6, 5};
	int sortedItems[] = {1, 3, 5, 6, 7};
	unsigned int size = sizeof(items) / sizeof(items[0]);

	cout << "Linear Search:\n";
	cout << "5: " << linearSearch(items, size, 5) << endl;
	cout << "4: " << linearSearch(items, size, 4) << endl;
	cout << "3: " << linearSearch(items, size, 3) << endl;

	cout << "\nBinary Search:\n";
	cout << "3: " << binarySearchRec(sortedItems, size, 3) << endl;
	cout << "4: " << binarySearchRec(sortedItems, size, 4) << endl;
	cout << "5: " << binarySearchRec(sortedItems, size, 5) << endl;

	cout << "\nTernary Search:\n";
	cout << "3: " << ternarySearch(sortedItems, size, 3) << endl;
	cout << "4: " << ternarySearch(sortedItems, size, 4) << endl;
	cout << "5: " << ternarySearch(sortedItems, size, 5) << endl;

	cout << "\nJump Search:\n";
	cout << "3: " << jumpSearch(sortedItems, size, 3) << endl;
	cout << "4: " << jumpSearch(sortedItems, size, 4) << endl;
	cout << "5: " << jumpSearch(sortedItems, size, 5) << endl;

	cout << "\nExponential Search:\n";
	cout << "3: " << exponentialSearch(sortedItems, size, 3) << endl;
	cout << "4: " << exponentialSearch(sortedItems, size, 4) << endl;
	cout << "5: " << exponentialSearch(sortedItems, size, 5) << endl;

	return 0;
}

#endif
