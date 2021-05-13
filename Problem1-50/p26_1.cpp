/**
 * @file p26_1.cpp
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
    int removeDuplicates(vector<int>& nums) {
        int size = nums.size();
        if(size < 2)
        {
            return size;
        }
        int slow = 0, fast = 1;
        while(fast < size)
        {
            if(nums[slow] == nums[fast])
            {
                ++fast;
            }
            else
            {
                ++slow;
                nums[slow] = nums[fast];
                ++fast;
            }
        }
        return slow+1;

    }
};