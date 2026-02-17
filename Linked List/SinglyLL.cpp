#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next; // Next node ko show kr raha hoga

    // constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

    // Destructing
    ~Node()
    {
        int value = this->data;
        // Memory free
        if (this->next != NULL)
        {
            delete next;
            next = NULL;
        }

        cout << "Memory is free for node with data " << value << endl;
    }
};

void InsertAtHead(Node *&head, int d) // Why reference?? Cz i dnt want to make a copy
{

    // New node create
    Node *temp = new Node(d);
    temp->next = head;
    head = temp;
}

void InsertAtTail(Node *&tail, int d)
{
    // New node create
    Node *temp = new Node(d);
    tail->next = temp;
    tail = temp;
}

void InsertAtPosition(Node *&tail, Node *&head, int position, int d)
{
    if (position == 1)
    { // for 1st pe dalne ke liye
        InsertAtHead(head, d);
        return;
    }

    Node *temp = head;
    int cnt = 1; // pehli node pr hum starting mai to hai hi

    while (cnt < position - 1)
    {
        temp = temp->next;
        cnt++;
    }

    // Inserting at Last Position
    if (temp->next == NULL)
    {
        InsertAtTail(tail, d);
        return;
    }

    // creating a node for d
    Node *nodetoInsert = new Node(d);

    nodetoInsert->next = temp->next;
    temp->next = nodetoInsert;
}

void deleteNode(int position, Node *&head, Node *&tail)
{

    if (position == 1)
    {
        Node *temp = head;
        head = head->next;

        // If only one node, update tail
        if (temp == tail)
        {
            tail = head;
        }

        // memory free start node
        temp->next = NULL;
        delete temp;
    }
    else
    {
        // deleting any middle node or last node
        Node *curr = head;
        Node *prev = NULL;

        int cnt = 1;
        while (cnt < position)
        {
            prev = curr;
            curr = curr->next;
            cnt++;
        }

        prev->next = curr->next;
        // If deleting last node, update tail
        if (curr == tail)
        {
            tail = prev;
        }
        curr->next = NULL;
        delete curr;
    }
}

int getLength(Node* head)
{
    int len = 0;
    Node* temp = head;
    while (temp != NULL)
    {
        len++;
        temp = temp->next;
    }
    return len;
}

void print(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{

    // Created a new Node
    Node *node1 = new Node(10); // Creating in Heap memory
    // cout << node1->data << endl;
    // cout << node1->next << endl;

    Node *tail = node1; // Cz single node hogi to head and tail same hi hogi

    // head pointed to node1
    Node *head = node1;
    print(head); // 10

    InsertAtHead(head, 12); // Now my state should be like this type in which first i have 12 and then 10

    print(head); // 12 10

    InsertAtHead(head, 15);
    print(head); // 15 12 10

    InsertAtTail(tail, 8);
    print(head); // 15 12 10 8

    InsertAtPosition(tail, head, 3, 22);
    print(head); // 15 12 22 10 8;

    InsertAtPosition(tail, head, 1, 21); // starting vala cse
    print(head);                         // 21 15 12 22 10 8

    deleteNode(1, head, tail);
    print(head);

    return 0;
}