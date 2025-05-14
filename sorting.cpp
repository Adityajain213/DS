#include <iostream>
#include <vector>
using namespace std;

void bubblesort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
}

void selectionsort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++)
            if (arr[j] < arr[minIdx])
                minIdx = j;
        swap(arr[i], arr[minIdx]);
    }
}

void insertion(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int temp = arr[i], j = i - 1;
        while (j >= 0 && arr[j] > temp) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high], i = low - 1;
    for (int j = low; j <= high - 1; j++)
        if (arr[j] < pivot)
            swap(arr[++i], arr[j]);
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void merge(vector<int>& arr, int st, int mid, int end) {
    vector<int> temp;
    int i = st, j = mid + 1;
    while (i <= mid && j <= end)
        temp.push_back(arr[i] <= arr[j] ? arr[i++] : arr[j++]);
    while (i <= mid) temp.push_back(arr[i++]);
    while (j <= end) temp.push_back(arr[j++]);
    for (int k = 0; k < temp.size(); k++)
        arr[st + k] = temp[k];
}

void mergesort(vector<int>& arr, int st, int end) {
    if (st >= end) return;
    int mid = (st + end) / 2;
    mergesort(arr, st, mid);
    mergesort(arr, mid + 1, end);
    merge(arr, st, mid, end);
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int n, choice;
    cout << "Enter number of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    do {
        cout << "\n--- Sorting Menu ---\n";
        cout << "1. Bubble Sort\n";
        cout << "2. Selection Sort\n";
        cout << "3. Insertion Sort\n";
        cout << "4. Quick Sort\n";
        cout << "5. Merge Sort\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            bubblesort(arr, n);
            printArray(arr, n);
            break;
        case 2:
            selectionsort(arr, n);
            printArray(arr, n);
            break;
        case 3:
            insertion(arr, n);
            printArray(arr, n);
            break;
        case 4:
            quickSort(arr, 0, n - 1);
            printArray(arr, n);
            break;
        case 5: {
            vector<int> vec(arr, arr + n);
            mergesort(vec, 0, n - 1);
            for (int x : vec)
                cout << x << " ";
            cout << endl;
            break;
        }
        case 6:
            cout << "Exiting.\n";
            break;
        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 6);

    return 0;
}
