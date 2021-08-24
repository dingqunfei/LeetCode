/**
 * @file p18_2.cpp
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
        
        ListNode *dummyhead = new ListNode(INT_MAX);
        dummyhead->next = head;

        ListNode *temp = dummyhead;
        ListNode *p = dummyhead;
        while(p)
        {
            if(p->val == val)
            {
                break;
            }
            temp = p;
            p = p->next;
        }
        
        temp->next = p->next;
        
        return dummyhead->next;
    }
};