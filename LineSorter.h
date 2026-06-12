#ifndef LINESORTER_H
#define LINESORTER_H

#include <iostream>
#include <vector>
using namespace std;

// ============================================================================
// DSA CONCEPT: MERGE SORT
// ----------------------------------------------------------------------------
// Merge Sort is a divide-and-conquer comparison-based sorting algorithm.
// It recursively splits the array into halves, sorts each half, and merges
// them back together in the desired order (descending order of compression benefit).
//
// Key Features:
// - Time Complexity: O(N log N) in all cases (worst, average, best).
// - Space Complexity: O(N) auxiliary space.
// - Algorithmic Strategy: Divide and Conquer.
// - Stable sorting: preserves the relative order of equal elements.
// ============================================================================

struct DataBlock
{
    string name;
    int benefit;
};

class LineSorter
{
private:
    vector<DataBlock> blocks;

    void merge(int left, int mid, int right);
    void mergeSort(int left, int right);

public:
    void addBlock();
    void sortBlocks();
    void displayBlocks();
};

#endif