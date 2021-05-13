/**
 * @file p141_1.cpp
 * @brief 
 * @author dingqunfei (dqflying@gmail.com)
 * @version 1.0
 * @date 2021-04-21
 * 
 * @copyright Copyright (c) 2021 DQFLYING
 * 
 * @par :
 * 
 * 
 * Date        : 2021-04-21
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
    bool hasCycle(ListNode *head) {
        if(!head)
        {
            return false;
        }
        ListNode *fast = head;
        ListNode *slow = head;
        while(slow && fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next;
            fast = fast->next;
            if(slow == fast)
            {
                return true;
            }
        }
        return false;
    }
};