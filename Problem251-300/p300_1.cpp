/**
 * @file p300_1.cpp
 * @brief 
 * @author dingqunfei (dqflying@gmail.com)
 * @version 1.0
 * @date 2021-06-09
 * 
 * @copyright Copyright (c) 2021 DQFLYING
 * 
 * @par :
 * 
 * 
 * Date        : 2021-06-09
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
    int lengthOfLIS(vector<int>& nums) {
        int size = nums.size();
        if(size < 1)
        {
            return 0;
        }
        vector<int> dp(size, 0);
        dp[0] = 1;
        for(int i = 1; i < size; ++i)
        {
                int temp = i-1;
                int larger = 0;
                while(temp >= 0)
                {
                    if(nums[i] > nums[temp])
                    {
                        larger = (dp[temp] > larger)? dp[temp]:larger;
                    }
                    --temp;
                }
                dp[i] = larger+1;
        }
        
        return *(max_element(dp.begin(), dp.end()));
    }
};