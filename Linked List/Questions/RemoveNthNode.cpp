// Given the head of a singly linked list and an integer n. Remove the nth node from the back of the linked List and return the head of the modified list. The value of n will always be less than or equal to the number of nodes in the linked list.

#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    // Constructor
    Node(int data1, Node *next1)
    {
        data = data1;
        next = next1;
    }

    // Constructor
    Node(int data1)
    {
        data = data1;
        next = nullptr;
    }
};

//2nd Optimal approach with time complexity O(N) and SC is O(1)

// Function to delete the Nth node
// from the end of the linked list
Node *DeleteNthNodefromEnd2(Node *head, int N)
{
    // Create two pointers, fastp and slowp
    Node *fastp = head;
    Node *slowp = head;

    // Move the fastp pointer N nodes ahead
    for (int i = 0; i < N; i++)
        fastp = fastp->next;

    // If fastp becomes NULL,
    // the Nth node from the end is the head
    if (fastp == NULL)
        return head->next;

    // Move both pointers until fastp reaches the end
    while (fastp->next != NULL)
    {
        fastp = fastp->next;
        slowp = slowp->next;
    }

    // Delete the Nth node from the end
    Node *delNode = slowp->next;
    slowp->next = slowp->next->next;
    delete delNode;
    return head;
}

// 1st Brute force approach with slightly higher time complexity as O(2N) in worst case and SC is O(1)

// Function to delete the Nth node
// from the end of the linked list
Node *DeleteNthNodefromEnd1(Node *head, int N)
{
    if (head == NULL)
    {
        return NULL;
    }
    int cnt = 0;
    Node *temp = head;

    // Count the number of nodes in the linked list
    while (temp != NULL)
    {
        cnt++;
        temp = temp->next;
    }

    // If N equals the total number of
    // nodes, delete the head
    if (cnt == N)
    {
        Node *newhead = head->next;
        delete (head);
        return newhead;
    }

    // Calculate the position of the node to delete (res)
    int res = cnt - N;
    temp = head;

    // Traverse to the node just before the one to delete
    while (temp != NULL)
    {
        res--;
        if (res == 0)
        {
            break;
        }
        temp = temp->next;
    }

    // Delete the Nth node from the end
    Node *delNode = temp->next;
    temp->next = temp->next->next;
    delete (delNode);
    return head;
}
// Function to print the linked list
void printLL(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    int N = 3;
    Node *head = new Node(arr[0]);
    head->next = new Node(arr[1]);
    head->next->next = new Node(arr[2]);
    head->next->next->next = new Node(arr[3]);
    head->next->next->next->next = new Node(arr[4]);

    // Delete the Nth node from the end
    // and print the modified linked list
    head = DeleteNthNodefromEnd2(head, N);
    printLL(head);
}