/**
 * @file p485_1.cpp
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
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int nConsecutiveOnes = 0;
        int size = nums.size();
        int i = 0, j = 0;
        while(i < size && j < size)
        {
            if(nums[j] != 1)
            {
                nConsecutiveOnes = max(nConsecutiveOnes, j-i);
                ++j;
                i = j;
            }
            else
            {
                ++j;
            }
        }
        return max(nConsecutiveOnes, j-i);
    }
};