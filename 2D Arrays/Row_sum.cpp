#include <iostream>
#include <climits>
using namespace std;

int main()
{
    int row, col;

    cout << "Enter the number of rows: ";
    cin >> row;
    cout << "Enter the number of cols: ";
    cin >> col;
    int arr[row][col];

    for (int i = 0; i < row; i++)
    { // input in row format
        for (int j = 0; j < col; j++)
        {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < row; i++)
    { // output in row format
        for (int j = 0; j < col; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    

    int maxi = INT_MIN;
    int rowIndex = -1;
    // FOR ROW WISE SUM
    for (int i = 0; i < row; i++) // i = 1 skips the first row.
                                   // i <= row tries to access an invalid index at the end. THERE FORE DONT USE <= AND I = 1
    {   
        int sum = 0;
        for (int j = 0; j < col; j++)
        {
            sum = sum + arr[i][j];
        }

        cout << "Sum of " << i << " row is : " << sum << endl;
        maxi = max(maxi, sum);
        rowIndex = i+1;     
    }                                                         

    cout<<"Row with Maximum Sum : "<<maxi<<endl;
    cout<<"Row Index : "<<rowIndex<<endl;

    

    // FOR COLUMN WISE SUM
    // for (int i = 0; i < col; i++)
    // {
    //     int sum = 0;
    //     for (int j = 0; j < row; j++)
    //     {
    //         sum = sum + arr[i][j];
    //     }

    //     cout << "Sum of " << i << " row is : " << sum << endl;
    // }

    return 0;
}