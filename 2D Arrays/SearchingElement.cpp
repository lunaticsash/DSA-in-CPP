#include <iostream>
using namespace std;

bool isPresent(int arr[][4], int target, int row){
    for(int i = 0; i < row; i++){
        for(int j = 0 ; j < 4 ; j++){
            if(arr[i][j]==target){
                return 1;
            }
        }
    }
    return 0;
}


int main(){

    int arr[3][4];

    for(int i=0;i<3;i++){
        for(int j=0;j<4;j++){
            cin>>arr[i][j];
        }
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    cout<<"Element to Find : "<<endl;
    int target;
    cin>>target;

    if(isPresent(arr, target, 3)){
        cout<<"Element is Present"<<endl;
    }
    else{
        cout<<"Element is not Present"<<endl;
    }
    

    return 0;
}