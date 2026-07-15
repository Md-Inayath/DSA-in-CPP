#include <bits/stdc++.h>
using namespace std;

/*
Algorithm: Quick Sort (Lomuto Partition)

1. Choose the last element as the pivot.
2. Partition the array such that:
   - Elements less than or equal to the pivot are placed on the left.
   - Elements greater than the pivot are placed on the right.
3. Place the pivot in its correct sorted position.
4. Recursively apply Quick Sort on the left and right subarrays.


Time Complexity:

Best Case    : O(n log n)
Average Case : O(n log n)
Worst Case   : O(n²) (If pivot is max or min element in array).

Space Complexity

Average Case : O(log n)   // Recursion stack
Worst Case   : O(n)

*/

// Partition function using Lomuto Partition Scheme
int partition(int arr[], int low, int high) {
    int pivot = arr[high];   // Select the last element as the pivot
    int i = low;             // Marks the position for the next smaller element

    // Rearrange elements around the pivot
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            swap(arr[i], arr[j]);
            i++;
        }
    }

    // Place the pivot in its correct sorted position
    swap(arr[i], arr[high]);

    return i;
}

// Recursive Quick Sort function
void quick_sort(int arr[], int low, int high) {
    if (low < high) {
        int pIndex = partition(arr, low, high);

        // Sort the left subarray
        quick_sort(arr, low, pIndex - 1);

        // Sort the right subarray
        quick_sort(arr, pIndex + 1, high);
    }
}

int main() {
    int n;
    cin >> n;

    int arr[n];

    // Input array elements
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Perform Quick Sort
    quick_sort(arr, 0, n - 1);

    // Display the sorted array
    cout << "Sorted Array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}