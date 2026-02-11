#include <iostream>
#include <algorithm>
using namespace std;

int reverse(int arr[][3], int row)
{
    for (int i = 0; i < row; i++)
    {
        int j = 0;
        int k = 3 - 1; // 3 is number of columns
        while (j < k)
        {
            swap(arr[i][j], arr[i][k]);
            j++;
            k--;
        }
    }
}

int transverse(int arr[][3], int row)
{
    // int startingRow = 0;
    // int startingCol = 0;
    // j = i + 1 dene se bhi kaam ho jayega

    for (int i = 0; i < row; i++)
    {
        for (int j = i + 1; j < 3; j++)
        {
            swap(arr[i][j], arr[j][i]);
        }
        // startingRow++;
        // startingCol++;
    }
}

int main()
{

    int arr[3][3] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    transverse(arr, 3);
    reverse(arr, 3);

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
