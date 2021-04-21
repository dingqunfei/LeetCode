/**
 * @file p34_1.cpp
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
private:
    int findFirstTarget(vector<int> &nums, int target)
    {
        int size = nums.size();
        /*if(size == 0)
        {
            return -1;
        }
        if(size == 1)
        {
            return nums[0] == target ? 0:-1;
        }
        */
        int lhs = 0;
        int rhs = size;
        while(lhs < rhs)
        {
            int mid = (lhs + rhs)/2;
            if(nums[mid] > target)
            {
                rhs = mid;
            }
            else if(nums[mid] == target)
            {
                rhs = mid;
            }
            else if(nums[mid] < target)
            {
                lhs = mid + 1;
            }
        }
        if(lhs == size)
        {
            return -1;
        }
        return nums[lhs] == target ? lhs:-1;
    }

    int findLastTarget(vector<int> &nums, int target)
    {
        int size = nums.size();
        /*
        if(size == 0)
        {
            return -1;
        }
        if(size == 1)
        {
            return nums[0] == target ? 0:-1;
        }
        */
        int lhs = 0;
        int rhs = size;
        while(lhs < rhs)
        {
            int mid = (lhs + rhs)/2;
            if(nums[mid] > target)
            {
                rhs = mid;
            }
            else if(nums[mid] == target)
            {
                lhs = mid + 1;
            }
            else if(nums[mid] < target)
            {
                lhs = mid + 1;
            }
        }
        if(lhs == 0)
        {
            return -1;
        }
        return nums[lhs-1] == target ? lhs-1:-1;
    }

public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = findFirstTarget(nums, target);
        int right = findLastTarget(nums, target);
        //if(left <= right && right < nums.size() && nums[left] == target && nums[right] == target)
        
        return {left, right};
        
    }   
};