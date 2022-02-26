#include <bits/stdc++.h>
// #include<iostream>
//using namespace std;

#define n 100

class stack {
    int* arr;
    int top;

    public:
    stack() {
        arr = new int[n];
        top = -1;
    }

    void push(int x) {
        // check if the stack is full or not
        if(top == n-1) {
            std::cout << "Stack overflow" << std::endl;
            return;
        }
        top++;
        arr[top] = x;
    }

    void pop() {
        // check if the stack is empty or not
        if(top == -1) {
            std::cout << "No element in stack to pop" << std::endl;
            return;
        }
        top--;
    }

    int Top() {
        if(top == -1) {
            return -1;
        }
        return arr[top];
    }

    bool empty() {
        return (top == -1);
    }
};

int main() {

    stack stk;
    stk.push(2);
    stk.push(4);
    stk.push(6);

    std::cout << "Top = " << stk.Top() << std::endl;

    stk.pop();
    std::cout << "Top = " << stk.Top() << std::endl;
    std::cout << "Is stack empty? " << stk.empty() << std::endl;

    stk.pop();
    stk.pop();
    stk.pop();

    std::cout << "Top = " << stk.Top() << std::endl;
    std::cout << "Is stack empty? " << stk.empty() << std::endl;

    return 0;
}
