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
    ListNode* reverse(ListNode* head, ListNode* tail)
    {
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = NULL;
        while(curr != tail)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) 
    {
        ListNode* a = head;
        ListNode* b = head;
        for(int i = 0; i < k; ++i)
        {
            if(b == NULL)
            {
                return head;
            }
            b = b->next;
        }
        ListNode* newHead = reverse(a, b);
        a->next = reverseKGroup(b, k);
        return newHead;
    }
};