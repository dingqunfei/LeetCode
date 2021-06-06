/**
 * @file p516_1.cpp
 * @brief 
 * @author dingqunfei (dqflying@gmail.com)
 * @version 1.0
 * @date 2021-06-05
 * 
 * @copyright Copyright (c) 2021 DQFLYING
 * 
 * @par :
 * 
 * 
 * Date        : 2021-06-05
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
    int longestPalindromeSubseq(string s) {
        int size = s.size();
        vector<vector<int>> dp(size, vector<int>(size, 0));
        for(int n = 0; n < size; ++n)
        {
            dp[n][n] = 1;
        }
        for(int i = size - 1; i >= 0; --i)
        {
            for(int j = i+1; j < size; ++j)
            {
                if(s[i] == s[j])
                {
                    dp[i][j] = dp[i+1][j-1]+2;
                }
                else
                {
                    dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
                }
            }
        }
        return dp[0][size-1];
    }
};