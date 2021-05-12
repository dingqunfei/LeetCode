/**
 * @file p78_2.cpp
 * @brief 
 * @author dingqunfei (dqflying@gmail.com)
 * @version 1.0
 * @date 2021-05-13
 * 
 * @copyright Copyright (c) 2021 DQFLYING
 * 
 * @par :
 * 
 * 
 * Date        : 2021-05-13
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
private:
    vector<vector<int>> res;

private:
    void backtrack(vector<int> &nums, int start, vector<int> &track)
    {
        res.push_back(track);
        for(int i = start; i < nums.size(); ++i)
        {
            track.push_back(nums[i]);
            backtrack(nums, i+1, track);
            //这里为什么要pop_back()撤销选择的元素？
            //对于i的每次循环，取消前一次选择的nums[i]
            track.pop_back();
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> track;
        backtrack(nums, 0, track);
        return res;
    }
};