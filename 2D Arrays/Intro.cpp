#include <iostream>
using namespace std;


int main()
{
    int arr[3][4];

    // creating 2D array
    // int arr[3][4] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 12}; 
    // //1 2 3 4
    // //5 6 7 8
    // //9 10 11 12

    // int arr[3][4] = {{1,11,111,1111}, {2,22,222,2222}, {3,33,333,3333}};//row wise gye  

    // cin>>arr[3][3]; // This is wrong way to take input in 2D array
    // cin>>arr[0][0]; // This is also wrong way to take input in 2D array

    
    //right way of taking input // It take row wise Input
    for(int i=0;i<3;i++){
        for(int j=0;j<4;j++){
            cin>>arr[i][j];
        }
    } 

    // It take col wise Input
    // for (int i = 0; i < 4; i++)
    // {
    //     for (int j = 0; j < 3; j++)
    //     {
    //         cin >> arr[j][i];
    //     } // 1 2 3 4 5 6 7 8 9 10 11 12
    // }
    // 1 4 7 10
    // 2 5 8 11
    // 3 6 9 12

    // print 2D array
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
