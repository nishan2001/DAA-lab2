#include <iostream>
using namespace std;

int partition(int arr[], int low, int high, int& steps) {
    int pivot = arr[high], i = low - 1;
    for (int j = low; j <= high - 1; ++j, steps += 2)
        if (arr[j] < pivot) swap(arr[++i], arr[j]), steps += 3;
    swap(arr[i + 1], arr[high]), steps += 3;
    return i + 1;
}

void quickSort(int arr[], int low, int high, int& steps) {
    if (low < high) {
        int pi = partition(arr, low, high, steps);
        quickSort(arr, low, pi - 1, steps);
        quickSort(arr, pi + 1, high, steps);
    }
}

int main() {
    int n, steps = 0;
    cout << "Enter the number of elements: "; cin >> n;
    int arr[n];
    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; cin >> arr[i++]);

    quickSort(arr, 0, n - 1, steps);

    cout << "Sorted array:\n";
    for (int i = 0; i < n; cout << arr[i++] << " ");
    cout << "\nTotal steps taken: " << steps << endl;

    return 0;
}

