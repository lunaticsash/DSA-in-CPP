#include<iostream>
using namespace std;

void sortArray( int *arr,int start, int n){
    //Base case: starting index
    if(start >= n-1) return;

    //Find the index of the minumum element
    int minIndex = start;
    for (int i = start + 1; i <= n-1; i++)      
    {
        if(arr[i]<arr[minIndex]) minIndex = i;
    }

    //Swap
    if(minIndex != start) {
        swap(arr[start],arr[minIndex]);
    }

    //Recursive call
    sortArray(arr, start+1, n);

}

int main(){

    int arr[5] = {3,5,53,8,0};
    sortArray(arr,0,5);

    for (int i = 0; i < 5; i++)
    {
        cout<<arr[i]<<"";
    }

    return 0;
}