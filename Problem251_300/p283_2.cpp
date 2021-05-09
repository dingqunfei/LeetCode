/**
 * @file p283_2.cpp
 * @brief 
 * @author dingqunfei (dqflying@gmail.com)
 * @version 1.0
 * @date 2021-05-09
 * 
 * @copyright Copyright (c) 2021 DQFLYING
 * 
 * @par :
 * 
 * 
 * Date        : 2021-05-09
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
    void moveZeroes(vector<int>& nums) {
        int size = nums.size();
        int lhs = 0, rhs = 0;
        while(rhs < size)
        {
            if(nums[rhs])
            {
                swap(nums[lhs], nums[rhs]);
                ++lhs;
            }
            ++rhs;
        }
    }
};