#include <iostream>
using namespace std;

class Human
{

private:
    int name;

public:
    int height;
    int weight;
    int age;

public:
    int getAge()
    {
        return this->age;
    }

    void setAge(int a)
    {
        this->age = a; // age = a;
    }

    void setWeight(int w)
    {
        this->weight = w;
    }
};

class Male : private Human
{

public:
    string colour;

    void sleep()
    {
        cout << "Male sleeping" << endl;
    }

    int getHeight(){
        return this->height;
    }
};

int main()
{
    Male m1;
    cout << m1.getHeight() << endl;

    /*
        Male Object1;
        Object1.setAge(19);

        cout << Object1.age << endl;
        cout << Object1.weight << endl;
        cout << Object1.height << endl;
        // cout << Object1.name << endl; //Since age is a private member of Human

        cout << Object1.colour << endl;

        Object1.sleep();
    */

    return 0;
}
