#include<bits/stdc++.h>
// using namespace std;

#define n 10

class queue {
    private:

    int *arr;
    int front;
    int back;

    public:
    queue() {
        arr = new int[n];
        front = -1;
        back = -1;
    }

    void push(int x) {
        if(back == n-1) {
            std::cout << "Queue overflow" << std::endl;
            return;
        }
        if(front == -1) {
            front++;
        }
        back++;
        arr[back] = x;
    }

    void pop() {
        if(front == -1 || front > back) {
            std::cout << "Queue is empty, can't pop" << std::endl;
            return;
        }
        // only element in the list
        if(front == back) {
            front = -1;
            back = -1;
            return;
        }
        front++;
    }

    int peek() {
        if(front == -1 || front > back) {
            std::cout << "Queue is empty, can't peek" << std::endl;
            return -1;
        }
        return arr[front];
    }

    bool empty() {
        if(front == -1 || front > back) {
            return true;
        }
        return false;
    }
};

int main() {

    queue q;
    q.push(2);
    q.push(4);
    q.push(6);
    q.push(8);

    std::cout << q.peek() << std::endl;
    q.pop();

    std::cout << q.peek() << std::endl;
    q.pop();

    std::cout << q.peek() << std::endl;
    q.pop();

    std::cout << q.peek() << std::endl;
    q.pop();

    std::cout << q.peek() << std::endl;
    q.pop();

    std::cout << "Is queue empty? " << q.empty() << std::endl;


    return 0;
}