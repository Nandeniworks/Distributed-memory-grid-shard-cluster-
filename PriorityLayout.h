#ifndef PRIORITYLAYOUT_H
#define PRIORITYLAYOUT_H

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// ============================================================================
// DSA CONCEPT: PRIORITY QUEUE / MIN-HEAP
// ----------------------------------------------------------------------------
// A Priority Queue is an abstract data type where each element has an associated 
// "priority". In a Min-Heap representation, the element with the lowest priority 
// value is always at the front (top) of the queue.
//
// Key Features:
// - Operations: push() (O(log N)), pop() (O(log N)), top() (O(1)).
// - Under the hood: usually implemented using binary heaps.
// - Application: Storing data blocks mapped to their age/timestamp. This makes
//   it easy to identify and evict the oldest block (lowest timestamp/highest age)
//   when cache or storage space limits are reached.
// ============================================================================

class PriorityLayout
{
private:
    priority_queue<
        pair<int,string>,
        vector<pair<int,string>>,
        greater<pair<int,string>>
    > blocks;

public:
    void addBlock();
    void evictBlock();
    void displayBlocks();
};

#endif