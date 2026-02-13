#include<iostream>
using namespace std ; 

int main(){

    int n;
    cin>>n;

    int row = 1;
    while(row <= n){
        //for spaces
        int space = n - row;
        while(space){
            cout<<" ";
            space--;
        
        }
        //for numbers
        int col = 1;
        
        while(col<=row){
            cout<<col;
            col++;
        }
        // for decreasing numbers
        int dec = row - 1;
        while(dec > 0){
            cout << dec;
            dec--;
        }
        cout<<endl;
        row++;

    }
    return 0;
}
