#include<iostream>
using namespace std;

int main(){
    char name[20];

    cout<< "Enter your name: "<<endl;
    cin>>name;
    // name[2]= '\0'; means Pranjal input mai dalega to 'Pr' hi print hoga only.

    cout<<"Your name is ";
    cout<<name<<endl;

    return 0;
}
