/**
 * @file p560_1.cpp
 * @brief 
 * @author dingqunfei (dqflying@gmail.com)
 * @version 1.0
 * @date 2021-05-26
 * 
 * @copyright Copyright (c) 2021 DQFLYING
 * 
 * @par :
 * 
 * 
 * Date        : 2021-05-26
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
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> preSum;
        int size = nums.size();
        preSum[0] = 1;
        int ret = 0, sum = 0;
        for(int i = 0; i < size; ++i)
        {
            sum += nums[i];
            if(preSum.count(sum-k))
            {
                ret += preSum[sum-k];
            }
            
            ++preSum[sum];
        }
        return ret;
    }
};