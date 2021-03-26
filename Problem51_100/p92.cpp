/**
 * @file p92.cpp
 * @brief 
 * @author dingqunfei (dqflying@gmail.com)
 * @version 1.0
 * @date 2021-03-18
 * 
 * @copyright Copyright (c) 2021 DQFLYING
 * 
 * @par :
 * 
 * 
 * Date        : 2021-03-18
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

/*
class Solution {
public:
    ListNode* reverseBetween(ListNode* head) {
        if(!head->next)
        {
            return head;
        }
        ListNode *last = reverseBetween(head->next);
        head->next->next = head;
        head->next = nullptr;
        return last;
    }
};
*/

class Solution {
public:
    ListNode *tailList = NULL;

    ListNode* reverseN(ListNode* head, int N) {
        if(N == 1)
        {
            tailList = head->next;
            return head;
        }
        ListNode *last = reverseN(head->next, N-1);
        head->next->next = head;
        head->next = tailList;
        return last;
    }

    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(m == 1)
        {
            return reverseN(head, n);
        }
        
    }

};