#include <iostream>
#include <vector>
using namespace std;

#define TABLE_SIZE 11
#define MAX_DISPLACEMENTS 20

class CuckooHashing {
    int table[2][TABLE_SIZE];
    int size;

public:
    CuckooHashing() {
        size = TABLE_SIZE;
        for (int i = 0; i < size; i++) {
            table[0][i] = -1;
            table[1][i] = -1;
        }
    }

    int hash(int function, int key) {
        if (function == 0)
            return key % size;
        else
            return (key / size) % size;
    }

    bool insert(int key) {
        if (search(key)) {
            cout << "Key already present!" << endl;
            return false;
        }

        int pos, tempKey = key;
        int tableId = 0;

        for (int i = 0; i < MAX_DISPLACEMENTS; i++) {
            pos = hash(tableId, tempKey);
            swap(tempKey, table[tableId][pos]);

            if (tempKey == -1)
                return true;

            tableId = 1 - tableId;  // Switch tables
        }

        cout << "Cycle detected, insertion failed for key: " << key << endl;
        return false;
    }

    bool search(int key) {
        if (table[0][hash(0, key)] == key)
            return true;
        if (table[1][hash(1, key)] == key)
            return true;
        return false;
    }

    void display() {
        cout << "Table 0: ";
        for (int i = 0; i < size; i++) {
            if (table[0][i] != -1)
                cout << table[0][i] << " ";
            else
                cout << "- ";
        }
        cout << endl;

        cout << "Table 1: ";
        for (int i = 0; i < size; i++) {
            if (table[1][i] != -1)
                cout << table[1][i] << " ";
            else
                cout << "- ";
        }
        cout << endl;
    }
};

int main() {
    CuckooHashing ht;
    int choice, key;

    do {
        cout << "\n==== Menu ====\n";
        cout << "1. Insert key\n";
        cout << "2. Search key\n";
        cout << "3. Display tables\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter key to insert: ";
            cin >> key;
            ht.insert(key);
            break;
        case 2:
            cout << "Enter key to search: ";
            cin >> key;
            if (ht.search(key))
                cout << "Key found!\n";
            else
                cout << "Key not found!\n";
            break;
        case 3:
            ht.display();
            break;
        case 4:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice, try again.\n";
        }
    } while (choice != 4);

    return 0;
}
