/**
 * @file p53_1.cpp
 * @brief 
 * @author dingqunfei (dqflying@gmail.com)
 * @version 1.0
 * @date 2021-06-11
 * 
 * @copyright Copyright (c) 2021 DQFLYING
 * 
 * @par :
 * 
 * 
 * Date        : 2021-06-11
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
    int maxSubArray(vector<int>& nums) {
        int size = nums.size();
        vector<int> dp(size, 0);
        if(size < 1)
        {
            return -1;
        }
        dp[0] = nums[0];
        for(int i = 1; i < size; ++i)
        {
            dp[i] = (dp[i-1] > 0)?(dp[i-1]+nums[i]):nums[i];
        }
        return *(max_element(dp.begin(), dp.end()));
    }
};


//优化了内存占用
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int size = nums.size();
        
        if(size < 1)
        {
            return -1;
        }
        int max_element = nums[0];
        int last = nums[0];
        for(int i = 1; i < size; ++i)
        {
            last = (last > 0)?(last+nums[i]):nums[i];
            max_element = max(last, max_element);
        }
        return max_element;
    }
};