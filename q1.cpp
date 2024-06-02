#include <iostream>
using namespace std;

void insertionSort(int arr[], int n, int &steps) {
    for (int i = 1; i < n; i++)
        for (int j = i - 1; j >= 0 && arr[j] > arr[j + 1]; j--, steps++)
            swap(arr[j], arr[j + 1]);
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " elements:";
    for (int i = 0; i < n; cin >> arr[i++]);

    int steps = 0;

    insertionSort(arr, n, steps);

    cout << "Sorted array:" << endl;
    for (int i = 0; i < n; cout << arr[i++] << " ");
    cout << "\nTotal steps taken: " << steps << endl;

    return 0;
}

