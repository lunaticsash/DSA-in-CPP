#include <iostream>
#include <cstdint>
using namespace std;

// int main() {
//     int a = 10;

//     double b = 5.5;
//     char c = 'X';

//     void* ptr; // Generic pointer

//     ptr = &a; // Storing integer address
//     cout << "Integer: " << *(static_cast<int*>(ptr)) << endl;

//     ptr = &b; // Storing double address
//     cout << "Double: " << *(static_cast<double*>(ptr)) << endl;

//     ptr = &c; // Storing char address
//     cout << "Char: " << *(static_cast<char*>(ptr)) << endl;

//     cout << "Integer: " << *(static_cast<int*>(ptr)) << endl;//88=>X

//     return 0;
// }

int main()
{
    // int a = 42;
    // int* ptr = &a;

    // int* newPtr = reinterpret_cast<int*>(ptr);
    // cout<<*newPtr<<endl; //ok

    // char c = 'A';
    // char *charPtr = &c;

    // // ❌ static_cast<int*>(charPtr); // ERROR: Invalid conversion
    //  *intPtr = reinterpret_cast<int *>(charPtr); // ✅ Works, but unsafe

    // cout << *intPtr << endl; // May cause undefined behavior//garbage value

    // char c = 'A';
    // int intValue = static_cast<int>(c); // ✅ Safe conversion

    
    char c = 'A';
    char* charPtr = &c;
    uintptr_t address = reinterpret_cast<uintptr_t>(charPtr);

    std::cout << "Address: " << address << std::endl; // ✅ Safe
    return 0;
}


// 💡 Think of static_cast as a Teacher who converts only "safe & logical" things.
// 💡 Think of reinterpret_cast as a Hacker who forces anything, even if it's dangerous.
// 📌 2. What is uintptr_t? (Safe Address Storage)
// 👉 Used to store memory addresses safely as an integer.
// // 👉 Prevents pointer-to-integer conversion errors.
// 💡 Super Simple Mind Trick to Remember
// static_cast → "Stay Safe!" (Use for safe, logical type conversions)
// reinterpret_cast → "Risky Reinterpretation!" (Forces anything but may crash)
// uintptr_t → "Pointer Address SafeBox" (Stores pointer addresses safely)

