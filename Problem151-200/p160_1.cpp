/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* pA = headA;
        ListNode* pB = headB;
        bool bA = false, bB = false;
        while((pA || !bA) && (pA || !bB))
        {
            if(pA == pB)
            {
                return pA;
            }
            if(pA)
            {
                pA = pA->next;
            }
            else if(!bA)
            {
                pA = headB;
            }
            if(pB)
            {
                pB = pB->next;
            }
            else if(!pB)
            {
                pB = headA;
            }
            // if(pA == pB)
            // {
            //     return pA;
            // }
        }
        return NULL;
    }
};