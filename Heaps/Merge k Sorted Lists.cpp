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