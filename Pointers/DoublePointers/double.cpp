#include<iostream>
using namespace std;

void update(int **p2){
    // p2 = p2 + 1;//KUch change hoga?NO

    // *p2 = *p2+ 1;//change in p

    **p2 = **p2 + 1; //change in i
} 

int main(){
    int i  = 5;
    int *p = &i;

    int **p2 = &p;

    cout<<"sab shi "<<endl;
    

    // //5
    // cout<<"i "<<i<<endl;
    // cout<<"Printing *p "<<*p<<endl;
    // cout<<"Printing **p2 "<<**p2<<endl;

    // //Address of i 
    // cout<<"Address of i  "<<&i<<endl;
    // cout<<"Printing p "<<p<<endl;
    // cout<<"Printing *p2 "<<*p2<<endl;


    // //Address of p
    // cout<<"Printing &p "<<&p<<endl;
    // cout<<"Printing &p "<<&p<<endl;
    
    // //Address of p2
    // cout<<"Address of p2 "<<&p2<<endl;

    cout<<"Before "<<i<<endl;
    cout<<"Before "<<p<<endl;
    cout<<"Before "<<p2<<endl;

    update(p2);

    cout<<"After "<<i<<endl;
    cout<<"After "<<p<<endl;
    cout<<"After "<<p2<<endl;

    return 0;
}