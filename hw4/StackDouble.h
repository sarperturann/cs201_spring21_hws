#include <string>

/**
* Sarper Turan 21903051
* Double Stack for evaluatePrefix
*/

using namespace std;

class StackDouble {
public:
    StackDouble();
    StackDouble(const StackDouble& aStack);
    ~StackDouble();

    bool isEmpty() const;
    bool push(double newItem);
    bool pop();
    bool pop(double& stackTop);
    bool getTop(double& stackTop) const;

private:
    struct StackNode {
        double item;
        StackNode* next; // ptr to next node
    };
    StackNode* topPtr; // ptr to first node
};
