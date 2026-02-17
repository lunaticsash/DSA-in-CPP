#include <iostream>
using namespace std;

class Node
{

public:
    int data;
    Node *prev;
    Node *next;

    // Constructor
    Node(int d)
    {
        this->data = d;
        this->prev = NULL;
        this->next = NULL;
    }

    ~Node()
    {
        int value = this->data;
        if (next != NULL)
        {
            delete next;
            next = NULL;
        }
        cout << "Memory free for node with data " << value << endl;
    }
};

void insertAtHead(Node *&head, Node *&tail, int d)
{
    // empty list
    if (head == NULL)
    {
        Node *temp = new Node(d);
        head = temp;
        tail = temp;
    }
    else
    {
        Node *temp = new Node(d);
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}

void insertAtTail(Node *&head, Node *&tail, int d)
{
    // empty list
    if (tail == NULL)
    {
        Node *temp = new Node(d);
        head = temp;
        tail = temp;
    }

    else
    {
        Node *temp = new Node(d);
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
}

void insertAtPosition(Node *&head, Node *&tail, int position, int d)
{

    if (position == 1)
    { // for 1st pe dalne ke liye
        insertAtHead(head, tail, d);
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
        insertAtTail(head, tail, d);
        return;
    }

    // creating a node for d
    Node *nodetoInsert = new Node(d);

    nodetoInsert->next = temp->next;
    temp->next->prev = nodetoInsert;
    temp->next = nodetoInsert;
    nodetoInsert->prev = temp;
}

void deleteNode(int position, Node *&head, Node *&tail)
{

    // deleting first or last node
    if (position == 1)
    {
        Node *temp = head;
        temp->next->prev = NULL;
        head = temp->next;
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

        curr->prev = NULL;
        prev->next = curr->next;
        curr->next = NULL;

        delete curr;
    }
}

// Traversing a linked list
void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// gives lenth of a Linked list |
int getLength(Node *head)
{
    int len = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        len++;
        temp = temp->next;
    }
    return len;
}

int main()
{

    // Node *node1 = new Node(10);

    Node *head = NULL;
    Node *tail = NULL;

    print(head);

    cout << getLength(head);

    insertAtHead(head, tail, 11);
    print(head);

    insertAtHead(head, tail, 20);
    print(head);

    insertAtTail(head, tail, 13);
    print(head);

    insertAtPosition(head, tail, 2, 100);
    print(head); // 20 100 11 10 13

    insertAtPosition(head, tail, 1, 101);
    print(head);
    
    deleteNode(5, head, tail);
    print(head);
    // cout<<"Head "<< head->data <<endl;
    // cout<<"Tail "<< tail->data <<endl;
 
    return 0;
}