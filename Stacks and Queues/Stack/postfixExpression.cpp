// Time complexity: O(N)
// Space complexity: O(N) 
// where N = length of string or number of chars in string


#include<bits/stdc++.h>
using namespace std;

int evaluatePostfixExpression(string str) {
    stack<int> stk;
    int stringLength = str.length();
    for(int i=0; i<stringLength; i++) {
        if(str[i] >= '0' && str[i] <= '9') {
            stk.push(str[i]-'0');
        }
        else {
            // In any expression,
            // left operand is op1
            // right operand is op2

            int op2 = stk.top();
            stk.pop();
            int op1 = stk.top();
            stk.pop();
            switch(str[i]) {
                case '+': 
                stk.push(op1 + op2);
                break;

                case '-':
                stk.push(op1 - op2);
                break;

                case '*':
                stk.push(op1 * op2);
                break;

                case '/':
                stk.push(op1/op2);
                break;

                case '^': 
                stk.push(pow(op1, op2));
                break;
            }
        }
    }
    return stk.top();
}

int main() {

    string postfixExp = "46+2/5*7+";
    int postfixResult = evaluatePostfixExpression(postfixExp);
    cout << "Postfix = " << postfixResult << endl;
    return 0;
}