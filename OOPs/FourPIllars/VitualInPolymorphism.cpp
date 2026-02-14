// 🧠 Imagine This:
// You work in a company. There's a general employee (Base class), and then there's a Manager (Derived class).

// You have a pointer called bptr that refers to an employee — but this employee might be a Manager.
// So what should happen when you ask the employee to “show their role”? Should it always show the base "Employee" role, or should it show the actual role ("Manager")?

// This is where virtual functions help.

#include <iostream>
using namespace std;

class Employee {
public:
    virtual void showRole() {
        cout << "I am an employee" << endl;
    }
};

class Manager : public Employee {
public:
    void showRole() {
        cout << "I am a manager" << endl;
    }
};

int main() {
    Employee* bptr;
    Manager m;

    bptr = &m;

    bptr->showRole();  // ✅ Output: I am a manager (not "employee")
}

// 📌 Key Concept:
// bptr is a pointer of type Employee*, but it points to an object of type Manager.

// showRole() is virtual in the base class → so C++ checks at runtime: “What is the actual object here?”

// Since the actual object is a Manager, it runs Manager::showRole(), not Employee::showRole().