#include<iostream>
using namespace std;

//Encapsulation
class Student {
    private:
    string name;
    int age;
    int height;

    public:
    int getAge(){
        return this->age;
    }
};

int main(){

    Student first;

    cout<<":Sab shi chal raha hai" << endl;

    return 0;
}


class Student {
private:
    int marks;  // hidden data

public:
    void setMarks(int m) {  // controlled access
        marks = m;
    }

    int getMarks() {
        return marks;
    }
};
