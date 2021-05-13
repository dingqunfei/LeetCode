/**
 * @file p25_1.cpp
 * @brief 
 * @author dingqunfei (dqflying@gmail.com)
 * @version 1.0
 * @date 2021-03-28
 * 
 * @copyright Copyright (c) 2021 DQFLYING
 * 
 * @par :
 * 
 * 
 * Date        : 2021-03-28
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *tmphead = head;
        int count = k;
        while(tmphead && count > 0)
        {
            tmphead = tmphead->next;
            --count;
        }
        if(count > 0)
        {
            return head;
        }
        ListNode *prev = NULL;
        ListNode *curr = head;
        ListNode *next = NULL;
        count = k;
        while(curr && count > 0)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            --count;
        }
        ListNode *last = reverseKGroup(curr, k);
        head->next = last;

        return prev;
    }
};