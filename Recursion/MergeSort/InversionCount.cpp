#include<iostream>

using namespace std;

void merge(int *arr, int s , int e, int *p){

    int mid = s + (e-s)/2;
    int length1= mid - s + 1;
    int length2= e - mid;

    //making 2 arrays
    int *first = new int[length1];
    int *second = new int[length2];

    //copying first array // k = MainArrayIndex
    int k = s;
    for(int i = 0; i<length1;i++){
        first[i]= arr[k++];
    }

    //copying second array
    k = mid + 1;
    for (int i = 0; i < length2; i++)
    {
        second[i] = arr[k++];
    }

    // Merge 2 arrays and sort them
    int index1= 0;
    int index2= 0;
    k = s;
    
    while(index1<length1 && index2<length2 ){
        if(first[index1]<second[index2]){
            arr[k++] = first[index1++];
        }
        else{
            arr[k++] = second[index2++];
            *p = length1 - index1; //No. of inversion count (Explaination in notebook)
        }
    }
    while (index1<length1)
    {
        arr[k++] = first[index1++];
    }
    while (index2<length2)
    {
        arr[k++] = second[index2++];
    }

    delete []first;
    delete []second;

    
}

void mergesort(int *arr, int s, int e, int *p){

    if(s>=e){
        return;
    }
    int mid = s + (e-s)/2;

    //Leftpart
    mergesort(arr, s, mid, p);

    //right part
    mergesort(arr, mid+1, e, p);

    //Merge Both
    merge(arr, s, e, p);
    
}

int main(){

    int arr[5] = {2,5,1,6,9};
    int n = 5;

    int count = 0;
    int *p = &count;

    mergesort(arr, 0, n-1, p);

    cout<<"Inversion count is "<<count<<endl;

    return 0;
}