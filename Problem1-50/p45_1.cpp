/**
 * @file p45_1.cpp
 * @brief 
 * @author dingqunfei (dqflying@gmail.com)
 * @version 1.0
 * @date 2021-07-18
 * 
 * @copyright Copyright (c) 2021 DQFLYING
 * 
 * @par :
 * 
 * 
 * Date        : 2021-07-18
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
    int jump(vector<int>& nums) {
        int n = nums.size();
        int boundary = 0, farthest = 0, jumps = 0;

        for(int i = 0; i < n-1; ++i)
        {
            farthest = max(farthest, i+nums[i]);
            if(i == boundary)
            {
                ++jumps;
                boundary = farthest;
            }
        }

        return jumps;
    }
};