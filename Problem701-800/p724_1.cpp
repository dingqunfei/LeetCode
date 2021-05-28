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


//优化版本，直接计算最终的sum和
class Solution {
public:
    int pivotIndex(vector<int> &nums) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        int sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (2 * sum + nums[i] == total) {
                return i;
            }
            sum += nums[i];
        }
        return -1;
    }
};