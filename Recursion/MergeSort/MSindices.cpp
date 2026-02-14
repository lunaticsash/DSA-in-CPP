#include <iostream>
using namespace std;

void merge(int *arr, int s, int e) {
    int mid = (s + e) / 2;

    int i = s;       // Pointer for the left subarray
    int j = mid + 1; // Pointer for the right subarray
    int k = 0;       // Pointer for the temporary array

    // Temporary array to store the merged result
    int temp[e - s + 1];

    // Merge the two subarrays
    while (i <= mid && j <= e) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }

    // Copy remaining elements from the left subarray
    while (i <= mid) {
        temp[k++] = arr[i++];
    }

    // Copy remaining elements from the right subarray
    while (j <= e) {
        temp[k++] = arr[j++];
    }

    // Copy the merged result back to the original array
    for (int x = 0; x < k; x++) {
        arr[s + x] = temp[x];
    }
}

void mergeSort(int *arr, int s, int e) {
    // Base case
    if (s >= e) {
        return;
    }

    int mid = (s + e) / 2;

    // Left part sort
    mergeSort(arr, s, mid);

    // Right part sort
    mergeSort(arr, mid + 1, e);

    // Merge both
    merge(arr, s, e);
}

int main() {
    int arr[5] = {2, 5, 1, 6, 9};
    int n = 5;
    mergeSort(arr, 0, n - 1); // Array, Start, End

    for (int i = 0; i < 5; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}

// Time Complexity:
// Best Case: O(n log n), When the array is already sorted or nearly sorted.
// Average Case: O(n log n), When the array is randomly ordered.
// Worst Case: O(n log n), When the array is sorted in reverse order.
// Auxiliary Space: O(n), Additional space is required for the temporary array used during merging.

// Applications of Merge Sort:
// Sorting large datasets
// External sorting (when the dataset is too large to fit in memory)
// Inversion counting
// Merge Sort and its variations are used in library methods of programming languages.
// Its variation TimSort is used in Python, Java Android and Swift. The main reason why it is preferred to sort non-primitive types is stability which is not there in QuickSort.
// Arrays.sort in Java uses QuickSort while Collections.sort uses MergeSort.
// It is a preferred algorithm for sorting Linked lists.
// It can be easily parallelized as we can independently sort subarrays and then merge.
// The merge function of merge sort to efficiently solve the problems like union and intersection of two sorted arrays.