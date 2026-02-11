#include <iostream>
using namespace std;

int BinarySearch(int arr[], int size, int key)
{

    int start = 0;
    int end = size - 1;

    int mid = (start + end) / 2;// mid = e + (s - e)/2 for not going out of range of int

    while (start <= end)
    {

        if (arr[mid] == key)
        {
            return mid;
        }

        // go to right vala part
        if (key > arr[mid])
        {
            start = mid + 1;
        }

        // go to left vala part
        else
        {
            end = mid - 1;
        }
        mid = (start + end) / 2; // updating the mid value
    }
    return -1;
}

int main()
{

    int even[6] = {2, 4, 6, 8, 10, 12}; // should me kmonotonic which means decreasing order or increasing order

    int odd[5] = {3, 8, 11, 14, 16};

    int index = BinarySearch(even, 6, 10);

    cout << "Index of 10 is " << index << endl;

    return 0;
}