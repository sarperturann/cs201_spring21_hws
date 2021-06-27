#include <iostream>
#include <string>
#include "StrangeCalculator.h"

/**
* Sarper Turan 21903051
* Strange Calculator Implementation File
*/

using namespace std;

//Constructors
StrangeCalculator::StrangeCalculator(){}
StrangeCalculator::~StrangeCalculator(){}

//Methods
string infix2prefix(const string exp){
    //TODO:
    /*
    * A way to do this might be: 
    * First, reverse the infix expression 
    * Scan the characters one by one
    * If char is an operand -> copy it to the output of the prefix notation
    * If char is a closing parenthesis -> push it to the stack
    * If char is an opening parenthesis -> pop the elements in stack till the closing parenthesis that responds
    * If char is an operator -> if the operator has greater or equal then the top of the stack, 
    *           push the operator to the stack
    *                        -> if the operator has less then the top of the stack,
    *           pop the operator and output it to prefix notation output then check the notation of the new top of the stack
    * after scanning all, reverse the notation output for the prefix
    */ 
   StackChar operatorStack;
   string prefix;
   string result;
   char ch;
   char a;
   char b;
   char c;
   for( int i = exp.length() - 1; i > -1; i--){ //reverse check
        ch = exp.at(i);
        if(ch == '+' || ch == '-' || ch == '*' || ch == '/'){
           // operator encountered
            if(operatorStack.isEmpty()) // if its empty push the operator to the stack
                operatorStack.push(ch);
            else{ // comparing precedence
                operatorStack.getTop(a);
                if( (a == '*'  || a == '/') && ( ch == '+' || ch == '-')){
                    operatorStack.pop(a);
                    prefix = prefix + a;
                    operatorStack.push(ch);
                } else {
                    operatorStack.push(ch);
                }
            }
       } else if ( ch == ')'){
           // if it is a closing parenthesis, push it to the stack
           operatorStack.push(ch);
       } else if ( ch == '('){
           // If it is an opening parenthesis, looking for the closing one
           operatorStack.pop(b);
           while( b != ')'){
               prefix = prefix + b;
               operatorStack.pop(b);
           }
       } else {
           prefix = prefix + ch;
       }
   }
   while( !operatorStack.isEmpty()){ // popping from the stack to the prefix output
       operatorStack.pop(c);
       prefix = prefix + c;
   }
   for( int i = prefix.length() - 1; i > -1; i--){ //reversed
       result = result + prefix.at(i);
   }
   return result;
}

double evaluatePrefix(const string exp){
    StackDouble stack;
    
    for(int i = exp.length() - 1; i > -1; i--){
        char ch = exp.at(i);
        if(ch == '+' || ch == '-' || ch == '*' || ch == '/'){
            // operator encountered - pop two elements from stack
            double e1, e2;
            stack.pop(e1);
            stack.pop(e2);

            // operating on these elements according to the operator and pushing the result back to the stack
            if (ch == '+') {
                stack.push(e1 + e2);
            } else if (ch == '-') {
                stack.push(e1 - e2);
            } else if (ch == '*') {
                stack.push(e1 * e2);
            } else if (ch == '/') {
                stack.push(e1 / e2);
            }
        } else {
            // operand encountered, we have to convert it to double and then push it to stack
            // to convert our char to double, we substract ASCII '0'
            double d = (double) ch;
            d = d - '0';
            stack.push(d);
        }
    }
    double result;
    stack.pop(result);
    return result;
}

bool isBalancedInfix(const string exp){
    StackChar stack;
    bool isBalanced = true;

    int index = 0;
    while( index < exp.length() && isBalanced ){
        char ch = exp.at(index);
        index++;
        if( ch == '(')
            stack.push(ch);
        else if ( ch == ')'){
            if( stack.isEmpty()){
                isBalanced = false;
                return false;
            }else{
                stack.pop();
                isBalanced = true;
            }
        }
    }
    if( isBalanced && stack.isEmpty()){
        return true;
    }
    return false;
}

void evaluateInputPrefixExpression(){
    // I wasn't sure if I MUST use stack in every method, I did use here to guarantee it but 
    //          it can be done without using stack, instead of doing the push/pop operations just ad the input.at(i) to our result
    string input;
    string result;
    string prefix;
    StackChar stack;
    char ch;
    cout << "Please enter an infix input: " << endl;
    getline(cin, input);
    for( int i = 0; i < input.size(); i++){
        if( input.at(i) != ' '){
            stack.push(input.at(i));
        }
    }
    while( !stack.isEmpty()){
        stack.pop(ch);
        result = result + ch;
    }
    if( isBalancedInfix(input)){
        prefix = infix2prefix(result);
        cout << "prefix of your input: " << prefix << endl;
        cout << "result of your input: " << evaluatePrefix(prefix) << endl;
    } else 
        cout << "Your input does not have balanced parenthesis" << endl;
}
