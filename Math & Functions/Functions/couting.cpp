#include<iostream>
using namespace std;

// function signature
void printCounting(int n){ // void do not return any value, it prints only
    //function Body
    for(int i = 1; i<=n;i++){
        
        cout<< i << " "<<endl;
    }
}

int main(){

    int n;

    cin>>n;
    //function call
    printCounting(n);


    return 0; // Indicates successful execution
}