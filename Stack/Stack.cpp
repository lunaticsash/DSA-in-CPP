#include <iostream>
#include <stack>   // stack library
using namespace std;

int main() {
    stack<int> s;  // stack of integers

    // Push elements
    s.push(10);
    s.push(20);
    s.push(30);

    // Top element
    cout << "Top element: " << s.top() << endl;  // 30

    // Pop element
    s.pop();  // removes 30

    cout << "Top after pop: " << s.top() << endl;  // 20

    // Size of stack
    cout << "Stack size: " << s.size() << endl;

    // Check if empty
    if (s.empty())
        cout << "Stack is empty" << endl;
    else
        cout << "Stack is not empty" << endl;

    return 0;
}
















// #include <iostream>
// using namespace std;

// #define SIZE 5  // maximum size of stack

// class Stack {
//     int arr[SIZE];
//     int top;

// public:
//     Stack() { top = -1; }

//     void push(int x) {
//         if (top == SIZE - 1) {
//             cout << "Stack Overflow\n";
//             return;
//         }
//         arr[++top] = x;
//         cout << x << " pushed into stack\n";
//     }

//     void pop() {
//         if (top == -1) {
//             cout << "Stack Underflow\n";
//             return;
//         }
//         cout << arr[top--] << " popped from stack\n";
//     }

//     void peek() {
//         if (top == -1) {
//             cout << "Stack is empty\n";
//             return;
//         }
//         cout << "Top element is: " << arr[top] << "\n";
//     }

//     bool isEmpty() {
//         return (top == -1);
//     }
// };

// int main() {
//     Stack s;
//     s.push(10);
//     s.push(20);
//     s.push(30);
//     s.peek();
//     s.pop();
//     s.peek();
//     return 0;
// }
