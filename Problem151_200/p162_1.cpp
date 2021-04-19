/**
 * @file p162_1.cpp
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
    //NB plus
    int findPeakElement(vector<int>& nums) {
        int size = nums.size();
        
        for(int i = 0; i < size-1; ++i)
        {
            if(nums[i] > nums[i+1])
            {
                return i;
            }
        }
        return size-1;
    }
};