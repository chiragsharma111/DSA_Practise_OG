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
    return -1;
}

string mainAlgoConvertInfixToPrefix(string str) {
    int strLen = str.length();
    string result = "";
    stack<char> stk;
    for(int i=0; i<strLen; i++) {
        char currChar = str[i];
        if( (currChar >= 'a' && currChar <= 'z' ) || (currChar >= 'A' && currChar <= 'Z') ) {
            result += currChar;
        }
        // operations associated with opening brackets
        else if(currChar == '(') {
            stk.push(currChar);
        }
        // operations associated with closing brackets
        else if(currChar == ')') {
            while(!stk.empty() && stk.top() != '(') {
                result += stk.top();
                stk.pop();
            }
            // popping the closing bracket
            if(!stk.empty()) {
                stk.pop();
            }
        }
        // Operators other than brackets
        else {
            while(!stk.empty() && prec(stk.top()) >= prec(currChar)) {
                result += stk.top();
                stk.pop();
            }
            // pushing current operator into stack
            stk.push(currChar);
        }
    }
    while(!stk.empty()) {
        result += stk.top();
        stk.pop();
    }
    return result;
}

string infixToPrefixExpression(string infixStr) {

    int infixStrLen = infixStr.length();

    // include header file to use reverse
    // #include<algorithm>
    reverse(infixStr.begin(), infixStr.end());

    // toggling opening and closing brackets
    for(int i=0; i<infixStrLen; i++) {
        if(infixStr[i] == ')') {
            infixStr[i] = '(';
        }
        else if(infixStr[i] == '(') {
            infixStr[i] = ')';
        }
    }
    string prefixString = mainAlgoConvertInfixToPrefix(infixStr);
    reverse(prefixString.begin(), prefixString.end());
    return prefixString;
}

int main() {

    string infixString = "(a-b/c)*(a/k-l)";
    cout << "Infix expression = " << infixString << endl;
    string prefix = infixToPrefixExpression(infixString);
    cout << "Prefix expression = " << prefix << endl;

    return 0;
}