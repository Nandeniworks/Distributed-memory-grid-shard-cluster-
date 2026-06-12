#include "LineSorter.h"
#include <limits>

// DSA CONCEPT: Merge Sort
// This module sorts data blocks based on their compression benefit in descending order.
// Merge Sort divides the array into sub-arrays of size 1, then repeatedly merges
// them to produce sorted sub-arrays until the entire array is sorted.
// It has a guaranteed O(N log N) time complexity.

void LineSorter::addBlock()
{
    DataBlock block;

    cout << "Enter Block Name (e.g., BlockA): ";
    cin >> block.name;

    cout << "Enter Compression Benefit (Integer value, e.g., 40): ";
    while (!(cin >> block.benefit)) {
        cout << "Invalid input. Please enter a valid integer for compression benefit: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    blocks.push_back(block);

    cout << "\nData Block Added Successfully!\n";
}

// Merges two sorted subarrays blocks[left...mid] and blocks[mid+1...right]
void LineSorter::merge(int left, int mid, int right)
{
    vector<DataBlock> temp;

    int i = left;
    int j = mid + 1;

    // Merge in descending order of benefit
    while(i <= mid && j <= right)
    {
        if(blocks[i].benefit >= blocks[j].benefit)
            temp.push_back(blocks[i++]);
        else
            temp.push_back(blocks[j++]);
    }

    // Copy remaining elements of left half
    while(i <= mid)
        temp.push_back(blocks[i++]);

    // Copy remaining elements of right half
    while(j <= right)
        temp.push_back(blocks[j++]);

    // Copy sorted elements back to original array
    for(size_t k = 0; k < temp.size(); k++)
        blocks[left + k] = temp[k];
}

// Recursive function that implements Merge Sort
void LineSorter::mergeSort(int left, int right)
{
    // Base case: 1 or 0 elements
    if(left >= right)
        return;

    int mid = left + (right - left) / 2;

    // Divide: Recursively sort left and right halves
    mergeSort(left, mid);
    mergeSort(mid + 1, right);

    // Conquer: Merge the sorted halves
    merge(left, mid, right);
}

void LineSorter::sortBlocks()
{
    if(blocks.empty())
    {
        cout << "\nNo Blocks Available to Sort!\n";
        return;
    }

    mergeSort(0, blocks.size() - 1);

    cout << "\nBlocks Sorted Successfully via Merge Sort (O(N log N))!\n";
}

void LineSorter::displayBlocks()
{
    if(blocks.empty())
    {
        cout << "\nNo Blocks Available.\n";
        return;
    }

    cout << "\n----- Data Blocks (Ranked by Compression Benefit) -----\n";
    cout << "Format: [Block Name] -> [Compression Benefit]\n";
    cout << "-------------------------------------------------------\n";

    for(const auto &block : blocks)
    {
        cout << "  " << block.name
             << " -> "
             << block.benefit
             << endl;
    }
    cout << "-------------------------------------------------------\n";
}