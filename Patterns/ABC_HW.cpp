#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int row = 1;
    while (row <= n) // jitne baar vertically chaiye
    {
        int col = 1; // j=1
        while (col <= n)
        {
        char ch = 'A' + col - 1;
        cout << ch;
        col = col +1;
        } // cz horizontally bhi utna hi chaiye, n ke jgh row tb hota jab hum triangle jaisa kr rhe hote
    cout<<endl;
    row= row+1;
    }
}