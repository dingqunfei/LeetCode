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
    vector<int> nVec;
    void reverse(ListNode* head)
    {
        if(head == NULL)
        {
            return;
        }
        reverse(head->next);
        nVec.push_back(head->val);
    }
    vector<int> reversePrint(ListNode* head) {
        reverse(head);
        return nVec;
    }
};