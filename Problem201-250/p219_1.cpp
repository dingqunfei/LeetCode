/**
 * @file p219_1.cpp
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
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> valueIndexMap;
        for(int i = 0; i < nums.size(); ++i)
        {
            if(valueIndexMap.count(nums[i]))
            {
                if(i-valueIndexMap[nums[i]] <= k)
                {
                    return true;
                }

            }
            valueIndexMap[nums[i]] = i;
        }
        return false;
    }
};