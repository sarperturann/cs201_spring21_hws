#include <iostream>
#include "StackChar.h"

/**
* Sarper Turan 21903051
*/

using namespace std;

StackChar::StackChar() :topPtr(NULL) {}
StackChar::StackChar(const StackChar& aStack) {
    if (aStack.topPtr == NULL)
        topPtr = NULL; // original stack
    else{
        // copy first node
        topPtr = new StackNode;
        topPtr->item = aStack.topPtr->item;

        // copy rest of the stack
        StackNode* newPtr = topPtr;
        for (StackNode* origPtr = aStack.topPtr->next; origPtr != NULL; origPtr = origPtr->next) {
            newPtr->next = new StackNode;
            newPtr = newPtr->next;
            newPtr->item = origPtr->item;
        }
        newPtr->next = NULL;
    }
}
StackChar::~StackChar() {
    // pop until stack is empty
    while (!isEmpty())
        pop();
}

bool StackChar::isEmpty() const {
    return topPtr == NULL;
}

bool StackChar::push(char newItem) {

    // create a new node
    StackNode* newPtr = new StackNode;

    // set data portion of new node
    newPtr->item = newItem;

    // insert the new node
    newPtr->next = topPtr;
    topPtr = newPtr;

    return true;
}

bool StackChar::pop() {
    if (isEmpty())
        return false;
    // stack is not empty; delete top
    else {
        StackNode* temp = topPtr;
        topPtr = topPtr->next;

        // return deleted node to system
        temp->next = NULL; // safeguard
        delete temp;
        return true;
    }
}

bool StackChar::pop(char& stackTop) {
    if (isEmpty())
        return false;
    // not empty, retrieve and delete top
    else{
        stackTop = topPtr->item;
        StackNode* temp = topPtr;
        topPtr = topPtr->next;

        // return deleted node to system
        temp->next = NULL; // safeguard
        delete temp;
        return true;
    }
}

bool StackChar::getTop(char& stackTop) const {
    if (isEmpty())
        return false;

    // stack is not empty; retrieve top
    else {
        stackTop = topPtr->item;
        return true;
    }
}