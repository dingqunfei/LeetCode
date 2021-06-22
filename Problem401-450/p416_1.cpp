/**
 * @file p416_1.cpp
 * @brief 
 * @author dingqunfei (dqflying@gmail.com)
 * @version 1.0
 * @date 2021-06-23
 * 
 * @copyright Copyright (c) 2021 DQFLYING
 * 
 * @par :
 * 
 * 
 * Date        : 2021-06-23
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
    bool canPartition(vector<int>& nums) {
        int size = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum % 2 == 1)
        {
            return false;
        }
        int part_sum = sum/2;

        vector<vector<bool>> dp(part_sum+1, vector<bool>(size+1, false));
        for(int i = 0; i < size+1; ++i)
        {
            dp[0][i] = true;
        }
        for(int i = 1; i < part_sum+1; ++i)
        {
            for(int j = 1; j < size+1; ++j)
            {
                if(i-nums[j-1] < 0)
                {
                    dp[i][j] = dp[i][j-1];
                }
                else
                {
                    dp[i][j] = dp[i-nums[j-1]][j-1] || dp[i][j-1];
                }
            }
        }

        return dp[part_sum][size];
    }
};