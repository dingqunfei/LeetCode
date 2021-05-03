/**
 * @file p3_4.cpp
 * @brief 
 * @author dingqunfei (dqflying@gmail.com)
 * @version 1.0
 * @date 2021-05-02
 * 
 * @copyright Copyright (c) 2021 DQFLYING
 * 
 * @par :
 * 
 * 
 * Date        : 2021-05-02
 * Version     : 1.0
 * Author      : dqflying
 * Lisence     : 
 * Description : 
 * 
 * 
 * 
 * 
 */

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // value , index
        unordered_map<char, int> window;
        int size = s.size();
        int maxLen = 0;
        int lhs = 0, rhs = 0;
        while(rhs < s.size())
        {
            char a = s[rhs];
            ++rhs;
            ++window[a];
            while(window[a] > 1)
            {
                char b = s[lhs];
                --window[b];
                ++lhs;
            }
            
            maxLen = max(maxLen, rhs - lhs);
        }

        return maxLen;
    }
};