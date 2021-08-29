/**
 * @file 268_2.cpp
 * @brief 
 * @author dingqunfei (dqflying@gmail.com)
 * @version 1.0
 * @date 2021-08-30
 * 
 * @copyright Copyright (c) 2021 DQFLYING
 * 
 * @par :
 * 
 * 
 * Date        : 2021-08-30
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
    int missingNumber(vector<int>& nums) {
        int size = nums.size();
        int res = size;
        for(int i = 0; i < size; ++i)
        {
            res ^= nums[i];
            res ^= i;
        }
        return res;
    }
};