#include <iostream>
#include <string.h>
using namespace std;

class Car
{
private:
    int speed;

public:
    Car(int s)
    {
        speed = s;
    }

    int getSpeed() const
    { // ✅ const function, safe for const objects
        return speed;
    }

    void setSpeed(int s)
    { // ❌ not allowed for const object
        speed = s;
    }
};

int main()
{
    const Car myCar(100); // 🔒 const object

    cout << myCar.getSpeed() << endl; // ✅ allowed

    // myCar.setSpeed(200);  // ❌ ERROR: can't call non-const function
}


// | Feature                | Meaning                                                       |
// | ---------------------- | ------------------------------------------------------------- |
// | `int speed;`           | Data member to store speed                                    |
// | `Car myCar;`           | Normal object, can modify data                                |
// | `const Car myCar;`     | Constant object, cannot modify data                           |
// | `int getSpeed() const` | Const member function, does not modify anything, safe to call |

// 💡 Why use const objects?
// To protect data from being changed.

// Useful when passing objects as arguments (read-only).

// Helps the compiler catch bugs if you try to accidentally modify values.

// C++ program to demonstrate the
// constant function
// #include <iostream>
// using namespace std;

// // Class Test
// class Test {
//     int value;

// public:
//     // Constructor
//     Test(int v = 0) { value = v; }

//     // We get compiler error if we
//     // add a line like "value = 100;"
//     // in this function.
//     int getValue() const { return value; }

//     // a nonconst function trying to modify value
//     void setValue(int val) { value = val; }
// };

// // Driver Code
// int main()
// {
//     // Object of the class T
//     Test t(20);

//     // non-const object invoking const function, no error
//     cout << t.getValue() << endl;

//     // const object
//     const Test t_const(10);

//     // const object invoking const function, no error
//     cout << t_const.getValue() << endl;

//     // const object invoking non-const function, CTE
//     // t_const.setValue(15);

//     // non-const object invoking non-const function, no
//     // error
//     t.setValue(12);

//     cout << t.getValue() << endl;

//     return 0;
// }