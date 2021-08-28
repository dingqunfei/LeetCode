/**
 * @file p198_1.cpp
 * @brief 
 * @author dingqunfei (dqflying@gmail.com)
 * @version 1.0
 * @date 2021-08-28
 * 
 * @copyright Copyright (c) 2021 DQFLYING
 * 
 * @par :
 * 
 * 
 * Date        : 2021-08-28
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
    int rob(vector<int>& nums) {
        int size = nums.size();
        vector<vector<int>> dp(size+1, vector<int>(2, 0));
        dp[0][0] = 0, dp[0][1] = 0;
        for(int i = 1; i <= size; ++i)
        {
            dp[i][0] = max(dp[i-1][1], dp[i-1][0]);
            dp[i][1] = dp[i-1][0]+nums[i-1];
        }
        return max(dp[size][0], dp[size][1]);
    }
};