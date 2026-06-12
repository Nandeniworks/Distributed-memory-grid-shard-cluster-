#include "PriorityLayout.h"
#include <limits>

// DSA CONCEPT: Priority Queue (Min-Heap)
// We use a custom greater<pair<int, string>> comparison to instantiate a Min-Heap.
// In this heap, the element with the smallest timestamp (oldest element) bubble ups
// to the top, allowing eviction of the oldest elements in O(log N) time complexity.

void PriorityLayout::addBlock()
{
    string name;
    int timestamp;

    cout << "Enter Block Name (e.g., BlockA): ";
    cin >> name;

    cout << "Enter Timestamp (Integer priority, e.g., 1609459200): ";
    while (!(cin >> timestamp)) {
        cout << "Invalid input. Please enter a valid integer timestamp: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    // Insert block with its timestamp into the Min-Heap: O(log N) complexity
    blocks.push({timestamp, name});

    cout << "\nBlock \"" << name << "\" Added Successfully to Priority Layout!\n";
}

void PriorityLayout::evictBlock()
{
    if(blocks.empty())
    {
        cout << "\nNo Blocks Available for Eviction!\n";
        return;
    }

    // Access the element with the smallest key/timestamp: O(1) complexity
    cout << "\n[EVICTED] Oldest Block: " << blocks.top().second 
         << " (Timestamp: " << blocks.top().first << ")\n";

    // Delete the root element and rebuild the heap: O(log N) complexity
    blocks.pop();
}

void PriorityLayout::displayBlocks()
{
    if(blocks.empty())
    {
        cout << "\nNo Blocks Stored in Priority Layout.\n";
        return;
    }

    // Since a priority queue doesn't allow random/iterator access,
    // we copy it and pop elements one-by-one to print them in sorted order.
    priority_queue<
        pair<int,string>,
        vector<pair<int,string>>,
        greater<pair<int,string>>
    > temp = blocks;

    cout << "\n----- Priority Layout Blocks (Oldest First) -----\n";
    cout << "Format: [Block Name] -> [Timestamp]\n";
    cout << "-------------------------------------------------\n";

    while(!temp.empty())
    {
        cout << "  " << temp.top().second
             << " -> " << temp.top().first
             << endl;

        temp.pop();
    }
    cout << "-------------------------------------------------\n";
}