/**
 * @file p209_1.cpp
 * @brief 
 * @author dingqunfei (dqflying@gmail.com)
 * @version 1.0
 * @date 2021-09-12
 * 
 * @copyright Copyright (c) 2021 DQFLYING
 * 
 * @par :
 * 
 * 
 * Date        : 2021-09-12
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
    int minSubArrayLen(int target, vector<int>& nums) {
        int size = nums.size();
        int minArrayLen = INT_MAX;
        int i = 0, j = 0;
        while(j <= size)
        {
            int nArraySum = accumulate(nums.begin()+i, nums.begin()+j, 0);
            if(nArraySum >= target)
            {
                minArrayLen = min(minArrayLen, j-i);
                ++i;
            }
            else
            {
                ++j;
            }
        }
        return minArrayLen==INT_MAX?0:minArrayLen;
    }
};