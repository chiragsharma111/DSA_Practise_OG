#include<bits/stdc++.h>
using namespace std;

int prec(char ch) {
    if(ch == '^') {
        return 3;
    }
    if(ch == '*' || ch == '/') {
        return 2;
    }
    if(ch == '+' || ch == '-') {
        return 1;
    }
    return -1; // in case of unknown operators or brackets.
}

string infixToPostfix(string infixStr) {

    stack<char> stk;
    string result = "";
    int strLength = infixStr.length();

    for(int i=0; i<strLength; i++) {
        char currChar = infixStr[i];
        if( (currChar >= 'a' && currChar <= 'z') || (currChar >= 'A' && currChar <= 'Z') ) {
            result += currChar;
        }
        else if(currChar == '(') {
            stk.push(currChar);
        }
        else if(currChar == ')') {
            while(!stk.empty() && stk.top() != '(') {
                result += stk.top();
                stk.pop();
            }
            // popping the opening bracket
            if(!stk.empty()) {
                stk.pop();
            }
        }
        // other operators
        else {
            while(!stk.empty() && prec(stk.top()) >= prec(currChar)) {
                result += stk.top();
                stk.pop();
            }
            // pushing the current char into stack after popping
            stk.push(currChar);             
        }
    }

    while(!stk.empty()) {
        result += stk.top();
        stk.pop();
    }
    return result;
}

int main() {

    string infixString = "(a-b/c)*(a/k-l)";
    string postfixString = infixToPostfix(infixString);
    cout << "Infix string = " << infixString << endl;
    cout << "Postfix string = " << postfixString << endl;


    return 0;
}