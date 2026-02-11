#include <iostream>

using namespace std;

void reverse(int arr[], int n)
{

    int start = 0;
    int end = n - 1;

    while(start <= end)
    {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}

void printArray(int arr[], int n)
{

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr[7] = {3, 4, 8, 4, 3, 7, 4};
    int brr[5] = {5 , 6 , 8 , 3 , 6};

    reverse(arr, 7);
    reverse(brr, 5);

    printArray(arr, 7);
    printArray(brr, 5);

    return 0;
}