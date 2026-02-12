#include<iostream>
using namespace std;

int main(){

    int n;
    cin>>n;
    cout<<endl;
    int m;
    cin>>m;

    //Making of n*n array
    int ** arr = new int*[n];
    for(int i = 0; i<m; i++){
        arr[i] = new int [m];
    }

    //Creation done

    //Taking input
    for(int i = 0;i<n;i++){

        for(int j = 0; j<m;j++ ){

            cin>>arr[i][j];
        }
    }
    cout<<endl;
    
    //Print
    for(int i = 0;i<n;i++){

        for(int j = 0; j<m;j++ ){

            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

    //Releasing memory
    for(int i = 0; i<n;i++){
        delete [] arr[i];
    }
    delete []arr;
    

    return 0;
}