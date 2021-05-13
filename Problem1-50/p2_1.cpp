/**
 * @file p2_1.cpp
 * @brief 
 * @author dqflying (dqflying@gmail.com)
 * @version 1.0
 * @date 2020-05-16
 * 
 * @copyright Copyright (c) 2020  DQFLYING.INC
 * 
 * @par 新增文件:
 * <table>
 * <tr><th>Date            <th>Version      <th>Author       <th>Description
 * <tr><td>2020-05-16      <td>1.0          <td>dqflying     <td>内容
 * </table>
 */

/*
Description:
2. Add Two Numbers

You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example:

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.
*/

/*
Solution:
1、遍历得到两个链表长度
2、将短链表的值加到长链表上，more记录进位
3、不要忘记两种情况，more与长链表末端相加，more超过长链表长度
*/

/*
Result:
Runtime: 52 ms, faster than 6.06% of C++ online submissions for Add Two Numbers.
Memory Usage: 69.6 MB, less than 5.14% of C++ online submissions for Add Two Numbers.
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int len1 = 1, len2 = 1, shortLen = 0;
        ListNode *temp1 = l1, *temp2 = l2, *addTempLarger = NULL, *addTempShorter = NULL;
        while(temp1->next)
        {
            ++len1;
            temp1 = temp1->next;
        }
        while(temp2->next)
        {
            ++len2;
            temp2 = temp2->next;
        }
      
        if(len1 > len2)
        {
            addTempLarger = l1;
            addTempShorter = l2;
            shortLen = len2;
        }
        else
        {
            addTempLarger = l2;
            addTempShorter = l1;
            shortLen = len1;
        }
        ListNode *res = addTempLarger;
        int more = 0;
        int sum = 0;
        for(int i = 1; i < shortLen; ++i)
        {
            sum = addTempLarger->val + addTempShorter->val;
            addTempLarger->val = (sum + more)%10;
            more = (sum + more)/10;
            addTempLarger = addTempLarger->next;
            addTempShorter = addTempShorter->next;
        }
        sum = addTempLarger->val + addTempShorter->val;
        addTempLarger->val = (sum + more)%10;
        more = (sum + more)/10;
        while(more)
        {
            if(addTempLarger->next)
            {
                addTempLarger = addTempLarger->next;
                sum = addTempLarger->val + more;
                addTempLarger->val = sum % 10;
                more = sum / 10;
            }
            else
            {
                addTempLarger->next = new ListNode(more);
                more = 0;
            }
            
        }
        return res;
    }
};