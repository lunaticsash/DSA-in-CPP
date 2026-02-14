#include<iostream>
using namespace std;

int partition( int arr[], int s, int e ){
    int pivot = arr[s];

    //Jitne number chhote hai pivot se
    int cnt = 0;
    for(int i = s+1; i<=e; i++){
        if (arr[i]<=pivot)  
        {
            cnt++;
        }
    }

    //place pivot at right position
    int pivotIndex = s + cnt;
    swap(arr[pivotIndex], arr[s]);

    //Left and right vala part smbhal rhe ab
    int i = s, j = e;

    while (i<pivotIndex &&j>pivotIndex)
    {
        while (arr[i]<= pivot)
        {
            i++;
        }

        while (arr[j]>pivot)
        {
            j--;
        }

        //Swap
        if (i<pivotIndex &&j>pivotIndex)
        {
            swap(arr[i++], arr[j--]);
        }

        return pivotIndex;

    }
    

}

void quicksort(int arr[], int s, int e){
    //base case
    if(s >= e){
        return;
    }

    //Partition karenge
    int p = partition(arr, s, e);

    //left part sort kro
    quicksort(arr, s, p-1);

    //Right part sort kro
    quicksort(arr, p+1, e);
    

}

int main(){
    
    int arr[5] = {2,4,1,6,9} ;
    int n = 5;

    quicksort(arr, 0, n-1);

    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    

    return 0;
}


// #include <bits/stdc++.h>

// using namespace std;

 

// int partition(vector<int> &arr, int start, int end) {

//     int pivot = arr[start];

//     int cnt = 0;

//     for (int i = start + 1; i <= end; i++) {

//       if (arr[i] <= pivot) {

//           cnt++;

//       }

//     }

//     int pivotindex = start+cnt;

//     swap(arr[pivotindex], arr[start]);

 

//     int i =start;

//     int j =end;

//     while (i < pivotindex && j > pivotindex) {

//       while (arr[i]<=pivot) {

//           i++;

//       }

//       while (arr[j]>pivot) {

//           j--;

//       }

//       if (i < pivotindex && j > pivotindex) {

//           swap(arr[i++],arr[j--]);

//       }

//     }

//     return pivotindex;

// }

// void quick_sort(vector<int> &arr, int start, int end) {

//   if (start >= end) {

//       return;

//   }

 

//   int p = partition(arr,start,end);

//   quick_sort(arr,start,p-1);

//   quick_sort(arr,p+1,end);

// }

// vector<int> quickSort(vector<int> arr)

// {

//     int start = 0;

//     int end = arr.size()-1;

//     quick_sort(arr,start,end);

//     return arr;

// }