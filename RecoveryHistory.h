#ifndef RECOVERYHISTORY_H
#define RECOVERYHISTORY_H

#include <iostream>
#include <stack>
using namespace std;

// ============================================================================
// DSA CONCEPT: STACK
// ----------------------------------------------------------------------------
// A Stack is a linear data structure that follows the LIFO (Last In, First Out)
// principle. The last operation added (pushed) is the first one to be removed
// (popped) during recovery.
//
// Key Features:
// - Operations: push() (O(1)), pop() (O(1)), top() (O(1)).
// - Best suited for undo mechanisms, backtrack history, and state recovery.
// ============================================================================

class RecoveryHistory
{
private:
    stack<string> history;

public:
    void addOperation();
    void undoOperation();
    void displayHistory();
};

#endif