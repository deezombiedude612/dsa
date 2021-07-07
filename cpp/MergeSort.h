#pragma once
#ifndef MERGESORT_H
#define MERGESORT_H

class MergeSort {
 private:
  /**
  * @brief Merges both array partitions
  * 
  * @param left - First array partition
  * @param leftSize - First array partition size
  * @param right - Second array partition
  * @param rightSize - Second array partition size
  * @param result - Contains sorted array
  */
  void merge(int left[], unsigned int leftSize, int right[], unsigned int rightSize, int result[]) {
    unsigned int i = 0, j = 0, k = 0;

    while (i < leftSize && j < rightSize) {
      if (left[i] < right[j])
        result[k++] = left[i++];
      else
        result[k++] = right[j++];
    }

    while (i < leftSize) result[k++] = left[i++];
    while (j < rightSize) result[k++] = right[j++];
  }

 public:
  /**
  * @brief Construct a new Merge Sort object to perform merge sort on array
  * 
  * @param items - Array to be sorted
  * @param size - Size of array
  */
  MergeSort(int items[], unsigned int size) {
    // Base case: If items only has < 2 elements, stop recursion here
    if (size < 2) return;

    // Divide array into half
    unsigned int middle = size / 2;

    int left[middle];
    for (unsigned int i = 0; i < middle; ++i) left[i] = items[i];

    int right[size - middle];
    for (unsigned int i = middle; i < size; ++i) right[i - middle] = items[i];

    // Sort each half of array (done recursively)
    MergeSort(left, middle);
    MergeSort(right, (size - middle));

    // Merge both array partitions
    merge(left, middle, right, (size - middle), items);
  }
};

#endif
