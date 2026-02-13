#include <iostream>
using namespace std;

char GetMaxocc(string s)
{
    int arr[26] = {0};

    // Create an array of count of characters
    for (int i = 0; i < s.length(); i++)
    {
        char ch = s[i];
        // lowercase
        int number = 0;
        number = ch - 'a';
        arr[number]++;
    }

    // find maximum occuring character
    int maxi = -1, ans = 0;
    for (int i = 0; i < 26; i++)
    {
        if (maxi < arr[i])
        {
            ans = i;
            maxi = arr[i];
        }
    }

    char finalAns = 'a' + ans;
    return finalAns;
}

int main()
{

    string s;
    cin >> s;

    // cout<<s<<endl; //getline(cin, input); with spaces read krta hai

    cout << GetMaxocc(s) << endl;

    return 0;
}