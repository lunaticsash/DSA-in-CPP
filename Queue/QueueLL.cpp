#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = nullptr;
    }
};

class Queue
{
public:
    Node *start;
    Node *end;
    int count;

public:
    Queue()
    {
        start = end = nullptr;
        count = 0;
    }

    void push(int x)
    {
        Node *temp = new Node(x);

        if (start == nullptr)
            start = end = temp;
        else
        {
            end->next = temp;
            end = temp;
            
        }
        count += 1;
    }

    void pop()
    {
        if (start == nullptr)
        {
            cout << "Queue is emtpy" << endl;
            return;
        }

        Node *temp = start;
        start = start->next;

        if (start == nullptr)
        { // Queue became empty
            end = nullptr;
        }
        delete temp;
        count -= 1;
    }

    int top()
    {
        if (start == nullptr)
        {
            cout << "Queue is emtpy" << endl;
            return -1;
        }

        return start->data;
    }

    int size(){
        return count;
    }

    // Check if empty
    bool empty() {
        return (start == nullptr);
    }

    // Display queue
    void display() {
        if (start == nullptr) {
            cout << "Queue is empty" << endl;
            return;
        }
        Node* temp = start;
        cout << "Queue: ";
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{

    Queue q;

    q.push(10);
    q.push(20);
    q.push(30);

    q.display(); // Queue: 10 20 30
    cout << "count: " << q.size() << endl;

    cout << "Front element (top): " << q.top() << endl;

    q.pop();
    q.display(); // Queue: 20 30
    cout << "count: " << q.size() << endl;

    q.pop();
    q.pop();
    q.pop(); // extra pop

    cout << "Final count: " << q.size() << endl;

    return 0;
}