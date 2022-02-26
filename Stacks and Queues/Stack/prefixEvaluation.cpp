// Time complexity: O(N)
// Space complexity: O(N) 
// where N = length of string or number of chars in string


#include<bits/stdc++.h>
using namespace std;

int prefixEvaluation(string str) {
    int n = str.length();
    stack<int> stk;

    for(int i=n-1; i>=0; i--) {
        if(str[i] >= '0' && str[i] <= '9') {
            stk.push(str[i] -'0'); // converted char to int
        }
        else {
            int op1 = stk.top();
            stk.pop();
            int op2 = stk.top();
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
                stk.push(op1 / op2);
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

    string prefixExp = "-+7*45+20";
    int prefixResult = prefixEvaluation(prefixExp);
    cout << "Prefix Result = " << prefixResult << endl;

    return 0;
}