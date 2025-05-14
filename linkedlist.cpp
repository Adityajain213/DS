#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

// Function declarations
void insertfront(Node*& head, int value);
void insertend(Node*& head, int value);
void insertatanyposition(Node*& head, int position, int value);
void deletefront(Node*& head);
void deleteend(Node*& head);
void deleteatanyposition(Node*& head, int position);
void displaylist(Node* head);

int main() {
    Node* head = nullptr;
    int choice, value, position;

    do {
        cout << "\n---- Menu ----\n";
        cout << "1. Insert at front\n";
        cout << "2. Insert at end\n";
        cout << "3. Delete from front\n";
        cout << "4. Delete from end\n";
        cout << "5. Insert at any position\n";
        cout << "6. Delete at any position\n";
        cout << "7. Display list\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert at front: ";
                cin >> value;
                insertfront(head, value);
                break;
            case 2:
                cout << "Enter value to insert at end: ";
                cin >> value;
                insertend(head, value);
                break;
            case 3:
                deletefront(head);
                break;
            case 4:
                deleteend(head);
                break;
            case 5:
                cout << "Enter value: ";
                cin >> value;
                cout << "Enter position: ";
                cin >> position;
                insertatanyposition(head, position, value);
                break;
            case 6:
                cout << "Enter position to delete: ";
                cin >> position;
                deleteatanyposition(head, position);
                break;
            case 7:
                displaylist(head);
                break;
            case 8:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid input\n";
        }
    } while (choice != 8);

    return 0;
}

void insertfront(Node*& head, int value) {
    Node* newNode = new Node(value);
    newNode->next = head;
    head = newNode;
}

void insertend(Node*& head, int value) {
    Node* newNode = new Node(value);
    if (!head) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }

    temp->next = newNode;
}

void insertatanyposition(Node*& head, int position, int value) {
    if (position <= 0) {
        cout << "Invalid position!" << endl;
        return;
    }

    if (position == 1) {
        insertfront(head, value);
        return;
    }

    Node* temp = head;
    for (int i = 1; i < position - 1 && temp != nullptr; i++) {
        temp = temp->next;
    }

    if (!temp) {
        cout << "Position out of bounds!" << endl;
        return;
    }

    Node* newNode = new Node(value);
    newNode->next = temp->next;
    temp->next = newNode;
}

void deletefront(Node*& head) {
    if (!head) {
        cout << "List is empty!" << endl;
        return;
    }

    Node* temp = head;
    head = head->next;
    delete temp;
}

void deleteend(Node*& head) {
    if (!head) {
        cout << "List is empty!" << endl;
        return;
    }

    if (!head->next) {
        delete head;
        head = nullptr;
        return;
    }

    Node* temp = head;
    while (temp->next->next != nullptr) {
        temp = temp->next;
    }

    delete temp->next;
    temp->next = nullptr;
}

void deleteatanyposition(Node*& head, int position) {
    if (!head || position <= 0) {
        cout << "Invalid position or list is empty!" << endl;
        return;
    }

    if (position == 1) {
        deletefront(head);
        return;
    }

    Node* temp = head;
    for (int i = 1; i < position - 1 && temp != nullptr; i++) {
        temp = temp->next;
    }

    if (!temp || !temp->next) {
        cout << "Position out of bounds!" << endl;
        return;
    }

    Node* toDelete = temp->next;
    temp->next = toDelete->next;
    delete toDelete;
}

void displaylist(Node* head) {
    if (!head) {
        cout << "List is empty!" << endl;
        return;
    }

    Node* temp = head;
    cout << "Linked List: ";
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}
