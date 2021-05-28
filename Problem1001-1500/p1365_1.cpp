/**
 * @file p1365_1.cpp
 * @brief 
 * @author dingqunfei (dqflying@gmail.com)
 * @version 1.0
 * @date 2021-05-28
 * 
 * @copyright Copyright (c) 2021 DQFLYING
 * 
 * @par :
 * 
 * 
 * Date        : 2021-05-28
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
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int size = nums.size();
        vector<int> result = nums;
        sort(result.begin(), result.end());
        unordered_map<int, int> valueIndex;
        for(int i = 0; i < size; ++i)
        {
           if(!valueIndex.count(result[i]))
           {
               valueIndex[result[i]] = i;
           }
        }
        for(int i = 0; i < size; ++i)
        {
            result[i] = valueIndex[nums[i]];
        }
        return result;
    }
};