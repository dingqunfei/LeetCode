/**
 * @file p141_havingfun.cpp
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


//给链表节点赋一个特殊的值，检测，如果检测到特殊的值，说明链表是环形的
class Solution {
public:
    bool hasCycle(ListNode *head) {
        
        while (head){
            if(head->val == -100005)
                return true;
            else
                head->val = -100005;
            head = head->next;
        }
        return false;
    }
};