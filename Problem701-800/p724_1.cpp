/**
 * @file p724_1.cpp
 * @brief 
 * @author dingqunfei (dqflying@gmail.com)
 * @version 1.0
 * @date 2021-05-28
 * 
 * @copyright Copyright (c) 2021 DQFLYING
 * 
 * @par :
 * 
 * 
 * Date        : 2021-05-28
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
    int pivotIndex(vector<int>& nums) {
        int size = nums.size();
        vector<int> preSum;
        int sum = 0;
        preSum.push_back(0);
        for(int i = 0; i < size; ++i)
        {
            sum += nums[i];
            preSum.push_back(sum);
        }
        for(int i = 0; i < size; ++i)
        {
            if(preSum[size] - nums[i] == 2 * preSum[i])
            {
                return i;
            }
        }
        return -1;
    }
};