/**
 * @file p234_1.cpp
 * @brief 
 * @author dingqunfei (dqflying@gmail.com)
 * @version 1.0
 * @date 2021-04-01
 * 
 * @copyright Copyright (c) 2021 DQFLYING
 * 
 * @par :
 * 
 * 
 * Date        : 2021-04-01
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
    ListNode *orderHead = NULL;
    bool isPalindrome(ListNode* head) 
    {
        orderHead = head;
        return traverse(head);
    }
    bool traverse(ListNode *head)
    {
        if(!head)
        {
            return true;
        }
        bool res = traverse(head->next);
        res = res && (head->val == orderHead->val);
        orderHead = orderHead->next;
        return res;
    }
};