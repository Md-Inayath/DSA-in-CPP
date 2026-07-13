/*
Bubble Sort (Optimized)

Time Complexity:
Best    : O(n)
Average : O(n²)
Worst   : O(n²)

Space Complexity: O(1)
In-place: Yes
*/
#include <bits/stdc++.h>
using namespace std;

void bubble_sort(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        bool swapped = false;

        // Largest element settles at the end after each pass.
        for (int j = 0; j < n - i - 1; j++) {

            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }

        // Stop if the array is already sorted.
        if (!swapped)
            break;
    }
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    bubble_sort(arr, n);
    cout << "Sorted Array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}