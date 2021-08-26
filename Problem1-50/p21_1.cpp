/**
 * @file p21_1.cpp
 * @brief 
 * @author dingqunfei (dqflying@gmail.com)
 * @version 1.0
 * @date 2021-08-27
 * 
 * @copyright Copyright (c) 2021 DQFLYING
 * 
 * @par :
 * 
 * 
 * Date        : 2021-08-27
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *dummy = new ListNode(0);
        ListNode *head = dummy;
        while(l1 && l2)
        {
            if(l1->val > l2->val)
            {
                head->next = l2;
                l2 = l2->next;
                head = head->next;
            }
            else
            {
                head->next = l1;
                l1 = l1->next;
                head = head->next;
            }
        }
        if(l1)
        {
            head->next = l1;
        }
        else if(l2)
        {
            head->next = l2;
        }
        return dummy->next;
    }
};