#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int row = 1;
    while (row <= n){ // to finish
        int star = n - row + 1; 
        int col = 1;
        while(col<= star){ //for stars
            cout<<"*";
            col++;
        }
        cout<<endl;
        row++;

    }
    
    return 0;
}