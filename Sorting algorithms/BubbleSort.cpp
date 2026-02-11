#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void BubbleSort(vector<int> &arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    { // for round 1 t n-1
        bool swapped = false;
        
            for (int j = 0; j < n - i - 1; j++) // process element till(n-i-1)th index
            {
                if (arr[j] > arr[j + 1])
                {
                    swap(arr[j], arr[j + 1]);
                    swapped = true;
                }
            }
        
        if (swapped == false) // Already sorted
            break;
    }
}
