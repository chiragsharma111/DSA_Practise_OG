// Time complexity = O(N) - for & while loop
// Space complexity= O(N) - stack need space == the number of words in a sentence

#include<bits/stdc++.h>
using namespace std;

void reverseString(string str) {
    stack<string> stk;
    int n = str.length();
    for(int i=0; i<n; i++) {
        string word = "";

        while(str[i] != ' ' && i < n) {
            word += str[i];
            i++;
        }
        stk.push(word);
    }
    while(!stk.empty()) {
        cout << stk.top() << " ";
        stk.pop();
    }
    cout << endl;
}

int main() {
    string s = "Hi, How's you doin??";
    reverseString(s);
    return 0;
}
