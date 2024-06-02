#include <iostream>
using namespace std;

void merge(int arr[], int left, int mid, int right, int& steps) {
    int n1 = mid - left + 1, n2 = right - mid, L[n1], R[n2], i = 0, j = 0, k = left;
    for (; i < n1; i++) L[i] = arr[left + i];
    for (; j < n2; j++) R[j] = arr[mid + 1 + j];
    for (i = 0, j = 0; k <= right; k++, steps++) {
        if (i < n1 && (j == n2 || L[i] <= R[j])) arr[k] = L[i++];
        else arr[k] = R[j++];
        steps++; // for array element assignment
    }
}

void mergeSort(int arr[], int left, int right, int& steps) {
    if (left >= right) return;
    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid, steps);
    mergeSort(arr, mid + 1, right, steps);
    merge(arr, left, mid, right, steps);
}

int main() {
    int n, steps = 0;
    cout << "Enter the number of elements: "; cin >> n;
    int arr[n];
    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; cin >> arr[i++]);
    
    mergeSort(arr, 0, n - 1, steps);

    cout << "Sorted array:\n";
    for (int i = 0; i < n; cout << arr[i++] << " ");
    cout << "\nTotal steps taken: " << steps << endl;
    
    return 0;
}

