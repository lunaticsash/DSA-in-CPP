#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void insertionSort(int n, vector<int> &arr){
    
    for(int i = 1; i < n; i++){//0 vale ko to sorted hi liya and uske base pe sb compare and shift

        int temp =arr[i]; //storing for shifting
        int j = i - 1; //scope ke vjh se bahar likha
        for(;j>=0;j--){//left side aa rhe compare krte hue 
            if(arr[j]>temp){//a>b
                arr[j+1] =arr[j];//b ko a ke jagah bethaya
            } else {
                break;//pehle se sorted tb ek ek comparison mai khtm in which the T.C is O(n)
            }
        }
        arr[j+1] = temp;//a ko b ke jagah bethaya
    }
}