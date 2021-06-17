/**
 * @file p712_1.cpp
 * @brief 
 * @author dingqunfei (dqflying@gmail.com)
 * @version 1.0
 * @date 2021-06-18
 * 
 * @copyright Copyright (c) 2021 DQFLYING
 * 
 * @par :
 * 
 * 
 * Date        : 2021-06-18
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
    int minimumDeleteSum(string s1, string s2) {
        int deleteSum = 0;
        int len1 = s1.size(), len2 = s2.size();

        vector<vector<int>> dp(len1+1, vector<int>(len2+1, 0));

        for(int i = 1; i < len1+1; ++i)
        {
            deleteSum += (int)s1[i-1];
            dp[i][0] = deleteSum;
        }
        deleteSum = 0;
        for(int i = 1; i < len2+1; ++i)
        {
            deleteSum += (int)s2[i-1];
            dp[0][i] = deleteSum;
        }

        for(int i = 1; i < len1+1; ++i)
        {
            for(int j = 1; j < len2+1; ++j)
            {
                if(s1[i-1] == s2[j-1])
                {
                    dp[i][j] = dp[i-1][j-1];
                }
                else
                {
                    //注意这里
                    dp[i][j] = min(dp[i][j-1]+s2[j-1], dp[i-1][j]+s1[i-1]);
                }
            }
        }
        return dp[len1][len2];
    }
};