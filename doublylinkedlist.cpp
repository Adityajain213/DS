#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int value) {
        data = value;
        next = NULL;
        prev = NULL;
    }
};

void insertAtPosition(Node*& head, int pos, int value) {
    Node* newNode = new Node(value);
    if (pos == 1) {
        newNode->next = head;
        if (head) head->prev = newNode;
        head = newNode;
        return;
    }
    Node* temp = head;
    for (int i = 1; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }
    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next) temp->next->prev = newNode;
    temp->next = newNode;
}

void deleteAtPosition(Node*& head, int pos) {
    if (!head) {
        cout << "List is empty.\n";
        return;
    }

    Node* temp = head;
    if (pos == 1) {
        head = head->next;
        if (head) head->prev = NULL;
        delete temp;
        return;
    }

    for (int i = 1; i < pos && temp != NULL; i++) {
        temp = temp->next;
    }

    if (!temp) {
        cout << "Position out of bounds.\n";
        return;
    }

    if (temp->prev) temp->prev->next = temp->next;
    if (temp->next) temp->next->prev = temp->prev;
    delete temp;
}

void display(Node* head) {
    if (!head) {
        cout << "List is empty.\n";
        return;
    }

    Node* temp = head;
    cout << "List: ";
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void findEvenNumbers(Node* head) {
    if (!head) {
        cout << "List is empty.\n";
        return;
    }

    Node* temp = head;
    bool found = false;
    cout << "Even numbers: ";
    while (temp) {
        if (temp->data % 2 == 0) {
            cout << temp->data << " ";
            found = true;
        }
        temp = temp->next;
    }
    if (!found) cout << "None.";
    cout << endl;
}

int main() {
    Node* head = NULL;
    int choice, pos, value;

    do {
        cout << "\n---- Menu ----\n";
        cout << "1. Insert at position\n";
        cout << "2. Delete at position\n";
        cout << "3. Display list\n";
        cout << "4. Find even numbers\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter position to insert: ";
                cin >> pos;
                cout << "Enter value: ";
                cin >> value;
                insertAtPosition(head, pos, value);
                break;
            case 2:
                cout << "Enter position to delete: ";
                cin >> pos;
                deleteAtPosition(head, pos);
                break;
            case 3:
                display(head);
                break;
            case 4:
                findEvenNumbers(head);
                break;
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice.\n";
        }

    } while (choice != 5);

    return 0;
}
