/*
Selection Sort

Time Complexity:
Best    : O(n²)
Average : O(n²)
Worst   : O(n²)

Space Complexity: O(1)
Stable: No
In-place: Yes
*/

#include <bits/stdc++.h>
using namespace std;

void selection_sort(int arr[], int n) {
    // Traverse array from 0 to n and let inner loop does partition.
    for (int i = 0; i < n; i++) {
        int mini = i;

        // Find the index of the minimum element.
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[mini]) {
                mini = j;
            }
        }

        // Place the minimum element at its correct position.
        swap(arr[mini], arr[i]);
    }
}

int main() {
    int n;
    cin >> n;

    int arr[n];

    // Read array elements.
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    selection_sort(arr, n);

    cout << "Sorted Array:\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}