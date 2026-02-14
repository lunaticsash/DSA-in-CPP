#include<iostream>
using namespace std;

class ok{
    public:
     int a;
     int b;

    ok(int a, int b){
        this->a = a;
        this->b = b;
       cout<<"constructor is called"<<endl; 
    }

    void print(){
        cout<<"a: "<<a<<" b: "<<b<<endl;
    }
};

int main(){
    ok one(10,20);
    one.print();
}