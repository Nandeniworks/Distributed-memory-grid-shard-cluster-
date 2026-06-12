#include "RegistryIndex.h"
#include <limits>

// DSA CONCEPT: Binary Search
// The list of registered nodes is kept sorted: [1, 2, 3, 4, 5, 6, 7, 8, 9, 10].
// A binary search algorithm repeatedly cuts the search space in half, yielding
// a fast lookup of O(log N) time complexity for node membership validation.

RegistryIndex::RegistryIndex()
{
    // The registry is initialized as a sorted list
    nodes = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
}

void RegistryIndex::displayNodes()
{
    cout << "\n--- Cluster Node Registry (Sorted for Binary Search) ---\n";
    cout << "Active Nodes: ";
    for(int node : nodes)
        cout << "[" << node << "] ";
    cout << "\n--------------------------------------------------------\n";
}

void RegistryIndex::searchNode()
{
    int target;

    cout << "Enter Node ID to search: ";
    while (!(cin >> target)) {
        cout << "Invalid input. Please enter a valid integer Node ID: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int left = 0;
    int right = nodes.size() - 1;
    bool found = false;

    // Binary search loop
    while(left <= right)
    {
        // Calculate mid-point safely to avoid overflow
        int mid = left + (right - left) / 2;

        if(nodes[mid] == target)
        {
            found = true;
            break;
        }

        if(nodes[mid] < target)
            left = mid + 1; // Discard left half
        else
            right = mid - 1; // Discard right half
    }

    if (found) {
        cout << "\nNode " << target << " is VERIFIED and belongs to the cluster! (Search time: O(log N))\n";
    } else {
        cout << "\nNode " << target << " NOT found in registry. Membership verification failed!\n";
    }
}