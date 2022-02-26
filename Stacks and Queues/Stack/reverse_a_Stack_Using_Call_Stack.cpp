#include<bits/stdc++.h>
using namespace std;

void insertAtBottom(stack<int> &stk, int element) {
    if(stk.empty()) {
        stk.push(element);
        return;
    }

    int topElement = stk.top();
    stk.pop();
    insertAtBottom(stk, element);

    stk.push(topElement);
}

void reverseStack(stack<int> &st) {
    if(st.empty()) {
        return;
    }

    int ele = st.top();
    st.pop();
    reverseStack(st);
    insertAtBottom(st, ele);

}

int main() {

    stack<int> st;
    st.push(2);
    st.push(4);
    st.push(6);
    st.push(8);

    reverseStack(st);

    while(!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }

    cout << endl;


    return 0;
}
