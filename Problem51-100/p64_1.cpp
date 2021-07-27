/**
 * @file p64_1.cpp
 * @brief 
 * @author dingqunfei (dqflying@gmail.com)
 * @version 1.0
 * @date 2021-07-28
 * 
 * @copyright Copyright (c) 2021 DQFLYING
 * 
 * @par :
 * 
 * 
 * Date        : 2021-07-28
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
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = grid[0][0];
        for(int i = 1; i < m; ++i)
        {
            dp[i][0] = grid[i][0]+dp[i-1][0];
        }
        for(int j = 1; j < n; ++j)
        {
            dp[0][j] = grid[0][j]+dp[0][j-1];
        }
        for(int i = 1; i < m; ++i)
        {
            for(int j = 1; j < n; ++j)
            {
                dp[i][j] = min(dp[i-1][j], dp[i][j-1])+grid[i][j];
            }
        }

        return dp[m-1][n-1];
    }
};