// Segregate odd and even nodes in LL

// Given the head of a singly linked list. Group all the nodes with odd indices followed by all the nodes with even indices and return the reordered list.

// Consider the 1st node to have index 1 and so on. The relative order of the elements inside the odd and even group must remain the same as the given input.

/*
Definition of singly linked list:
struct ListNode
{
    int val;
    ListNode *next;
    ListNode()
    {
        val = 0;
        next = NULL;
    }
    ListNode(int data1)
    {
        val = data1;
        next = NULL;
    }
    ListNode(int data1, ListNode *next1)
    {
        val = data1;
        next = next1;
    }
};
*/

class Solution
{
public:
    ListNode *oddEvenList(ListNode *head)
    {

        if (head == NULL || head->next == NULL)
        {
            return head;
        }

        ListNode *odd = head;
        ListNode *even = head->next;
        ListNode *evenHead = head->next;

        while (even != NULL && even->next != NULL)
        {
            odd->next = odd->next->next;
            even->next = even->next->next;

            odd = odd->next;
            even = even->next;
        }

        odd->next = evenHead;
        return head;
    }
};
