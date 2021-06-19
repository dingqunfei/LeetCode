/**
 * @file p5_2.cpp
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



//动态规划，用得不好，判断条件太复杂
class Solution {
public:
    string longestPalindrome(string s) {
        /*
        int size = s.size();
        vector<vector<int>> dp(size+1, vector<int>(size+1, 0));

        for(int i = 1; i < size+1; ++i)
        {
            dp[i][i] = 1;
        }

        for(int i = size; i > 0; --i)
        {
            for(int j = i+1; j < size+1; ++j)
            {

            }
        }

        return 0;
        */
        int size = s.size();

        vector<vector<int>> dp(size, vector<int>(size, 0));
        for(int n = 0; n < size; ++n)
        {
            dp[n][n] = 1;
        }
        int max = 1;
        int left = 0, right = 0;
        for(int i = size - 1; i >= 0; --i)
        {
            for(int j = i+1; j < size; ++j)
            {
                if((s[i] == s[j]) && ((i+1 == j) || (dp[i+1][j-1] != 0)))
                {
                    dp[i][j] = dp[i+1][j-1]+2;
                    if(dp[i][j] > max)
                    {
                        max = dp[i][j];
                        left = i;
                        right = j;
                    }
                }
            }
        }
        return s.substr(left, right-left+1);
    }
};