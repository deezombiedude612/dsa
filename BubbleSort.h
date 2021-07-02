#pragma once
#ifndef BUBBLESORT_H
#define BUBBLESORT_H

class BubbleSort {
 public:
  /**
  * @brief Construct a new Bubble Sort object to perform bubble sort on array
  * 
  * @param items - Array to be sorted
  * @param size - Size of array
  */
  BubbleSort(int items[], unsigned int size) {
    for (unsigned int i = 0; i < size; ++i) {
      for (unsigned int j = 0; j < size - i - 1; ++j) {
        if (items[j] > items[j + 1]) {
          int temp = items[j];
          items[j] = items[j + 1];
          items[j + 1] = temp;
          // swap(items, j, (j + 1));
        }
      }
    }
  }
};

#endif
