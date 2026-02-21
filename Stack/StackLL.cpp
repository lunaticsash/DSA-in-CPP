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

class Stack
{
public:
    Node *top;
    int count = 0;

    Stack(){
        top = nullptr;
    }

    void push(int x)
    {
        Node *temp = new Node(x);
        temp->next = top;
        top = temp;
        count++;
    }

    void pop()
    {
        if (top == nullptr)
        {
            cout << "Stack is empty, cannot pop." << endl;
            return;
        }
        Node *temp = top;
        top = top->next;
        delete temp;
        count--;
    }

    int peek()
    {
        if (top == nullptr)
        {
            cout << "Stack is empty, no top element." << endl;
            return -1; // or throw exception
        }
        return top->data;
    }

    int size()
    {
        return count;
    }

    // Display Stack
    void display()
    {
        if (top == nullptr)
        {
            cout << "Stack is empty" << endl;
            return;
        }
        Node *temp = top;
        cout << "Stack: ";
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{

    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);

    s.display(); // Stack: 10 20 30
    cout << "count: " << s.size() << endl;

    cout << "Front element (top): " << s.peek() << endl;

    s.pop();
    s.display(); // Stack: 20 30
    cout << "count: " << s.size() << endl;

    s.pop();
    s.pop();
    s.pop(); // extra pop

    cout << "Final count: " << s.size() << endl;

    // Edge cases
    s.pop();                                     // pop on empty
    cout << "Top on empty: " << s.peek() << endl; // top on empty

    Stack emptyStack;
    emptyStack.display(); // display on empty

    return 0;
}