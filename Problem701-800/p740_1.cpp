/**
 * @file p740_1.cpp
 * @brief 
 * @author dingqunfei (dqflying@gmail.com)
 * @version 1.0
 * @date 2021-09-18
 * 
 * @copyright Copyright (c) 2021 DQFLYING
 * 
 * @par :
 * 
 * 
 * Date        : 2021-09-18
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
    int deleteAndEarn(vector<int>& nums) {
        int maxValue = *max_element(nums.begin(), nums.end());

        int size = maxValue+1;
        vector<int> sum(size, 0);
        for(int value: nums)
        {
            sum[value] += value;
        }
        
        vector<vector<int>> dp(size, vector<int>(2, 0));
        dp[0][0] = 0, dp[0][1] = 0;
        for(int i = 1; i < size; ++i)
        {
            dp[i][0] = max(dp[i-1][0], dp[i-1][1]);
            dp[i][1] = dp[i-1][0]+sum[i];
        }
        return max(dp[size-1][0], dp[size-1][1]);
    }
};