#include<bits/stdc++.h>
using namespace std;

// --------------Approach 2: Making pop operation costly ------------

// Push elements in queue q1
// In pop function, pop elements (don't pop last element from q1) from q1 and 
// push elements in queue q2.
// Pop the last (ans only) element from q1
// swap q1 and q2.

class stackModified {
    int N;
    queue<int> q1;
    queue<int> q2;

    public:
    stackModified() {
        N = 0;
    }

    void push(int data) {
        q1.push(data);
        N++;
    }

    void pop() {
        if(q1.empty()) {
            cout << "Stack is empty, can't pop." << endl;
            return;
        }
        // // Having only one element in stackModified
        // if(N == 1) {
        //     q1.pop();
        //     N--;
        //     return;
        // }

        int N_copy = N;

        // Having more than one element in stackModified
        while(N_copy > 1) {
            int data = q1.front();
            q2.push(data);
            q1.pop();
            N_copy--;
        }

        q1.pop();
        N--;

        // swap queues q1 and q2
        queue<int> temp = q1;
        q1 = q2;
        q2 = temp;
    }

    int top() {
        if(N == 0) {
            cout << "Stack is empty. - Peek Operation" << endl;
            return -1;
        }
        return q1.back();
    }

    int size() {
        return N;
    }

    bool empty() {
        return (N == 0);
    }
};

int main() {

    stackModified stk;
    stk.push(1);
    stk.push(2);
    stk.push(3);
    stk.push(4);

    cout << "Top = " << stk.top() << ", Size = " << stk.size() << endl;
    cout << "Is stack empty? " << stk.size() << endl;
    stk.pop();

    cout << "Top = " << stk.top() << ", Size = " << stk.size() << endl;
    cout << "Is stack empty? " << stk.size() << endl;
    stk.pop();

    stk.push(5);

    cout << "Top = " << stk.top() << ", Size = " << stk.size() << endl;
    cout << "Is stack empty? " << stk.size() << endl;
    stk.pop();

    cout << "Top = " << stk.top() << ", Size = " << stk.size() << endl;
    cout << "Is stack empty? " << stk.size() << endl;
    stk.pop();

    stk.push(6);

    cout << "Top = " << stk.top() << ", Size = " << stk.size() << endl;
    cout << "Is stack empty? " << stk.size() << endl;
    stk.pop();

    cout << "Top = " << stk.top() << ", Size = " << stk.size() << endl;
    cout << "Is stack empty? " << stk.size() << endl;
    stk.pop();

    cout << "Top = " << stk.top() << ", Size = " << stk.size() << endl;
    cout << "Is stack empty? " << stk.size() << endl;
    stk.pop();


    return 0;
}