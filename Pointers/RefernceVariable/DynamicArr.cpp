#include <iostream>
using namespace std;

int getSum(int *arr, int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    return sum;
}

int main()
{

    // char ch = 'q';
    // cout << sizeof(ch) << endl;

    // char *chr = &ch;
    // cout << sizeof(chr) << endl;

    // char *chrp = new char; // Heap memory or Dynamic Allocation memory

    // int *arr = new int[5]; // to create an array fo size 5 and name arr

    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int ans = getSum(arr, n) ; 
    cout<<ans<<endl;

    while(1){
        int i = 5;
    }

    // while(1){ //BHAYANAK
    //     int* ptr = new int;
    // }

    return 0;
}