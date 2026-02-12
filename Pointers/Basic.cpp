#include <iostream>
using namespace std;

int main()
{
    // int num = 5;
    // cout<<num<<endl;

    // //addresss of operator -&

    // cout<<"address of num is "<<&num<<endl; //0x61ff0c

    // int *ptr = &num;//* is derefernece operator

    // cout<<"value is : "<<ptr<<endl; //0x61ff08
    // cout<<"value is : "<<*ptr<<endl; //5 

    // cout<<"Size of integer is "<<sizeof(num)<<endl;
    // cout<<"Value is " <<sizeof(ptr)<<endl;

    //pointer to int is created and pointing to some garbage address
    // int *p=nullptr;

    // cout<<*p;//Ajeeb si value ajayegi jo kii hum bhi nhi jante kaha se aa jayegi

    // int i = 5;

    // int *q=&i;
    // cout<<q<<endl;
    // cout<<*q<<endl;


    // int *p= 0;
    // p = &i;
    
    // cout<<p<<endl;
    // cout<<*p<<endl;

    // int num = 5;
    // // int a = num;
    // // a++;

    // int*p=&num;
    // int a = *p;
    // a++;

    // cout<<num<<endl;//5

    //copying a pointer
    // int *q = p;
    // cout<<p<<"_"<<q<<endl;//0x61ff00_0x61ff00
    
    // cout<<*p<<"_"<<*q<<endl;//5_5


    int i = 15;
    int *t=&i;
    cout<< (*t)++<<endl;

    t = t + 1;
    cout<<t<<endl;
    

    return 0;
}   