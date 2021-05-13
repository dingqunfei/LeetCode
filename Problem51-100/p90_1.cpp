/**
 * @file p90_1.cpp
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
        int last = INT_MAX;
        for(int i = start; i < nums.size(); ++i)
        {
            if(nums[i] == last)
            {
                continue;
            }
            track.push_back(nums[i]);
            backtrack(nums, i+1, track);
            track.pop_back();
            last = nums[i];
        }

    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) 
    {
        sort(nums.begin(), nums.end());
        vector<int> track;
        backtrack(nums, 0, track);
        return res;
    }
};