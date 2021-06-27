#include <string>

/**
* Sarper Turan 21903051
*/

using namespace std;

class StackChar {
public:
    StackChar();
    StackChar(const StackChar& aStack);
    ~StackChar();

    bool isEmpty() const;
    bool push(char newItem);
    bool pop();
    bool pop(char& stackTop);
    bool getTop(char& stackTop) const;

private:
    struct StackNode {
        char item;
        StackNode* next;
    };
    StackNode* topPtr;
};