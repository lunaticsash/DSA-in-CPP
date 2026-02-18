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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* dummyHead = new ListNode(-1); 
    ListNode* curr = dummyHead;
    ListNode* temp1 = l1;
    ListNode* temp2 = l2;
    int carry = 0;
    while(temp1!=NULL || temp2 != NULL){
        int sum = carry;
        if(temp1) sum+=temp1->val;
        if(temp2) sum+=temp2->val;
        ListNode* newNode = new ListNode(sum % 10);
        carry = sum/10;

        curr->next = newNode;
        curr = curr->next;

        if(temp1) temp1=temp1->next; 
        if(temp2) temp2=temp2->next; 
        
    }

    if(carry){
        ListNode* newNode = new ListNode(carry);
        curr->next = newNode;
    }
    return dummyHead->next;
    }
};



//0ms
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
// class Solution {
// public:
//     ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
//         if(l1 == NULL && l2 == NULL) return NULL;

//         ListNode* l3= new ListNode(0);
//         ListNode* temp= l3;
//         int sum=0, carry=0;

//         while(l1 != NULL || l2 != NULL || carry != 0)
//         {
//             sum= carry;

//             if(l1)
//             {
//                 sum += l1->val;
//                 l1= l1->next;
//             }

//             if(l2)
//             {
//                 sum += l2->val;
//                 l2= l2->next;
//             }

//             temp->next= new ListNode(sum%10);
//             carry= sum / 10;
//             temp= temp->next;
//         }
//         return l3->next;
//     }
// };