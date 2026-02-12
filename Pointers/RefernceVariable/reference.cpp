#include<iostream>
using namespace std;

int& update3(int a){
    int num = a;
    int& ans = num;
    return ans;
}

int* fun(int n){
    int* ptr = &n;
    return ptr;
}

void update2(int &n){//Argument is a reference variable
    n++;
}
void update1(int n){
    n++;
}

int main(){

    // int i = 5;

    // //Creating a refernce variable

    // int &j =i;//reference variable of i

    // cout<<i<<endl;//5
    // i++;
    // cout<<i<<endl;//6
    // j++;
    // cout<<i<<endl;//7

    // cout<<&j<<" "<<&i<<endl;//0x61ff08 0x61ff08
    
    int n = 5;

    cout<<"Before :"<<n<<endl;
    update1(n);
    cout<<"After :"<<n<<endl<<endl;
    cout<<"Before :"<<n<<endl;
    update2(n);
    cout<<"After :"<<n<<endl<<endl;
    cout<<"Before :"<<n<<endl;
    update3(n);
    cout<<"After :"<<n<<endl<<endl;

    fun(n);//warning ayegi

    return 0;
}