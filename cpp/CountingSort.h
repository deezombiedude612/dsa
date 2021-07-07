#pragma once
#ifndef COUNTINGSORT_H
#define COUNTINGSORT_H

class CountingSort {
 public:
  /**
  * @brief Construct a new Counting Sort object to perform counting sort on array
  * 
  * @param items - Array to be sorted
  * @param size - Size of array
  * @param max - Largest element in array
  */
  CountingSort(int items[], unsigned int size, int max) {
    const unsigned int COUNTS_SIZE = max + 1;

    // get the counts for each item occurrence in items array
    int counts[COUNTS_SIZE];                                       // array of counters
    for (unsigned int i = 0; i < COUNTS_SIZE; ++i) counts[i] = 0;   // initialize array of counters

    // std::cout << "Counts size: " << COUNTS_SIZE << endl;
    for (unsigned int i = 0; i < size; ++i)
      counts[items[i]]++;

    // // populate items array in ascending order following each counter
    int k = 0;
    for (unsigned int i = 0; i < COUNTS_SIZE; ++i)
      for (int j = 0; j < counts[i]; ++j)
        items[k++] = i;
  }
};

#endif