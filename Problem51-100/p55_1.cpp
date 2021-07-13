/**
 * @file p55_1.cpp
 * @brief 
 * @author dingqunfei (dqflying@gmail.com)
 * @version 1.0
 * @date 2021-07-14
 * 
 * @copyright Copyright (c) 2021 DQFLYING
 * 
 * @par :
 * 
 * 
 * Date        : 2021-07-14
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
    bool canJump(vector<int>& nums) {
        int size = nums.size();
        int distance = 0;
        for(int i = 0; i < size-1; ++i)
        {
            distance = max(distance, i+nums[i]);
            if(distance == i)
            {
                return false;
            }
        }

        return distance >= size-1;
    }
};