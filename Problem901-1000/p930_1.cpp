/**
 * @file p930_1.cpp
 * @brief 
 * @author dingqunfei (dqflying@gmail.com)
 * @version 1.0
 * @date 2021-05-29
 * 
 * @copyright Copyright (c) 2021 DQFLYING
 * 
 * @par :
 * 
 * 
 * Date        : 2021-05-29
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
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int, int> preSumFreq;
        preSumFreq[0] = 1;
        int size = nums.size();
        int preSum = 0;
        int result = 0;
        for(int i = 0; i < size; ++i)
        {
            preSum += nums[i];
            result += preSumFreq[preSum-goal];
            
            preSumFreq[preSum] += 1;
        }
        return result;
    }
};