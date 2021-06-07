/**
 * @file p494_2.cpp
 * @brief 
 * @author dingqunfei (dqflying@gmail.com)
 * @version 1.0
 * @date 2021-06-08
 * 
 * @copyright Copyright (c) 2021 DQFLYING
 * 
 * @par :
 * 
 * 
 * Date        : 2021-06-08
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
private:
    int subsets(vector<int> &nums, int target)
    {
        int size = nums.size();
        vector<vector<int>> dp(size+1, vector<int>(target+1, 0));
        for(int i = 0; i < size+1; ++i)
        {
            dp[i][0] = 1;
        }
        for(int i = 1; i < size+1; ++i)
        {
            for(int j = 0; j < target+1; ++j)
            {
                if(j >= nums[i-1])
                {
                    dp[i][j] = dp[i-1][j] + dp[i-1][j-nums[i-1]];
                }
                else
                {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[size][target];
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum < target || (sum+target)%2 == 1)
        {
            return 0;
        }
        return subsets(nums, (sum+target)/2);
    }
};
