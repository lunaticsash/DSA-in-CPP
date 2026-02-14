#include <iostream>
using namespace std;

class Student{

    private: //encapsulation + information hiding
    int rollNo;
    float marks;
    static int count;

    public:

    //Default constuructor
    Student(){
        rollNo = 0;
        marks = 0;
        count++;
        cout<<"Default constructor called\n";
    }

    //Parameterized constructor
    Student(int r, float m){
        rollNo = r; marks = m;
        count++;
        cout << "Parameterized constructor called\n";
    }

    //copy constructor
    Student(const Student& s){
        rollNo = s.rollNo;
        marks = s.marks;
        count++;
        cout<<"Copy constructor is called"<<endl; 
    }

    //dynamic constructor
    Student(string name){
        rollNo = new int(101); //dynamic allocation
        marks = 100;
        count++;
        cout << "Dynamic constructor for " << name << endl;
    }

    //Desdtructor
    ~ Student(){
        cout<<"destructor is called "<<endl;
        count--;
    }

    //Member fucntion defined outside scope resolution
    void display();

    //Static member fucntion
    static void showCount(){
        cout << "Total objects: " << count << endl;
    };

    // Operator Overloading (+)
    Student operator+(Student s){
        Student temp;
        temp.rollNo = rollNo + s.rollNo; //Just demo
        temp.marks = marks + s.marks;
        return temp;
    }

    //Explicit type conversion
    operator int(){
        return rollNo;
    }


};

int Student::count = 0;
void Student::display(){
    cout << "Roll: " << rollNo << " Marks: " << marks << endl;
}

int main(){

    Student s1;//default constructor
    Student s2(101, 95.5);//parameterized consturctor
    Student s3(s2);//copy constructor

    Student::showCount();//Static function

    s2.display();//member function call

    Student s4 = s2 + s3;//operator overloading
    s4.display();

    int roll =(int) s2; //Explaicit conversion

     cout << "Converted to int: " << roll << endl;


    return 0;//desturctor auto called here
}

