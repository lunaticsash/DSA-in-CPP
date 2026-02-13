#include <iostream>
using namespace std;

int main()
{

    int n;
    cin >> n;

    int row = 1;
    
    while (row <= n)
    {
        int col = 1;
        char start = 'A' + (row - 1) * n;
         
        while (col <= n)
        {
            cout << start;
            col = col + 1;
            start = start + 1;
        }
        cout << endl;
        row = row + 1;
    }
}