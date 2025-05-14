#include<iostream>
#include<stack>
#include<queue>
using namespace std;

class CircularQueue {
public:
    int front, rear, size;
    int capacity = 10;
    int arr[10];

    CircularQueue() {
        front = rear = -1;
        size = 0;
    }

    void enqueue(int data) {
        if (isFull()) {
            cout << "Queue is full" << endl;
            return;
        }

        rear = (rear + 1) % capacity;
        arr[rear] = data;
        size++;

        if (front == -1)
            front = rear;

        cout << data << " enqueued successfully." << endl;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }

        cout << arr[front] << " dequeued successfully." << endl;
        front = (front + 1) % capacity;
        size--;

        if (size == 0) {
            front = rear = -1;
        }
    }

    bool isFull() {
        return size == capacity;
    }

    bool isEmpty() {
        return size == 0;
    }

    int getSize() {
        return size;
    }

    void printElements() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }

        cout << "Queue elements: ";
        for (int i = 0; i < size; i++) {
            int idx = (front + i) % capacity;
            cout << arr[idx] << " ";
        }
        cout << endl;
    }
};

void reverseStack() {
    stack<int> st;
    queue<int> qu;
    int count = 5, ele;

    cout << "Enter 5 elements to push into the stack:" << endl;
    for (int i = 0; i < count; i++) {
        cin >> ele;
        st.push(ele);
    }

    // Transfer to queue
    while (!st.empty()) {
        qu.push(st.top());
        st.pop();
    }

    // Transfer back to stack
    while (!qu.empty()) {
        st.push(qu.front());
        qu.pop();
    }

    cout << "Stack reversed successfully." << endl;
}

int main() {
    CircularQueue q;
    int choice, en;

    do {
        cout << "\nAssignment - 3 Menu" << endl;
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. isFull" << endl;
        cout << "4. isEmpty" << endl;
        cout << "5. Get Size" << endl;
        cout << "6. Print Elements" << endl;
        cout << "7. Reverse a Stack using Queue" << endl;
        cout << "8. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter the element to enqueue: ";
            cin >> en;
            q.enqueue(en);
            break;

        case 2:
            q.dequeue();
            break;

        case 3:
            cout << (q.isFull() ? "Queue is full." : "Queue is not full.") << endl;
            break;

        case 4:
            cout << (q.isEmpty() ? "Queue is empty." : "Queue is not empty.") << endl;
            break;

        case 5:
            cout << "Size of the queue is: " << q.getSize() << endl;
            break;

        case 6:
            q.printElements();
            break;

        case 7:
            reverseStack();
            break;

        case 8:
            cout << "Exiting program." << endl;
            break;

        default:
            cout << "Invalid Choice!" << endl;
        }
    } while (choice != 8);

    return 0;
}
