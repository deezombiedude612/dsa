#pragma once
#ifndef SELECTIONSORT_H
#define SELECTIONSORT_H

class SelectionSort {
 public:
	/**
  * @brief Construct a new Selection Sort object to perform selection sort on array
  * 
  * @param items - Array to be sorted
  * @param size - Size of array
  */
	SelectionSort(int items[], unsigned int size) {
		for (unsigned int rightmost = size - 1; rightmost > 0; --rightmost) {
			int maxIndex = 0;
			for (unsigned int cur = 1; cur <= rightmost; ++cur) {
				if (items[cur] > items[maxIndex])
					maxIndex = cur;
			}

			if (items[maxIndex] > items[rightmost]) {
				int temp = items[maxIndex];
				items[maxIndex] = items[rightmost];
				items[rightmost] = temp;
				// swap(items, maxIndex, rightmost);
			}
		}
	}
};

#endif
