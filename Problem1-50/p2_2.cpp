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
1、与p2_1.cpp解法基本相同，判断方面进行简化
*/

/*
Result:
Runtime: 40 ms, faster than 15.41% of C++ online submissions for Add Two Numbers.
Memory Usage: 70.1 MB, less than 5.14% of C++ online submissions for Add Two Numbers.
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
        ListNode *start = new ListNode(0);
        ListNode *tail = start;
        
        int curr = 0, more = 0;
        while(more || l1 || l2)
        {
            if(l1) {more += l1->val; l1 = l1->next;}
            if(l2) {more += l2->val; l2 = l2->next;}
            curr = more%10;
            more = more/10;
            tail->next = new ListNode(curr);
            tail = tail->next;
        }
        
        return start->next;
    }
};