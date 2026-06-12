#ifndef BUFFERLINE_H
#define BUFFERLINE_H

#include <iostream>
#include <queue>
using namespace std;

// ============================================================================
// DSA CONCEPT: QUEUE
// ----------------------------------------------------------------------------
// A Queue is a linear data structure that follows the FIFO (First In, First Out)
// principle. The first request added (pushed) will be the first one to be 
// processed (popped).
//
// Key Features:
// - Operations: push() (O(1) back enqueue), pop() (O(1) front dequeue), 
//   front() (O(1) read).
// - Simulates request queues where incoming client reads/writes must be 
//   buffered and processed in arrival sequence order.
// ============================================================================

class BufferLine
{
private:
    queue<string> requests;

public:
    void addRequest();
    void processRequest();
    void displayRequests();
};

#endif