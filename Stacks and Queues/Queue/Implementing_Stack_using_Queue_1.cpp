// Two methods

// Method 1 - Making push method costly
// Method 2 - Making pop method costly

// ---------------Method 1 - Making push method costly-----------

// Insert element in queue q1,
// dequeue all the elements from q1 and enqueue into q2
// Swap q1 and q2
// pop element from q1.

#include <bits/stdc++.h>
using namespace std;

class stackModified
{
    int N; // size of stack
    queue<int> q1;
    queue<int> q2;

public:
    stackModified()
    {
        N = 0;
    }

    void push(int val)
    {
        q2.push(val);
        N++;
        while (!q1.empty())
        {
            int data = q1.front();
            q1.pop();
            q2.push(data);
        }
        // Till now, all the elements are present in q2
        // and q1 is empty.

        // swaping queues
        queue<int> temp = q1;
        q1 = q2;
        q2 = temp;
    }

    void pop()
    {
        if (N == 0)
        {
            cout << "Stack is empty, can't pop." << endl;
            return;
        }
        q1.pop();
        N--;
    }

    int top()
    {
        if (N == 0)
        {
            cout << "Stack is empty." << endl;
            return -1;
        }
        return q1.front();
    }

    int size()
    {
        return N;
    }

    bool empty()
    {
        return (N == 0);
    }
};

int main()
{

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