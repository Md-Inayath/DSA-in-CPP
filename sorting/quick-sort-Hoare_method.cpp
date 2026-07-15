#include <bits/stdc++.h>
using namespace std;

/*

Algorithm: Quick Sort (Hoare Partition)

1. Choose the first element as the pivot.
2. Move pointer 'i' from left to right until an element
   greater than the pivot is found.
3. Move pointer 'j' from right to left until an element
   less than or equal to the pivot is found.
4. If i < j, swap arr[i] and arr[j].
5. When i >= j, swap the pivot with arr[j].
6. Recursively apply Quick Sort on the left and right
   subarrays.

Time Complexity:
Best Case    : O(n log n)
Average Case : O(n log n)
Worst Case   : O(n²)

Space Complexity

Average Case : O(log n)   // Recursion stack
Worst Case   : O(n)

*/

// Partition function using Hoare Partition Scheme
int partition(int arr[], int low, int high) {
    int pivot = arr[low];   // Select the first element as the pivot
    int i = low;
    int j = high;

    while (i < j) {

        // Find the first element greater than the pivot
        while (i <= high - 1 && arr[i] <= pivot)
            i++;

        // Find the first element less than or equal to the pivot
        while (j >= low + 1 && arr[j] > pivot)
            j--;

        // Swap elements if pointers haven't crossed
        if (i < j)
            swap(arr[i], arr[j]);
    }

    // Place the pivot in its correct sorted position
    swap(arr[low], arr[j]);

    return j;
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