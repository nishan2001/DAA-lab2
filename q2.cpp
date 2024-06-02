#include <iostream>
using namespace std;

void selectionSort(int arr[], int n, int &steps) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++, steps++)
            if (arr[j] < arr[min_idx])
                min_idx = j;
        if (min_idx != i)
            swap(arr[i], arr[min_idx]);
    }
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " elements:" ;
    for (int i = 0; i < n; cin >> arr[i++]);

    int steps = 0;
    selectionSort(arr, n, steps);

    cout << "Sorted array:" << endl;
    for (int i = 0; i < n; cout << arr[i++] << " ");
    cout << "\nTotal steps taken: " << steps << endl;

    return 0;
}

