#ifndef REGISTRYINDEX_H
#define REGISTRYINDEX_H

#include <iostream>
#include <vector>
using namespace std;

// ============================================================================
// DSA CONCEPT: BINARY SEARCH
// ----------------------------------------------------------------------------
// Binary Search is an efficient search algorithm that finds the position of a 
// target value within a sorted array. It works by repeatedly dividing in half
// the search interval.
//
// Key Features:
// - Prerequisite: Array must be sorted.
// - Time Complexity: O(log N) worst/average case.
// - Space Complexity: O(1) auxiliary.
// - Ideal for fast cluster node membership lookup against a sorted registry.
// ============================================================================

class RegistryIndex
{
private:
    vector<int> nodes;

public:
    RegistryIndex();
    void displayNodes();
    void searchNode();
};

#endif