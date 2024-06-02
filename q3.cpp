#include <iostream>
#include <climits>
using namespace std;

struct MinMax { int min_val, max_val; };

MinMax findMinMax(int arr[], int n, int& steps) {
    MinMax result = {INT_MAX, INT_MIN};
    for (int i = 0; i < n; i++, steps += 2) {
        result.min_val = min(result.min_val, arr[i]);
        result.max_val = max(result.max_val, arr[i]);
        steps += 2; // for min and max comparison
    }
    return result;
}

int main() {
    int n;
    cout << "Enter the number of elements: "; cin >> n;
    int arr[n];
    cout << "Enter " << n << " elements:";
    for (int i = 0; i < n; cin >> arr[i++]);

    int steps = 0;
    MinMax result = findMinMax(arr, n, steps);

    cout << "Minimum element: " << result.min_val << "\nMaximum element: " << result.max_val << endl;
    cout << "Total steps taken: " << steps << endl;

    return 0;
}

