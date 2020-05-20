/**
 * @file p3_3.cpp
 * @brief 
 * @author dqflying (dqflying@gmail.com)
 * @version 1.0
 * @date 2020-05-17
 * 
 * @copyright Copyright (c) 2020  DQFLYING.INC
 * 
 * @par 新增文件:
 * <table>
 * <tr><th>Date            <th>Version      <th>Author       <th>Description
 * <tr><td>2020-05-17      <td>1.0          <td>dqflying     <td>内容
 * </table>
 */

/*
Description:
3. Longest Substring Without Repeating Characters

Given a string, find the length of the longest substring without repeating characters.

Example 1:
Input: "abcabcbb"
Output: 3 
Explanation: The answer is "abc", with the length of 3. 

Example 2:
Input: "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.

Example 3:
Input: "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3. 
Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/

/*
Solution:
最长无重复字符子串
与前面思想类似，使用int windowChars[128] = {0};记录每个字符在字符串中的（索引+1），
使用start,end对字符串扫描，当end扫描到的字符在windowChars中出现时（if (windowChars[c] > 0)），
说明与end重复，找到前一个重复的end字符，并将start到重复end字符间的字符索引清0
*/

/*
Result:
Runtime: 8 ms, faster than 95.04% of C++ online submissions for Longest Substring Without Repeating Characters.
Memory Usage: 7.1 MB, less than 100.00% of C++ online submissions for Longest Substring Without Repeating Characters.
*/


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        size_t sz = s.length();
        int start = 0, end = 0, ans = 0, counter = 0;
        int windowChars[128] = {0};
        while(end < sz) {
            int c = (int)(s[end]);
            if (windowChars[c] > 0) {
                while(start <= windowChars[c] - 1) {
                    windowChars[(int)(s[start])] = 0;
                    start++;
                }                
                windowChars[c] = (end++) + 1;
                continue;
            }
            windowChars[c] = end + 1;
            ans = max(ans, end - start + 1);
            end++;
        }
        return ans;
    }
};