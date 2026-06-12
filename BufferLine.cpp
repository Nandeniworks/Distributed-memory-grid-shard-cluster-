#include "BufferLine.h"

// DSA CONCEPT: Queue
// Under the hood, this module uses std::queue.
// A queue processes entries in a FIFO (First In, First Out) sequence.
// Ideal for buffers, message queues, and request-response throttling in distributed memory grids.

void BufferLine::addRequest()
{
    string request;

    cout << "Enter Request (e.g., READ UserProfile, WRITE MovieData): ";
    // Use std::ws to safely consume any residual whitespace in the input stream
    cin >> ws;
    getline(cin, request);

    // Enqueue request at the back (O(1) time complexity)
    requests.push(request);

    cout << "\nRequest Added Successfully to Buffer Line!\n";
}

void BufferLine::processRequest()
{
    if(requests.empty())
    {
        cout << "\nNo Pending Requests in Buffer Line!\n";
        return;
    }

    // Access front element (O(1) time complexity)
    cout << "\n[Processing Request] " << requests.front() << endl;

    // Dequeue front element (O(1) time complexity)
    requests.pop();
}

void BufferLine::displayRequests()
{
    if(requests.empty())
    {
        cout << "\nNo Pending Requests in Buffer Line.\n";
        return;
    }

    // Copy queue to iterate through it, since standard queues do not support iterator access
    queue<string> temp = requests;

    cout << "\n----- Pending Requests (FIFO Order) -----\n";
    int index = 1;
    while(!temp.empty())
    {
        cout << "  " << index++ << ". " << temp.front() << endl;
        temp.pop();
    }
    cout << "-----------------------------------------\n";
}