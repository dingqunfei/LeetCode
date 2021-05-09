/**
 * @file p27_1.cpp
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
    int removeElement(vector<int>& nums, int val) {
        int lhs = 0, rhs = nums.size()-1;
        
        while(lhs < rhs+1)
        {
            if(nums[lhs] != val)
            {
                ++lhs;
                continue;
            }
            if(nums[rhs] == val)
            {
                --rhs;
                continue;
            }
            int tmp = nums[lhs];
            nums[lhs] = nums[rhs];
            nums[rhs] = tmp;
            ++lhs;
            --rhs;
        }
        return lhs;
    }
};