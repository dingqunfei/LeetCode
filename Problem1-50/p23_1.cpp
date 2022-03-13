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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *dummy = new ListNode(0);
        ListNode *head = dummy;
        while(l1 && l2)
        {
            if(l1->val < l2->val)
            {
                head->next = l1;
                l1 = l1->next;
            }
            else
            {
                head->next = l2;
                l2 = l2->next;
            }
            head = head->next;
        }
        
        head->next = l1?l1:l2;
        head = dummy->next;
        delete dummy;
        return head;
    }
    ListNode* merge(vector<ListNode*>& lists, int left, int right)
    {
        if(left == right)
        {
            return lists[left];
        }
        if(left > right)
        {
            return NULL;
        }
        int mid = (left+right)/2;
        return mergeTwoLists(merge(lists, left, mid), merge(lists, mid+1, right));
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return merge(lists, 0, lists.size()-1);
    }
};