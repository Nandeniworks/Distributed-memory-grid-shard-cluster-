#ifndef CATALOGINDEX_H
#define CATALOGINDEX_H

#include <iostream>
#include <unordered_map>
using namespace std;

// ============================================================================
// DSA CONCEPT: HASHING (Hash Table)
// ----------------------------------------------------------------------------
// Hashing is a technique used to uniquely identify a specific object from a 
// group of similar objects. In this module, we use C++ STL's `unordered_map`
// which is implemented as a Hash Table.
//
// Key Features:
// - Time Complexity: Average O(1) for Insert, Search, and Delete operations.
// - Keys are hashed into bucket indices, providing near-constant time access.
// - Used in systems like Cassandra for partitioning and mapping keys to nodes.
// ============================================================================

struct MemoryRecord
{
    string dataName;
    string nodeName;
};

class CatalogIndex
{
private:
    unordered_map<int, MemoryRecord> catalog;

public:
    void addRecord();
    void searchRecord();
    void displayCatalog();
};

#endif