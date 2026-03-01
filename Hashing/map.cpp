#include <iostream>
#include <map>
using namespace std;

int main()
{

    int n;
    cin >> n;
    int arr[n];
    map<int, int> mpp;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        mpp[arr[i]]++;
    }

    // Pre-compute
    //  map<int, int> mpp;
    //  for(int i = 0; i <n; i++){
    //      mpp[arr[i]]++;
    //  }

    // //Iterate in the map;
    // for(auto it : mpp){
    //     cout<<it.first<<"->"<<it.second<<endl ;
    // }

    int q;
    cin >> q;
    while (q--)
    {
        int number;
        cin >> number;
        // fetch
        cout << mpp[number] << endl;
    }

    return 0;
}