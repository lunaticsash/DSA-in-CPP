#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
// TC = O(NLOGK) where N is the total number of nodes in all lists and K is the number of lists.
// SC = O(K) where K is the number of lists.
class Solution
{
public:
    struct cmp
    {
        bool operator()(ListNode *a, ListNode *b)
        {
            return a->val > b->val;
        }
    };

    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        priority_queue<ListNode *, vector<ListNode *>, cmp> pq;

        // Push the head of every non-empty list
        for (ListNode *head : lists)
        {
            if (head)
                pq.push(head);
        }

        ListNode dummy(0);
        ListNode *tail = &dummy;

        while (!pq.empty())
        {
            ListNode *node = pq.top();
            pq.pop();

            tail->next = node;
            tail = tail->next;

            if (node->next)
                pq.push(node->next);
        }

        return dummy.next;
    }
};

// TC = O(NLOGK) where N is the total number of nodes in all lists and K is the number of lists.
// SC = O(K) + O(N)( for new ll )
class Solution
{
public:
    struct cmp
    {
        bool operator()(ListNode *a, ListNode *b) { return a->val > b->val; }
    };
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        priority_queue<ListNode *, vector<ListNode *>, cmp> pq;

        for (ListNode *head : lists)
        {
            if (head != nullptr)
                pq.push(head);
        }

        ListNode *ans = nullptr;
        ListNode *tail = nullptr;

        while (!pq.empty())
        {
            ListNode *ok = pq.top();
            pq.pop();

            ListNode *newNode = new ListNode(ok->val);

            if (ans == nullptr)
            {
                ans = newNode;
                tail = newNode;
            }
            else
            {
                tail->next = newNode;
                tail = tail->next;
            }

            if (ok->next)
            {
                pq.push(ok->next);
            }
        }

        return ans;
    }
};