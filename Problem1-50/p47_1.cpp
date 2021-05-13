/**
 * @file p47_1.cpp
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
private:
    vector<vector<int>> res;

private:
    void backtrack(vector<int> &nums, vector<int> &track, bool *used)
    {
        if(nums.size() == track.size())
        {
            res.push_back(track);
            return;
        }
        int last = INT_MAX;
        for(int i = 0; i < nums.size(); ++i)
        {
            if(nums[i] == last)
            {
                continue;
            }
            if(used[i])
            {
                continue;
            }
            track.push_back(nums[i]);
            used[i] = true;
            backtrack(nums, track, used);
            track.pop_back();
            used[i] = false;
            last = nums[i];
        }
    }
    
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int len = nums.size();
        bool used[len];
        for(int i = 0; i < len; ++i)
        {
            used[i] = false;
        }
        vector<int> track;
        backtrack(nums, track, used);
        return res;
    }
};