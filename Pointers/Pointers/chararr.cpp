#include<iostream>

using namespace std;

int main(){
    int arr[5]={1,2,3,4,5};

    char ch[6]="abcde";//since it ends with \0

    cout<< arr<<endl;//address

    cout<<ch<<endl;//content = abcde

    char *c = &ch[0];
    cout<<c<<endl;//abcde NORMAL ARR MAI ADDRESS PRINT HOTA THA

    char temp = 'z';
    char *p = &temp;

    cout<<p<<endl;




    return 0;
}