#include<bits/stdc++.h>
using namespace std;

int main(){

    vector<int> arr= {1,3,2,2,1,3,4,1,2,1};
    unordered_map<int,int> count;
    int maxFreq = 0;
    int maxans = 0;

    for(int i = 0; i<arr.size(); i++){
        count[arr[i]]++;
        maxFreq = max(maxFreq, count[arr[i]]);
    }

    for (int i = 0; i < arr.size(); i++)
    {
        if(maxFreq == count [arr[i]]){
            maxans = arr[i];
            break;
        }
    }

    cout<<maxans<<endl;
    
    return 0;
}