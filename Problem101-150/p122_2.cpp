/**
 * @file p122_2.cpp
 * @brief 
 * @author dingqunfei (dqflying@gmail.com)
 * @version 1.0
 * @date 2021-08-14
 * 
 * @copyright Copyright (c) 2021 DQFLYING
 * 
 * @par :
 * 
 * 
 * Date        : 2021-08-14
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
    int maxProfit(vector<int>& prices) {
        int size = prices.size();
        if(size < 2)
        {
            return 0;
        }
        vector<vector<int>> dp(size, vector<int>(2, 0));
        dp[0][0] = 0;
        dp[0][1] = -prices[0];
        for(int i = 1; i < size; ++i)
        {
            dp[i][0] = max(dp[i-1][0], dp[i-1][1]+prices[i]);
            dp[i][1] = max(dp[i-1][1], dp[i-1][0]-prices[i]);
        }
        return dp[size-1][0];
    }
};