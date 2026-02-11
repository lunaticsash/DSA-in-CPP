#include<iostream>
using namespace std;

//HOLD
void printArray(){

}

int main(){
 
    //declare
    int number[15];

    cout<<"value at zero index "<< number[1]<< endl;//garbage value

    cout<<"value at 20 index "<< number[20]<< endl; //garbage value

    //intialising an array
    int second[3]={5,7,11}; // index {0,1,2}
    cout<<"value at 2 index "<< second[2]<< endl;

    int third[15]={2,15};
    
    int n= 15;
    cout<<"printing the array"<<endl;
    //print the array
    for(int i = 0;i<n; i++){
    cout<<third[i]<<" ";
    }

//❤️
    int fourth[10]={0}; //saare zero , agar zero ke jagah one likha to saare one nhi honge bs pehle vala one fir saare 0
    
    // int n= 10;  //ek usi naam ka dibba hai
    n =10;
    cout<<"printing the array"<<endl;
    //print the array
    for(int i = 0;i<n; i++){
    cout<<fourth[i]<<" ";
    }


    //accessing and element

    cout<< endl<< "everything is fine "<< endl<<endl;



}