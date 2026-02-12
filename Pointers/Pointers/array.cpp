#include <iostream>
using namespace std;

int main()
{
    /*
    int arr[10]={2,5,6};
    cout << "address of first memory block is " << arr << endl;//address of first memory block is 0x61fee4
    cout << "address of first memory block is " << &arr[0] << endl;//address of first memory block is 0x61fee4
    
    int *ptr = &arr[0];
    cout<<ptr<<endl;//0x61fee4

    cout<<"4th "<<*arr<<endl;//2
    cout<<"5th "<<*arr + 1<<endl;//3
    cout<<"5th "<<*(arr + 1)<<endl;//5
    cout<<"6th "<<*(arr) + 1<<endl;//2+1=3
    cout<<"7th "<<(arr[2])<<endl;//6
    cout<<"8th "<<*(arr + 2)<<endl;//6

    int i = 2;
    cout<<"Chalaki "<< i[arr]<<endl;//6
    cout<<"Chalaki Address "<< &(arr[i])<<endl;//6
    cout<<"Chalaki Address "<< (i[arr])<<endl;//6

    int temp[10];

    int*p = &temp[0];

    cout<<"Size of temp "<<sizeof(temp)<<endl;
    cout<<"Size of p "<<sizeof(p)<<endl;
    cout<<"Size of p "<<sizeof(*p)<<endl;
    cout<<"Size of p "<<sizeof(&p)<<endl;

    */

    int a[20]={1,2,3,4};
    cout<<&a[0]<<endl;//ye address of a
    cout<<a<<endl;//ye address of a
    cout<<&a<<endl;//ye address of a

    int*p= &a[0];
    cout<<&p[0]<<endl;//ye address of a
    cout<<p<<endl;//ye address of a
    cout<<&p<<endl;//ye alag cz ye address of p hai na

    // int arr[10];
    // arr = arr+1; // ERROR CZ CANNOT CHANGE
    int arr[10]={0};
    *arr = *arr+1;

    cout<<"ok "<<*arr<<endl;//1;

    
    


    return 0;
}
