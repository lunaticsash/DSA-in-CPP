#include <iostream>
#include <queue>   // queue library
using namespace std;

int main() {
    queue<int> q;  // queue of integers

    // Enqueue elements
    q.push(10);
    q.push(20);
    q.push(30);

    // Front element
    cout << "Front element: " << q.front() << endl;  // 10
    cout << "Rear element: " << q.back() << endl;    // 30

    // Dequeue element
    q.pop();  // removes 10

    cout << "Front after pop: " << q.front() << endl;  // 20

    // Size of queue
    cout << "Queue size: " << q.size() << endl;

    // Check if empty
    if (q.empty())
        cout << "Queue is empty" << endl;
    else
        cout << "Queue is not empty" << endl;

    return 0;
}
