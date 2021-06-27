#include <string>
#include "StackChar.h"
#include "StackDouble.h"

/**
* Sarper Turan 21903051
* Strange Calculator Header File
*/

using namespace std;

string infix2prefix( const string exp);
double evaluatePrefix( const string exp);
bool isBalancedInfix( const string exp);
void evaluateInputPrefixExpression();

class StrangeCalculator {
public:
    StrangeCalculator();
    ~StrangeCalculator();
private:
};