/**
 * @file p174_1.cpp
 * @brief 
 * @author dingqunfei (dqflying@gmail.com)
 * @version 1.0
 * @date 2021-08-05
 * 
 * @copyright Copyright (c) 2021 DQFLYING
 * 
 * @par :
 * 
 * 
 * Date        : 2021-08-05
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
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size();
        if(m == 0)
        {
            return 0;
        }
        int n = dungeon[0].size();
        if(n == 0)
        {
            return 0;
        }
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[m-1][n-1] = dungeon[m-1][n-1] > 0 ? 1 : 1-dungeon[m-1][n-1];
        for(int i = m-2; i >= 0; --i)
        {
            dp[i][n-1] = dungeon[i][n-1] >= dp[i+1][n-1] ? 1:dp[i+1][n-1]-dungeon[i][n-1];
        }
        for(int j = n-2; j >= 0; --j)
        {
            dp[m-1][j] = dungeon[m-1][j] >= dp[m-1][j+1] ? 1:dp[m-1][j+1]-dungeon[m-1][j];
        }
        for(int i = m-2; i >= 0; --i)
        {
            for(int j = n-2; j >= 0; --j)
            {
                if(dp[i+1][j] > dp[i][j+1])
                {
                    dp[i][j] = dungeon[i][j] >= dp[i][j+1] ? 1:dp[i][j+1]-dungeon[i][j];
                }
                else
                {
                    dp[i][j] = dungeon[i][j] >= dp[i+1][j] ? 1:dp[i+1][j]-dungeon[i][j];
                }
            }
        }

        return dp[0][0];
    }
};