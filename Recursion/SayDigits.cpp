#include <iostream>
using namespace std;

void sayDigit(int n, string arr[])
{
    // Base case
    if (n == 0)
        return;

    // processeing
    int digit = n % 10;
    n = n / 10;
    // cout<< arr[digit] <<" ";//yaha pe reverse ,ao print hoga

    //Recursive call
    sayDigit(n,arr);
    cout<< arr[digit] <<" ";//ab seedha
}

int main()
{

    string arr[10]={
        "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"
    };
    int n;
    cin >> n;

    cout<<endl<<endl<<endl;
    sayDigit(n,arr);
    cout<<endl;

    return 0;
}