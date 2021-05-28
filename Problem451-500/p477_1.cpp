/**
 * @file p477_1.cpp
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
    int totalHammingDistance(vector<int>& nums) {
        int size = nums.size();
        int total = 0;
        int ones = 0;
        for(int i = 0; i < 31; ++i)
        {
            
            for(int j = 0; j < size; ++j)
            {
                ones += (nums[j] >> i)&1;
            }
            total += (size - ones) * ones;
            ones = 0;
        }
        return total;
    }
};