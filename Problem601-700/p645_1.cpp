/**
 * @file p645_1.cpp
 * @brief 
 * @author dingqunfei (dqflying@gmail.com)
 * @version 1.0
 * @date 2021-05-18
 * 
 * @copyright Copyright (c) 2021 DQFLYING
 * 
 * @par :
 * 
 * 
 * Date        : 2021-05-18
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
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> res;
        for(int i = 0; i < nums.size(); ++i)
        {
            //这里的索引要取正值，可能会被前面遍历过的置为负值
            int val = abs(nums[i]);
            if(nums[val-1] < 0)
            {
                res.push_back(val);
            }
            else
            {
                int temp = nums[val-1];
                nums[val-1] = -temp;
            }
        }
        for(int i = 0; i < nums.size(); ++i)
        {
            if(nums[i] > 0)
            {
                res.push_back(i+1);
                break;
            }
        }
        return res;
    }
};