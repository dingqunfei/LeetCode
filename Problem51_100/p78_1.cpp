/**
 * @file p78_1.cpp
 * @brief 
 * @author dingqunfei (dqflying@gmail.com)
 * @version 1.0
 * @date 2021-05-12
 * 
 * @copyright Copyright (c) 2021 DQFLYING
 * 
 * @par :
 * 
 * 
 * Date        : 2021-05-12
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
    vector<vector<int>> subsets(vector<int>& nums) {
        int size = nums.size();
        vector<vector<int>> res = {{}};
        if(size == 0)
        {
            return res;
        }
        for(int i = 0; i < size; ++i)
        {
            int subset_size = res.size();
            for(int j = 0; j < subset_size; ++j)
            {
                vector<int> tmp = res[j];
                tmp.push_back(nums[i]);
                res.push_back(tmp);
            }
        }
        return res;
    }
};