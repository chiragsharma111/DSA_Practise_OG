#include<bits/stdc++.h>
using namespace std;

bool balancedParenthesis(string str) {
    int strLen = str.length();
    if(strLen == 0) {
        return true;
    }
    // odd number of characters(brackets) in string
    if(strLen % 2 != 0) {
        return false;
    }
    
    stack<char> stk;
    for(int i=0; i<strLen; i++) {
        
        char currChar = str[i];

        // push into stack if opening bracket
        if(currChar == '(' || currChar == '[' || currChar == '{') {
            stk.push(currChar);
        }
        // closing brackets
        else if(currChar == ')' || currChar == '}' || currChar == ']') {
            if(currChar == ')' && stk.top() == '(') {
                stk.pop();
            }
            else if(currChar == '}' && stk.top() == '{') {
                stk.pop();
            }
            else if(currChar == ']' && stk.top() == '[') {
                stk.pop();
            }
            else {
                return false;
            }
        }
    }

    if(!stk.empty()) {
        cout << "Stack top = " << stk.top() << endl;
        return false;
    }
    return true;    
}


int main() {

    string exp = "{[(){}[]()]";
    if(balancedParenthesis(exp)) {
        cout << "Balanced" << endl;
    }
    else {
        cout << "Not balanced" << endl;
    }

    return 0;
}