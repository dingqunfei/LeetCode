/**
 * @file p189_1.cpp
 * @brief 
 * @author dingqunfei (dqflying@gmail.com)
 * @version 1.0
 * @date 2021-08-15
 * 
 * @copyright Copyright (c) 2021 DQFLYING
 * 
 * @par :
 * 
 * 
 * Date        : 2021-08-15
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
    void rotate(vector<int>& nums, int k) {
        int size = nums.size();
        k %= size;
        reverse(nums, 0, size-k-1);
        reverse(nums, size-k, size-1);
        reverse(nums, 0, size-1);
    }
    void reverse(vector<int> &nums, int start, int end)
    {
        while(start < end)
        {
            swap(nums[start], nums[end]);
            ++start;
            --end;
        }
    }
};