#ifndef SORTINGALGORITHMS_CPP
#define SORTINGALGORITHMS_CPP

#include <ctime>
#include <iostream>

using namespace std;

#include "BubbleSort.h"
#include "BucketSort.h"
#include "CountingSort.h"
#include "MergeSort.h"
#include "QuickSort.h"
#include "SelectionSort.h"

#define MAX_SIZE 20000	// Array size
// #define MAX_SIZE 10	 // Array size

/**
 * @brief Prints all contents in array
 * 
 * @param items 
 * @param size 
 */
void printArray(int items[], unsigned int size) {
	for (unsigned int i = 0; i < size; ++i)
		cout << items[i] << " ";
	cout << endl;
}

/**
 * @brief Swaps 2 items in array
 * 
 * @param array - Array containing 2 items to be swapped
 * @param index1 - First swappable item's index
 * @param index2 - Second swappable item's index
 */
void swap(int array[], unsigned int index1, unsigned index2) {
	int temp = array[index1];
	array[index1] = array[index2];
	array[index2] = temp;
}

/**
 * @brief Get the Largest Element from array
 * 
 * @param array - Array to be searched
 * @param size - Size of array
 * @return int 
 */
int getLargestElement(int array[], unsigned int size) {
	if (size == 1) return array[0];
	if (size == 0) return 0;

	int largestElement = array[0];
	for (unsigned int i = 1; i < size; ++i) {
		if (array[i] > largestElement)
			largestElement = array[i];
	}

	return largestElement;
}

int main(int arg, char **argv) {
	int aList[MAX_SIZE], bList[MAX_SIZE], cList[MAX_SIZE], dList[MAX_SIZE], eList[MAX_SIZE], fList[MAX_SIZE];
	clock_t timeBefore, timeAfter;
	double timeTaken;

	srand(time(NULL));
	for (int i = 0; i < MAX_SIZE; ++i) {
		// aList[i] = rand() % 100;
		aList[i] = rand() % 20;
		fList[i] = eList[i] = dList[i] = cList[i] = bList[i] = aList[i];
	}

	// printArray(aList, MAX_SIZE);
	timeBefore = clock();
	BubbleSort(aList, MAX_SIZE);
	timeAfter = clock();
	timeTaken = timeAfter - timeBefore;
	// printArray(aList, MAX_SIZE);
	cout << "Bubble Sorting array with size " << MAX_SIZE << " takes " << timeTaken << " ms\n";

	// printArray(bList, MAX_SIZE);
	timeBefore = clock();
	SelectionSort(bList, MAX_SIZE);
	timeAfter = clock();
	timeTaken = timeAfter - timeBefore;
	// printArray(bList, MAX_SIZE);
	cout << "Selection Sorting array with size " << MAX_SIZE << " takes " << timeTaken << " ms\n";

	// printArray(cList, MAX_SIZE);
	timeBefore = clock();
	MergeSort(cList, MAX_SIZE);
	timeAfter = clock();
	timeTaken = timeAfter - timeBefore;
	// printArray(cList, MAX_SIZE);
	cout << "Merge Sorting array with size " << MAX_SIZE << " takes " << timeTaken << " ms\n";

	// printArray(dList, MAX_SIZE);
	timeBefore = clock();
	QuickSort(dList, MAX_SIZE);
	timeAfter = clock();
	timeTaken = timeAfter - timeBefore;
	// printArray(dList, MAX_SIZE);
	cout << "Quick Sorting array with size " << MAX_SIZE << " takes " << timeTaken << " ms\n";

	// printArray(eList, MAX_SIZE);
	timeBefore = clock();
	CountingSort(eList, MAX_SIZE, getLargestElement(eList, MAX_SIZE));
	timeAfter = clock();
	timeTaken = timeAfter - timeBefore;
	// printArray(eList, MAX_SIZE);
	cout << "Counting Sort the array with size " << MAX_SIZE << " takes " << timeTaken << " ms\n";

	// printArray(fList, MAX_SIZE);
	timeBefore = clock();
	BucketSort(fList, MAX_SIZE);
	timeAfter = clock();
	timeTaken = timeAfter - timeBefore;
	// printArray(fList, MAX_SIZE);
	cout << "Bucket Sorting array with size " << MAX_SIZE << " takes " << timeTaken << " ms\n";

	return 0;
}

#endif
