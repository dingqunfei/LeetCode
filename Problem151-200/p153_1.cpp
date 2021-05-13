/**
 * @file p153_1.cpp
 * @brief 
 * @author dingqunfei (dqflying@gmail.com)
 * @version 1.0
 * @date 2021-04-21
 * 
 * @copyright Copyright (c) 2021 DQFLYING
 * 
 * @par :
 * 
 * 
 * Date        : 2021-04-21
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
    int findMin(vector<int>& nums) {
        int lhs = 0;
        int rhs = nums.size()-1;
        while(lhs < rhs)
        {
            int mid = (lhs + rhs)/2;
            if(nums[mid] <= nums[rhs])
            {
                rhs = mid;
            }
            else if((nums[lhs] <= nums[mid]) && (nums[lhs] > nums[rhs]))
            {
                lhs = mid+1;
            }
            else if((nums[lhs] <= nums[mid]) && (nums[lhs] < nums[rhs]))
            {
                return nums[lhs];
            }
        }
        return nums[lhs];
    }
};