/**
 * @file p19_1.cpp
 * @brief 
 * @author dingqunfei (dqflying@gmail.com)
 * @version 1.0
 * @date 2021-08-26
 * 
 * @copyright Copyright (c) 2021 DQFLYING
 * 
 * @par :
 * 
 * 
 * Date        : 2021-08-26
 * Version     : 1.0
 * Author      : dqflying
 * Lisence     : 
 * Description : 
 * 
 * 
 * 
 * 
 */


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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        vector<ListNode*> headVec;
        ListNode *p = head;
        while(p)
        {
            headVec.push_back(p);
            p = p->next;
        }
        int size = headVec.size();
        int left = size-n-1, right = size-n+1;
        if(left < 0)
        {
            head = head->next;
            return head;
        }
        if(right >= size)
        {
            headVec[size-2]->next = NULL;
            return head;
        }
        headVec[left]->next = headVec[right];
        return head;
    }
};