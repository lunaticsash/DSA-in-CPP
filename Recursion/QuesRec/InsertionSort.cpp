#include <iostream>
using namespace std;

// Recursive function to sort the array using insertion sort
void recursiveInsertionSort(int *arr, int n) {
    // Base case: if size is 1 or less, it's already sorted
    if (n <= 1)
        return;

    // Recursively sort first n-1 elements
    recursiveInsertionSort(arr, n - 1);

    // Insert the last element at its correct position
    int last = arr[n - 1];
    int j = n - 2;

    // Move elements of arr[0..n-2], that are greater than last, one position ahead
    while (j >= 0 && arr[j] > last) {
        arr[j + 1] = arr[j];
        j--;
    }

    arr[j + 1] = last;
}

int main() {
    int arr[] = {5, 2, 9, 1, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    recursiveInsertionSort(arr, n);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}

