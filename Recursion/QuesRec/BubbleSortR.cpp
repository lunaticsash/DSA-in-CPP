#include<iostream>
using namespace std;

void sortArray(int *arr, int n){
    //base case
    if(n==0 || n == 1){
        return;
    }
    
    //RC
    //1st case-largest element ko end mai pohiocha dega
    for (int i = 0; i < n - 1; i++)
    {
        if(arr[i]>arr[i+1]){
            swap(arr[i], arr[i+1]);
        }
    }
    sortArray(arr, n-1);
}

int main(){

    int arr[5] = {3,5,53,8,0};
    sortArray(arr,5);

    for (int i = 0; i < 5; i++)
    {
        cout<<arr[i]<<"";
    }

    return 0;
}