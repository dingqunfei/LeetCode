/**
 * @file p518_1.cpp
 * @brief 
 * @author dingqunfei (dqflying@gmail.com)
 * @version 1.0
 * @date 2021-07-05
 * 
 * @copyright Copyright (c) 2021 DQFLYING
 * 
 * @par :
 * 
 * 
 * Date        : 2021-07-05
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
    int change(int amount, vector<int>& coins) {
        int size = coins.size();
        vector<vector<int>> dp(amount+1, vector<int>(size+1, 0));
        for(int i = 0; i < size+1; ++i)
        {
            dp[0][i] = 1;
        }
        for(int i = 1; i < amount+1; ++i)
        {
            for(int j = 1; j < size+1; ++j)
            {
                if(i - coins[j-1] >= 0)
                {
                    dp[i][j] = dp[i][j-1] + dp[i-coins[j-1]][j];
                }
                else
                {
                    dp[i][j] = dp[i][j-1];
                }
            }
        }

        return dp[amount][size];
    }
};