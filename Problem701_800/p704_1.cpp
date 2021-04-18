/**
 * @file p704_1.cpp
 * @brief 
 * @author dingqunfei (dqflying@gmail.com)
 * @version 1.0
 * @date 2021-04-18
 * 
 * @copyright Copyright (c) 2021 DQFLYING
 * 
 * @par :
 * 
 * 
 * Date        : 2021-04-18
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
        int rhs = 0;
        int lhs = nums.size()-1;

        while(rhs <= lhs)
        {
            int mid = (rhs + lhs)/2;
            if(nums[mid] == target)
            {
                return mid;
            }
            else if(nums[mid] < target)
            {
                rhs = mid+1;
            }
            else if(nums[mid] > target)
            {
                lhs = mid-1;
            }
        }
        return -1;

    }
};