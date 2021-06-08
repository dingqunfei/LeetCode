/**
 * @file p72_1.cpp
 * @brief 
 * @author dingqunfei (dqflying@gmail.com)
 * @version 1.0
 * @date 2021-06-09
 * 
 * @copyright Copyright (c) 2021 DQFLYING
 * 
 * @par :
 * 
 * 
 * Date        : 2021-06-09
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
    int minDistance(string word1, string word2) {
        int len1 = word1.size(), len2 = word2.size();
        vector<vector<int>> dp(len1+1, vector<int>(len2+1, 0));
        
        for(int i = 1; i < len1+1; ++i)
        {
            dp[i][0] = i;
        }
        for(int i = 1; i < len2+1; ++i)
        {
            dp[0][i] = i;
        }

        for(int i = 1; i < len1+1; ++i)
        {
            for(int j = 1; j < len2+1; ++j)
            {
                if(word1[i-1] == word2[j-1])
                {
                    dp[i][j] = dp[i-1][j-1];
                }
                else
                {
                    int min_value = min(dp[i][j-1], dp[i-1][j])+1;
                    min_value = min(dp[i-1][j-1]+1, min_value);
                    dp[i][j] = min_value;
                }
            }
        }
        return dp[len1][len2];
    }
};