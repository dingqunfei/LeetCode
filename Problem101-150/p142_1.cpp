/**
 * @file p142_1.cpp
 * @brief 
 * @author dingqunfei (dqflying@gmail.com)
 * @version 1.0
 * @date 2021-04-22
 * 
 * @copyright Copyright (c) 2021 DQFLYING
 * 
 * @par :
 * 
 * 
 * Date        : 2021-04-22
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
    ListNode *detectCycle(ListNode *head) {
        
        ListNode *fast = head;
        ListNode *slow = head;
        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next;
            fast = fast->next;
            if(slow == fast)
            {
                ListNode *prev = head;
                while(prev != slow)
                {
                    prev = prev->next;
                    slow = slow->next;
                }
                return prev;
            }
        }
        return nullptr;
    }
};

