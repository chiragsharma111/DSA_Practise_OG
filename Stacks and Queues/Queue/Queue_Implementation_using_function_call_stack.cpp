#include<bits/stdc++.h>
using namespace std;

class queueModified {
    private: 
    stack<int> s1;

    public:
    void push(int x) {
        s1.push(x);
    }
    int pop() {
        // Check if stack s1 is empty.
        if(s1.empty()) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        int x = s1.top();
        s1.pop();
        // if x was the only element in the queue
        if(s1.empty()) {
            return x;
        }
        // else if there are more than one element in the queue
        // Recursively calling pop function 
        // and storing the s1.top() in var item,
        // and once the stack is empty (s1.empty())
        // while returning back from extended recursive functional calls
        // we can push the element into the stack and return item at last.
        int item = pop();
        s1.push(x);
        return item;
    }
    bool empty() {
        if(s1.empty()) {
            return true;
        }
        return false;
    }
};

int main() {

    queueModified q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);

    cout << "pop = " << q.pop() << endl;
    cout << "Is queue empty? " << q.empty() << endl;
    
    cout << "pop = " << q.pop() << endl;
    cout << "Is queue empty? " << q.empty() << endl;

    q.push(5);

    cout << "pop = " << q.pop() << endl;
    cout << "Is queue empty? " << q.empty() << endl;

    q.push(6);

    cout << "pop = " << q.pop() << endl;
    cout << "Is queue empty? " << q.empty() << endl;

    cout << "pop = " << q.pop() << endl;
    cout << "Is queue empty? " << q.empty() << endl;

    cout << "pop = " << q.pop() << endl;
    cout << "Is queue empty? " << q.empty() << endl;

    cout << "pop = " << q.pop() << endl;
    cout << "Is queue empty? " << q.empty() << endl;

    return 0;
}

// Notes:

// Approach: Using functional call stack

// enQueue(x):
// Push x to stack1.

// deQueue():

// 1. If stack1 is empty then print error.
// 2. If stack1 has only one element then return it.
// 3. Recursively pop everything from stack1, 
// store the popped item in a variable res, push the res back to stack1 and return res.