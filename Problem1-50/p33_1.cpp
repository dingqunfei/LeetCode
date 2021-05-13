/**
 * @file p33_1.cpp
 * @brief 
 * @author dingqunfei (dqflying@gmail.com)
 * @version 1.0
 * @date 2021-04-19
 * 
 * @copyright Copyright (c) 2021 DQFLYING
 * 
 * @par :
 * 
 * 
 * Date        : 2021-04-19
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
    int search(vector<int>& nums, int target) {
        int size = nums.size();
        if(!size)
        {
            return -1;
        }
        if(size == 1)
        {
            return nums[0]==target?0:-1;
        }

        int lhs = 0;
        int rhs = size-1;
        while(lhs <= rhs)
        {
            int mid = (lhs + rhs)/2;
            if(target == nums[mid])
            {
                return mid;
            }
            //需要添加=的情况，否则会错过一些例子，如输入为[1,3] 2
            if(nums[lhs] <= nums[mid])
            {
                if(nums[lhs] <= target && target < nums[mid])
                {
                    rhs = mid-1;
                }
                else
                {
                    lhs = mid+1;
                }
            }
            //需要添加=的情况，否则会错过一些例子，如输入为[1,3] 2
            if(nums[mid] <= nums[rhs])
            {
                if(nums[mid] < target && target <= nums[rhs])
                {
                    lhs = mid+1;
                }
                else
                {
                    rhs = mid-1;
                }
            }
        
        }
        return -1;
    }
};