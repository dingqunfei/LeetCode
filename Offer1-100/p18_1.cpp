/**
 * @file p18_1.cpp
 * @brief 
 * @author dingqunfei (dqflying@gmail.com)
 * @version 1.0
 * @date 2021-08-25
 * 
 * @copyright Copyright (c) 2021 DQFLYING
 * 
 * @par :
 * 
 * 
 * Date        : 2021-08-25
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
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteNode(ListNode* head, int val) {
        ListNode *p = head;
        ListNode *temp = head;
        while(p)
        {
            if(p->val == val)
            {
                break;
            }
            temp = p;
            p = p->next;
        }
        if(p == temp)
        {
            head = p->next;
        }
        else
        {
            temp->next = p->next;
        }
        
        return head;
    }
};