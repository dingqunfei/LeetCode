/**
 * @file p1143_2.cpp
 * @brief 
 * @author dingqunfei (dqflying@gmail.com)
 * @version 1.0
 * @date 2021-06-16
 * 
 * @copyright Copyright (c) 2021 DQFLYING
 * 
 * @par :
 * 
 * 
 * Date        : 2021-06-16
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
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size(), n = text2.size();
        if(m*n == 0)
        {
            return 0;
        }

        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        for(int i = 1; i < m+1; ++i)
        {
            for(int j = 1; j < n+1; ++j)
            {
                if(text1[i-1] == text2[j-1])
                {
                    dp[i][j] = 1+dp[i-1][j-1];
                }
                else
                {
                    dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
                }
            }
        }

        return dp[m][n];
    }

private:

    int dp(string &text1, int len1, string &text2, int len2, vector<vector<int>> &memo)
    {
        if(len1 == text1.size() || len2 == text2.size())
        {
            return 0;
        }
        if(memo[len1][len2] != -1)
        {
            return memo[len1][len2];
        }
        if(text1[len1] == text2[len2])
        {
            memo[len1][len2] = 1+dp(text1, len1+1, text2, len2+1, memo);
        }
        else
        {
            memo[len1][len2] = max(dp(text1, len1+1, text2, len2, memo), 
            dp(text1, len1, text2, len2+1, memo));
        }
        return memo[len1][len2];
    }
};