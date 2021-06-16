/**
 * @file p583_1.cpp
 * @brief 
 * @author dingqunfei (dqflying@gmail.com)
 * @version 1.0
 * @date 2021-06-17
 * 
 * @copyright Copyright (c) 2021 DQFLYING
 * 
 * @par :
 * 
 * 
 * Date        : 2021-06-17
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
    int longestCommonSubsequence(string &text1, string &text2) {
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

    int minDistance(string word1, string word2) {
        int comm = longestCommonSubsequence(word1, word2);
        return word1.size()+word2.size()-2*comm;
    }
};