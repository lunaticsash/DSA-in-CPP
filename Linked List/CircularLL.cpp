#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    // constructor
    Node(int d)
    {
        this->data = d;
        this->next = NULL;
    }

    ~Node()
    {
        int value = this->data;
        if (this->next != NULL)
        {
            delete next;
            next = NULL;
        }
        cout << "Memory free for node with data " << value << endl;
    }
};

void insertAtNode(Node *&tail, int element, int d)
{

    // empty list
    if (tail == NULL)
    {
        Node *newNode = new Node(d);
        tail = newNode;
        newNode->next = newNode;
    }
    else
    {
        // Non empty list
        // Assunming that the element is present in the list.
        Node *curr = tail; // Head to hai nhi yaha

        while (curr->data != element)
        {
            curr = curr->next;
        }

        // element found -> curr is representing element vala node
        Node *temp = new Node(d);
        temp->next = curr->next;
        curr->next = temp;
    }
}

void deleteNode(Node* &tail, int value)
{
    // Empty list
    if (tail == NULL)
    {
        cout << "List is empty, please check again " << endl;
        return;
    }
    else
    {
        // NON EMPTY
        // Assuming that "value" is present in the Linked List

        Node *prev = tail;
        Node *curr = prev->next;

        while (curr->data != value)
        {
            prev = curr;
            curr = curr->next;
        }

        prev->next = curr->next;

        //1 Node LL
        if(curr == prev){
            tail = NULL;
        }

        //>=2 Node LL
        else if(tail == curr){
            tail = prev;
        }

        curr->next = NULL;
        delete curr;
    }
}

void print(Node *tail)
{
    Node *temp = tail;

    if(tail == NULL){
        cout<<"List is Empty "<<endl;
        return;
    }

    // cout<< tail->data << " ";//For single
    // while (tail->next != temp)
    // {
    //     cout << tail->data << " ";
    //     tail = tail->next;
    // }
    // cout << " ";

    do
    {
        cout << tail->data << " ";
        tail = tail->next;
    } while (tail != temp);
    cout << endl;
}

int main()
{
    Node *tail = NULL;

    // Inserting in an empty list.
    insertAtNode(tail, 5, 3);
    print(tail);

    insertAtNode(tail, 3, 5);
    print(tail);

    insertAtNode(tail, 5, 7);
    print(tail);

    insertAtNode(tail, 7, 9);
    print(tail);

    insertAtNode(tail, 3, 4);
    print(tail);

    deleteNode(tail, 3);
    print(tail);  

    deleteNode(tail, 9);
    print(tail);  

    deleteNode(tail, 5);
    print(tail);  

    return 0;
}