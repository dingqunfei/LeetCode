/**
 * @file p523_1.cpp
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
    bool checkSubarraySum(vector<int>& nums, int k) {
        int size = nums.size();
        
        unordered_map<int, int> preSumFreq;
        preSumFreq[0] = -1;
        long preSum = 0;
        for(int i = 0; i < size; ++i)
        {
            preSum += nums[i];
            int curr = (preSum % k + k)%k;
            if(preSumFreq.count(curr))
            {
                if(i - preSumFreq[curr] > 1)
                {
                    return true;
                }
            }
            else
            {
                preSumFreq[curr] = i;
            }
        }

        return false;
    }
};