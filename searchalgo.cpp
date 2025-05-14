#include <iostream>
using namespace std;

// Fibonacci Search function
int fibonacciSearch(int arr[], int n, int key) {
    int fibMMm2 = 0;  // (m-2)'th Fibonacci No.
    int fibMMm1 = 1;  // (m-1)'th Fibonacci No.
    int fibM = fibMMm2 + fibMMm1;  // m'th Fibonacci No.

    // Find the smallest Fibonacci number greater than or equal to n
    while (fibM < n) {
        fibMMm2 = fibMMm1;
        fibMMm1 = fibM;
        fibM = fibMMm2 + fibMMm1;
    }

    // Start from the found Fibonacci number and check positions
    int offset = -1;

    // Loop until we find the element or end the search
    while (fibM > 1) {
        // Check if fibMMm2 is a valid index
        int i = min(offset + fibMMm2, n - 1);

        // If key is greater, move the range to the right
        if (arr[i] < key) {
            fibM = fibMMm1;
            fibMMm1 = fibMMm2;
            fibMMm2 = fibM - fibMMm1;
            offset = i;
        }
        // If key is smaller, move the range to the left
        else if (arr[i] > key) {
            fibM = fibMMm2;
            fibMMm2 = fibMMm1 - fibMMm2;
            fibMMm1 = fibM - fibMMm2;
        }
        // Key found
        else {
            return i;
        }
    }

    // Comparing the last element with the key
    if (fibMMm1 && arr[offset + 1] == key) {
        return offset + 1;
    }

    // Key not found
    return -1;
}

// Binary Search function
int binarySearch(int arr[], int low, int high, int key) {
    while (low <= high) {
        int mid = low + (high - low) / 2;

        // If key is at the middle
        if (arr[mid] == key)
            return mid;
        
        // If key is greater, ignore the left half
        if (arr[mid] < key)
            low = mid + 1;
        // If key is smaller, ignore the right half
        else
            high = mid - 1;
    }

    // Key not found
    return -1;
}

int main() {
    int choice, n, key;

    do {
        cout << "\n----- Search Menu -----\n";
        cout << "1. Perform Fibonacci Search\n";
        cout << "2. Perform Binary Search\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                cout << "Enter the number of elements: ";
                cin >> n;

                int arr[n];

                cout << "Enter " << n << " sorted elements: ";
                for (int i = 0; i < n; i++) {
                    cin >> arr[i];
                }

                cout << "Enter the element to search: ";
                cin >> key;

                int result = fibonacciSearch(arr, n, key);

                if (result != -1)
                    cout << "Element found at index " << result << endl;
                else
                    cout << "Element not found\n";
                break;
            }

            case 2: {
                cout << "Enter the number of elements: ";
                cin >> n;

                int arr[n];

                cout << "Enter " << n << " sorted elements: ";
                for (int i = 0; i < n; i++) {
                    cin >> arr[i];
                }

                cout << "Enter the element to search: ";
                cin >> key;

                int result = binarySearch(arr, 0, n - 1, key);

                if (result != -1)
                    cout << "Element found at index " << result << endl;
                else
                    cout << "Element not found\n";
                break;
            }

            case 3:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 3);

    return 0;
}
