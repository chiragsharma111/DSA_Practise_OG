// Approach 1 - Using 2 stacks with expensive dequeue operation

// Time Complexity: 
//  Push - O(1)
//  Pop  - O(N)

// Space complexity: O(N)

#include<bits/stdc++.h>
using namespace std;

class queueModified {
    private:
        stack<int> s1;
        stack<int> s2;

    public:
        void push(int x) {
            s1.push(x);
        }

        int pop() {
            // check if both stacks are empty
            if(s1.empty() && s2.empty()) {
                cout << "Queue is empty, can't pop" << endl;
                return -1;
            }

            if(s2.empty()) {
                while(!s1.empty()) {
                    s2.push(s1.top());
                    s1.pop();
                }
            }
            int topValue = s2.top();
            s2.pop();
            return topValue;
        }

        int peek() {
            if(s2.empty() && s1.empty()) {
                cout << "Queue is empty, can't perform peek operation" << endl;
                return -1;
            }
            if(!s2.empty()) {
                return s2.top();
            }
            if(s2.empty()) {
                while(!s1.empty()) {
                    s2.push(s1.top());
                    s1.pop();
                }
            }
            return s2.top();
        }

        bool empty() {
            if(s1.empty() && s2.empty()) {
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
    cout << "Top = " << q.peek() << endl;
    cout << "Pop = " << q.pop() << endl;
    cout << "Is Empty? " << q.empty() << endl;

    q.push(5);
    cout << "Top = " << q.peek() << endl;
    cout << "Pop = " << q.pop() << endl;
    cout << "Is Empty? " << q.empty() << endl;

    cout << "Top = " << q.peek() << endl;
    cout << "Pop = " << q.pop() << endl;
    cout << "Is Empty? " << q.empty() << endl;

    cout << "Top = " << q.peek() << endl;
    cout << "Pop = " << q.pop() << endl;
    cout << "Is Empty? " << q.empty() << endl;

    cout << "Top = " << q.peek() << endl;
    cout << "Pop = " << q.pop() << endl;
    cout << "Is Empty? " << q.empty() << endl;

    cout << "Top = " << q.peek() << endl;
    cout << "Pop = " << q.pop() << endl;
    cout << "Is Empty? " << q.empty() << endl;

    q.push(11);

    cout << "Top = " << q.peek() << endl;
    cout << "Pop = " << q.pop() << endl;
    cout << "Is Empty? " << q.empty() << endl;

    cout << "Top = " << q.peek() << endl;
    cout << "Pop = " << q.pop() << endl;
    cout << "Is Empty? " << q.empty() << endl;
    
    return 0;
}