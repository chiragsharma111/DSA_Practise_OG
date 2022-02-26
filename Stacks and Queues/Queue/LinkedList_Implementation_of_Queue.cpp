#include<bits/stdc++.h>
// using namespace std;

class queue {
    public:
        queue() {}

        struct Node {
            int data;
            Node *next;
        };
        Node* head = NULL;
        Node* tail = NULL;

        // push at tail
        void Enqueue(int x) {
            if(head == NULL) {
                Node* newNode = new Node();
                newNode->data = x;
                newNode->next = NULL;
                head = newNode;
                tail = newNode;
            }
            else {
                Node* newNode = new Node();
                newNode->data = x;
                newNode->next = NULL;
                tail->next = newNode;
                tail = tail->next;
            }
        }   

        // pop from head
        void Dequeue() {
            if(head == NULL) {
                std::cout << "No element in queue, can't pop" << std::endl;
                return;
            }
            // only element in queue
            if(head == tail) {
                head = NULL;
                tail = NULL;
                return;
            }
            // Having more than 1 element in queue
            Node* temp = head;
            head = head->next;
            delete(temp);
        }

        int peek() {
            if(head == NULL) {
                std::cout << "No element in queue, can't peek" << std::endl;
                return -1;
            }
            return head->data;
        }

        bool empty() {
            if(head == NULL) {
                return true;
            }
            return false;
        }


};

int main() {

    queue q;
    q.Enqueue(2);
    q.Enqueue(4);
    // q.Enqueue(6);

    std::cout << "Top = " << q.peek() << std::endl;
    q.Dequeue();

    q.Enqueue(5);

    std::cout << "Top = " << q.peek() << std::endl;
    q.Dequeue();

    std::cout << "Top = " << q.peek() << std::endl;
    q.Dequeue();

    std::cout << "Is empty? " << q.empty() << std::endl;

    return 0;
}