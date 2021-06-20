/**
 * @file p5_3.cpp
 * @brief 
 * @author dingqunfei (dqflying@gmail.com)
 * @version 1.0
 * @date 2021-06-20
 * 
 * @copyright Copyright (c) 2021 DQFLYING
 * 
 * @par :
 * 
 * 
 * Date        : 2021-06-20
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
    string longestPalindrome(string s) {
        int size = s.size();
        if(size < 2)
        {
            return s;
        }
        vector<vector<bool>> dp(size, vector<bool>(size, false));
        for(int i = 0; i < size; ++i)
        {
            dp[i][i] = true;
        }
        int maxLen = 1;
        int start = 0;
        for(int i = size-1; i >= 0; --i)
        {
            for(int j = i+1; j < size; ++j)
            {
                if((s[i] == s[j]) && (i+1 == j || dp[i+1][j-1]))
                {
                    dp[i][j] = true;
                    if(j-i+1 > maxLen)
                    {
                        maxLen = j-i+1;
                        start = i;
                    }
                }
            }
        }

        return s.substr(start, maxLen);
    }
};