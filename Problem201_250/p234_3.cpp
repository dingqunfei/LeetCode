/**
 * @file p234_3.cpp
 * @brief 
 * @author dingqunfei (dqflying@gmail.com)
 * @version 1.0
 * @date 2021-04-02
 * 
 * @copyright Copyright (c) 2021 DQFLYING
 * 
 * @par :
 * 
 * 
 * Date        : 2021-04-02
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
        ListNode *prev = nullptr;
        ListNode *curr = head;
        ListNode *next = head;
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
    bool isPalindrome(ListNode* head) 
    {
        if(!head)
        {
            return true;
        }
        ListNode *fastPointer = head;
        ListNode *slowPointer = head;
        while(fastPointer->next && fastPointer->next->next)
        {
            slowPointer = slowPointer->next;
            fastPointer = fastPointer->next->next;
        }
        ListNode *reverseHead = slowPointer;
        if(fastPointer->next)
        {
            reverseHead = reverseHead->next;
        }
        reverseHead = reverseList(reverseHead);
        ListNode *tmp = reverseHead;
        while(tmp)
        {
            if(tmp->val != head->val)
            {
                //在此恢复链表顺序
                return false;
            }
            tmp = tmp->next;
            head = head->next;
        }
        //在此恢复链表顺序
        return true;

    }
};