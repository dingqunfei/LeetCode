/**
 * @file p92_2.cpp
 * @brief 
 * @author dingqunfei (dqflying@gmail.com)
 * @version 1.0
 * @date 2021-03-27
 * 
 * @copyright Copyright (c) 2021 DQFLYING
 * 
 * @par :
 * 
 * 
 * Date        : 2021-03-27
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
private:
    ListNode *reverseList(ListNode *head)
    {
        ListNode *prev = NULL;
        ListNode *curr = head;
        ListNode *next = NULL;
        while(curr)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

public:
    
    ListNode *reverseBetween(ListNode *head, int m, int n) 
    {
        ListNode *dummyNode = new ListNode(-1);
        dummyNode->next = head;

        ListNode *prev = dummyNode;
        for(int i = 0; i < m-1; ++i)
        {
            prev = prev->next;
        }

        ListNode *rightNode = prev;
        for(int i = 0; i < n-m+1; ++i)
        {
            rightNode = rightNode->next;
        }

        ListNode *tailHead = rightNode->next;
        ListNode *midHead = prev->next;
        prev->next = NULL;
        rightNode->next = NULL;

        reverseList(midHead);
        prev->next = rightNode;
        midHead->next = tailHead;
        return dummyNode->next;
    }
    
};