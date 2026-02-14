#include <iostream>
using namespace std;

class A
{
public:
    void sayHello()
    {
        cout << " Hello Pranjal " << endl;
    }
    int sayHello(string name, int n)
    {
        cout << " Hello Pranjal " << endl;
        return 1;
    }

    void sayHello(string name)
    {
        cout << " Hello " << name << endl;
    }
};

class B
{
public:
    int a;
    int b;

public:
    int add()
    {
        return a + b;
    }

    void operator+(B &obj)
    {
        int value1 = this->a;
        int value2 = obj.a;
        cout << "output is " << value2 - value1 << endl;
    }

    void operator() () {
        cout << "Ha bkl mai hi bracket hu " << endl;
    }
};

class Animal{
    public: 
    void speak(){
        cout<<"Speaking " << endl;
    }
};

class Dog : public Animal {
    public:
    void speak() {
        cout << "Barking " << endl;
    }   
};

int main()
{

    Dog obj;
    obj.speak();








    // B obj1, obj2;

    // obj1.a = 4;

    // obj2.a = 7;

    // obj1 + obj2;

    // obj1();

    // A obj;
    // obj.sayHello("ok");

    return 0;
}