#include <bits/stdc++.h>
using namespace std;

/*

Merge Sort

Idea:
1. Divide the array into two halves.
2. Recursively sort both halves.
3. Merge the two sorted halves into a single sorted array.

Time Complexity:
- Best Case    : O(n log n)
- Average Case : O(n log n)
- Worst Case   : O(n log n)

Space Complexity:
- O(n) (Temporary array used during merging)

Stable: Yes
In-place: No
*/

// Merges two sorted halves:
// Left  -> [low ... mid]
// Right -> [mid + 1 ... high]
void merge(int arr[], int low, int mid, int high) {

    int left = low;
    int right = mid + 1;

    vector<int> temp;

    // Compare elements from both halves
    while (left <= mid && right <= high) {

        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        }
        else {
            temp.push_back(arr[right]);
            right++;
        }
    }

    // Copy remaining elements from left half
    while (left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }

    // Copy remaining elements from right half
    while (right <= high) {
        temp.push_back(arr[right]);
        right++;
    }

    // Copy merged elements back to original array
    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }
}

// Recursively divides the array until each subarray
// contains only one element, then merges them back.
void merge_sort(int arr[], int low, int high) {

    // Base case: A single element is already sorted
    if (low >= high)
        return;

    int mid = low + (high - low) / 2;

    // Sort left half
    merge_sort(arr, low, mid);

    // Sort right half
    merge_sort(arr, mid + 1, high);

    // Merge both sorted halves
    merge(arr, low, mid, high);
}

int main() {

    int n;
    cin >> n;

    int arr[n];

    // Input array
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    merge_sort(arr, 0, n - 1);
    
    // Print sorted array
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}