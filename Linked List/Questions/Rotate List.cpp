#include<bits/stdc++.h>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int getLength(ListNode* head) {
        int count = 0;
        if (head == NULL)
            return 0;
        while (head != NULL) {
            head = head->next;
            count++;
        }
        return count;
    }

    ListNode* rotate(ListNode* head, int n, int k) {
        ListNode* temp = head;
        ListNode* last = head;

        for (int i = 0; i < n - k - 1; i++) {
            temp = temp->next;
        }
        for (int i = 0; i < n - 1; i++) {
            last = last->next;
        }

        last->next = head;
        head = temp->next;
        temp->next = NULL;

        return head;
    }

    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL || head->next == NULL)
            return head;
        int n = getLength(head);
        k = k % n;

        if (k == 0)
            return head;

        return rotate(head, n, k);
    }
};