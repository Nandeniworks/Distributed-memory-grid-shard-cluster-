#include "RecoveryHistory.h"

// DSA CONCEPT: Stack
// Under the hood, this module uses std::stack.
// A stack works on the LIFO (Last In, First Out) principle, making it ideal
// for tracking recovery histories or undoing/recovering the most recent write operation first.

void RecoveryHistory::addOperation()
{
    string operation;

    cout << "Enter Write Operation (e.g., WRITE UserProfile Node1): ";
    // Use std::ws to safely discard any leading newlines/whitespace in the buffer
    cin >> ws;
    getline(cin, operation);

    // Push operation onto the stack (O(1) time complexity)
    history.push(operation);

    cout << "\nOperation Recorded Successfully in Recovery History!\n";
}

void RecoveryHistory::undoOperation()
{
    if(history.empty())
    {
        cout << "\nNo Operations Available to Undo/Recover!\n";
        return;
    }

    // Access the top (most recent) element (O(1) time complexity)
    cout << "\nRecovered/Undone Operation: " << history.top() << endl;

    // Remove the top element (O(1) time complexity)
    history.pop();
}

void RecoveryHistory::displayHistory()
{
    if(history.empty())
    {
        cout << "\nRecovery History is Empty.\n";
        return;
    }

    // Since stack elements cannot be traversed directly without popping,
    // we copy the stack to display its contents from top to bottom.
    stack<string> temp = history;

    cout << "\n----- Recovery History (Top/Most Recent First) -----\n";
    while(!temp.empty())
    {
        cout << "  [Operation] " << temp.top() << endl;
        temp.pop();
    }
    cout << "----------------------------------------------------\n";
}