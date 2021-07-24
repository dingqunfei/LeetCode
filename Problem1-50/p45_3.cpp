/**
 * @file p45_3.cpp
 * @brief 
 * @author dingqunfei (dqflying@gmail.com)
 * @version 1.0
 * @date 2021-07-25
 * 
 * @copyright Copyright (c) 2021 DQFLYING
 * 
 * @par :
 * 
 * 
 * Date        : 2021-07-25
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
    int jump(vector<int>& nums) {
        int size = nums.size();
        if(size < 2)
        {
            return 0;
        }
        //dp[i]表示从索引i到终点需要的步数
        vector<int> dp(size, 0);

        for(int i = size-2; i > -1; --i)
        {
            if(nums[i] == 0)
            {
                dp[i] = dp[i+1]+1;
            }
            else if(nums[i] + i > size-2)
            {
                dp[i] = 1;
            }
            else
            {
                dp[i] = 1+*min_element(dp.begin()+i+1, dp.begin()+i+nums[i]+1);
            }

        }
        return dp[0];
    }
};