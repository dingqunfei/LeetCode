/**
 * @file p268_1.cpp
 * @brief 
 * @author dingqunfei (dqflying@gmail.com)
 * @version 1.0
 * @date 2021-08-30
 * 
 * @copyright Copyright (c) 2021 DQFLYING
 * 
 * @par :
 * 
 * 
 * Date        : 2021-08-30
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
    int missingNumber(vector<int>& nums) {
        int size = nums.size()+1;
        int actual_sum = accumulate(nums.begin(), nums.end(), 0);
        int should_sum = size * (size-1)/2;
        return should_sum-actual_sum;
    }
};