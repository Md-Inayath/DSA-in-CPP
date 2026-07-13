
// Insertion Sort in C++
// Time Complexity:

// Best Case    : O(n)
// Average Case : O(n^2)
// Worst Case   : O(n^2)
// Space Complexity : O(1)
// Stable Sorting Algorithm

#include <iostream>
using namespace std;

// Function to perform Insertion Sort
void insertion_sort(int arr[], int n)
{
    // Traverse the array starting from the second element
    // because a single element is already considered sorted.
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;
        // Keep shifting larger elements one position to the right

        while (j >= 0 && arr[j] > key)
        {
            // Shift the larger element to the right.
            arr[j + 1] = arr[j];

            // Move to the previous element.
            j--;
        }

        // Place the key in its correct sorted position.
        arr[j + 1] = key;
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
    insertion_sort(arr, n);
    cout << "Sorted Array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}