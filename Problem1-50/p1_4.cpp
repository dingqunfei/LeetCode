/**
 * @file p1_4.cpp
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
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> value_index_map;
        int size = nums.size();
        vector<int> res;
        for(int i = 0; i < size; ++i)
        {
            if(value_index_map.find(nums[i]) != value_index_map.end())
            {
                res.push_back(i);
                res.push_back(value_index_map[nums[i]]);
            }
            else
            {
                value_index_map.insert(make_pair(target-nums[i], i));
            }
        }
        return res;
    }
};