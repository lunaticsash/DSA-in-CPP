// https://www.geeksforgeeks.org/merge-sort/

#include <iostream>
using namespace std;

void merge(int *arr, int s, int e)
{
    int mid = (s + e) / 2;
    int length1 = mid - s + 1; // First vale ki Length.
    int length2 = e - mid;     // Second vale ki Length.

    // Creating 2 arrays
    int *first = new int[length1];
    int *second = new int[length2];

    // Copy values:1
    int MainArrayIndex = s;
    for (int i = 0; i < length1; i++)
    {
        first[i] = arr[MainArrayIndex++];
    }

    // Copy values:2
    MainArrayIndex = mid + 1;
    for (int i = 0; i < length2; i++)
    {
        second[i] = arr[MainArrayIndex++];
    }

    // Merge 2 Sorted arrays
    int index1 = 0;
    int index2 = 0;
    MainArrayIndex = s;

    while (index1 < length1 && index2 < length2)
    {
        if (first[index1] < second[index2])
        {
            arr[MainArrayIndex++] = first[index1++];
        }
        else
        {
            arr[MainArrayIndex++] = second[index2++];
        }
    }
    while (index1 < length1)
    {
        arr[MainArrayIndex++] = first[index1++];
    }
    while (index2 < length2)
    {
        arr[MainArrayIndex++] = second[index2++];
    }

    delete[] first;
    delete[] second;
}

void mergeSort(int *arr, int s, int e)
{

    // Base case
    if (s >= e)
    {
        return;
    }

    int mid = (s + e) / 2;
    // left part sort
    mergeSort(arr, s, mid);

    // Right part sort
    mergeSort(arr, mid + 1, e);

    // Merge both
    merge(arr, s, e);
}

int main()
{
    int arr[5] = {2, 5, 1, 6, 9};
    int n = 5;
    mergeSort(arr, 0, n - 1); // Array, Start, End

    for (int i = 0; i < 5; i++)
    {
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