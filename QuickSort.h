#pragma once
#ifndef QUICKSORT_H
#define QUICKSORT_H

class QuickSort {
 private:
	void printArray(int items[], unsigned int size) {
		for (unsigned int i = 0; i < size; ++i)
			cout << items[i] << " ";
		cout << endl;
	}

	/**
  * @brief Divides items array into 2 partitions
	* Reference: https://visualgo.net/en/sorting?slide=12-7
  * 
  * @param items - Array to be partitioned
  * @param start - References first item in array
  * @param end - References last item in array
  * @return int 
  */
	int partition(int items[], int start, int end) {
		int pivot = items[start];
		int boundary = start;											// S1 and S2 are initially empty
		for (int k = start + 1; k <= end; k++) {	// explore the unknown region
			if (items[k] < pivot) {									// case 2
				// boundary++;
				std::swap(items[k], items[++boundary]);	 // C++ STL algorithm std::swap
			}																					 // notice that we do nothing in case 1: items[k] >= pivot
		}
		std::swap(items[start], items[boundary]);	 // final step, swap pivot with a[m]
		return boundary;													 // return the index of pivot
	}

	/**
	 * @brief Construct a new Quick Sort object to perform quick sort on array
	 * Reference: https://visualgo.net/en/sorting?slide=12-8
	 * 
	 * @param items - Array to be sorted
	 * @param start - Start index
	 * @param end - Full size of items
	 */
	QuickSort(int items[], int start, int end) {
		// Base case: Stop recursion when items has 1 element (start == end) or none (start > end)
		if (start >= end) return;

		// Divide items array into 2 partitions
		int boundary = partition(items, start, end);	// O(N)

		QuickSort(items, start, boundary - 1);	// Recursively sort left subarray
		// items[boundary] = pivot is already sorted after partition

		QuickSort(items, boundary + 1, end);	// Then, recursively sort right subarray
	}

 public:
	QuickSort(int items[], int size) {
		QuickSort(items, 0, size - 1);
	}
};

#endif
