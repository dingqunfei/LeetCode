/**
 * @file p974_1.cpp
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
    int subarraysDivByK(vector<int>& nums, int k) {
        int size = nums.size();
        unordered_map<int, int> preSumFreq;
        preSumFreq[0] = 1;
        int count = 0;
        int preSum = 0;
        //余数相同，那么差就是k的倍数
        for(int i = 0; i < size; ++i)
        {
            preSum += nums[i];
            int curr = (preSum % k + k)%k;
            
            count += preSumFreq[curr];
            preSumFreq[curr] += 1;
        }
        return count;
    }
};