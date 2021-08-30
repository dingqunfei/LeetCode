/**
 * @file p68_1.cpp
 * @brief 
 * @author dingqunfei (dqflying@gmail.com)
 * @version 1.0
 * @date 2021-08-31
 * 
 * @copyright Copyright (c) 2021 DQFLYING
 * 
 * @par :
 * 
 * 
 * Date        : 2021-08-31
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
    int searchInsert(vector<int>& nums, int target) {
        int size = nums.size();
        int left = 0, right = size-1;
        while(left <= right)
        {
            int mid = (left+right)/2;
            if(nums[mid] == target)
            {
                return mid;
            }
            else if(nums[mid] < target)
            {
                left = mid+1;
            }
            else if(nums[mid] > target)
            {
                right = mid-1;
            }
        }
        //if(left == right+1)
        {
            return left;
        }
        
        return 0;
    }
};