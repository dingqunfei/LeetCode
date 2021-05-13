/**
 * @file p5_1.cpp
 * @brief 
 * @author dqflying (dqflying@gmail.com)
 * @version 1.0
 * @date 2020-05-24
 * 
 * @copyright Copyright (c) 2020  DQFLYING.INC
 * 
 * @par 新增文件:
 * 
 * 
 * Date              Version        Author         LISENCE
 * 2020-05-24        1.0            dqflying       XXXXXXX
 * Description:
 * 
 * 
 */

/*
Description:
5. Longest Palindromic Substring

Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

Example 1:
Input: "babad"
Output: "bab"
Note: "aba" is also a valid answer.

Example 2:
Input: "cbbd"
Output: "bb"
*/

/*
Solution:
回文字符串，从中间向两边扩展，两侧字符相同，有两种情况
一、中心字符是单独的，左右对侧，如"cbabc"
二、中心字符是对称的两个，如"cbaabc"
因此，查找时以每个字符为中心，向左右两边扩展查找相等的字符，当遇到情况二时，我们只需要一直向左（或者右）
遍历相同的字符，然后再如情况一，左右两边扩展。
当然，有些特殊情况需要处理，如"bbb"这种，如""
*/

/*
Result:
Runtime: 40 ms, faster than 84.90% of C++ online submissions for Longest Palindromic Substring.
Memory Usage: 6.6 MB, less than 100.00% of C++ online submissions for Longest Palindromic Substring.
*/

class Solution {
public:
    string longestPalindrome(string s) {
        
        int len = s.size();
        if(len < 2)
        {
            return s;
        }
        if(len == 2 && s[0] == s[1])
        {
            return s;
        }
        
        int leftIndex = 0, rightIndex = 0, currLen = 0, maxLen = 0;
        for(int i = 1; i < len; ++i)
        {
            char center = s[i];
            int left = i, right = i;
            while((left-1 >= 0) && (s[left-1] == s[i]))
            {
                --left;
            }
            while((left > 0) && (right < len-1))
            {
                if(s[left-1] == s[right+1])
                {
                    --left;
                    ++right;
                }
                else
                {
                    break;
                }
            }
            currLen = right - left + 1;
            if(currLen > maxLen)
            {
                maxLen = currLen;
                leftIndex = left;
                rightIndex = right;
            }
        }
        
        //return s.substr(leftIndex, rightIndex);
        string res(s.begin()+leftIndex, s.begin()+rightIndex+1);
        return res;
    }
};