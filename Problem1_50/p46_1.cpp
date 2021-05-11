/**
 * @file p46_1.cpp
 * @brief 
 * @author dingqunfei (dqflying@gmail.com)
 * @version 1.0
 * @date 2021-05-11
 * 
 * @copyright Copyright (c) 2021 DQFLYING
 * 
 * @par :
 * 
 * 
 * Date        : 2021-05-11
 * Version     : 1.0
 * Author      : dqflying
 * Lisence     : 
 * Description : 
 * 
 * 
 * 
 * 
 */

//查看链接视频解说
//https://leetcode-cn.com/problems/permutations/solution/quan-pai-lie-by-leetcode-solution-2/

class Solution {
private:
    vector<vector<int>> res;

public:
    void backtrack(vector<int> &nums, vector<int> &track)
    {
        if(track.size() == nums.size())
        {
            res.push_back(track);
            return;
        }
        for(int i = 0; i < nums.size(); ++i)
        {
            if(find(track.begin(), track.end(), nums[i]) != track.end())
            {
                continue;
            }
            track.push_back(nums[i]);
            backtrack(nums, track);
            track.pop_back();
        }

    }

    vector<vector<int>> permute(vector<int>& nums) 
    {
        vector<int> track;
        backtrack(nums, track);
        return res;
    }
};