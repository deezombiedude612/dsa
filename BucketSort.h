#pragma once
#ifndef BUCKETSORT_H
#define BUCKETSORT_H

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class BucketSort {
 public:
	BucketSort(int items[], unsigned int numberOfBuckets) {
		// initialize buckets
		vector<int> buckets[numberOfBuckets];

		// put elements into different buckets
		for (unsigned int i = 0; i < numberOfBuckets; ++i)
			buckets[items[i] / numberOfBuckets].push_back(items[i]);

		unsigned int index = 0;
		for (unsigned int i = 0; i < numberOfBuckets; ++i) {
			sort(buckets[i].begin(), buckets[i].end());	 // sort individual buckets

			// concatenate all buckets into items array
			for (unsigned int j = 0; j < buckets[i].size(); ++j)
				items[index++] = buckets[i][j];
		}
	}
};

#endif