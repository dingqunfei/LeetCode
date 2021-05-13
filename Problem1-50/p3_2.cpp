/**
 * @file p3_2.cpp
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
使用left/right遍历字符串，并使用unordered_map记录遍历过的字符和对应（索引+1）
当right端新添加的字符在map中被发现时，说明发生重复，对left的索引更新
同p3_1.cpp，利用vecotr<int> charIndexMap(256, -1)代替 unordered_map实现
*/

/*
Result:
Runtime: 12 ms, faster than 83.72% of C++ online submissions for Longest Substring Without Repeating Characters.
Memory Usage: 8.2 MB, less than 100.00% of C++ online submissions for Longest Substring Without Repeating Characters.
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        if(s == ""){return 0;}
        
        int maxLen = 0;
        int right = 0, left = 0;
        int sLen = s.size();
        //unordered_map<char, int> charIndexMap;
        vector<int> charIndexMap(256, -1);
        int prev = 0, curr = 0;
        while((right < sLen) && (left < sLen))
        {
            int index = charIndexMap[s[right]];
            if(index > left)
            {
                left = index;                
            }
            
            charIndexMap[s[right]] = right+1;
            ++right;
            int currLen = right - left;
            if(currLen > maxLen) {maxLen = currLen;}
        }
        return maxLen;
    }
};