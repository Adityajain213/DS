#include<iostream>
using namespace std;

void fibonacciSeries(int num) {
    int first = 0, second = 1, next;

    cout << "Fibonacci Series: ";
    for (int i = 0; i < num; i++) {
        cout << first << " ";
        next = first + second;
        first = second;
        second = next;
    }
    cout << endl;
}

int main() {
    int choice, num;

    do {
        cout << "\n==== Menu ====\n";
        cout << "1. Print Fibonacci Series\n";
        cout << "2. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the number of terms you want in the series: ";
                cin >> num;
                fibonacciSeries(num);
                break;
            case 2:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 2);

    return 0;
}
