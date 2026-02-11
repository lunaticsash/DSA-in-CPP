#include <iostream>
using namespace std;
#include <climits>

// for minimum
int GetMin(int number[], int n)
{

    int min = INT_MAX;

    for (int i = 0; i < n; i++)
    {
        if (number[i] < min)
        {
            min = number[i]; //updating the value
        }
    }
    return min;
}

// for maximum
int GetMax(int number[] /*array*/, int n /*size*/)
{

    int max = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        if (number[i] > max)
        {
            max = number[i]; // updating the value
        }
    }
    return max;
}

int main()
{

    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    int num[100];

    // taking input in array
    for (int i = 0; i < size; i++)
    {
        cin >> num[i];
    }

    cout << "Max value from the given values is " << GetMax(num, size) << endl;
    cout << "Min  value from the given values is " << GetMin(num, size) << endl;
}