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



//修改，使用数组used 为nums中元素是否使用做标记
/*
class Solution {
private:
    vector<vector<int>> res;

public:
    void backtrack(vector<int> &nums, vector<int> &track, bool *used)
    {
        if(track.size() == nums.size())
        {
            res.push_back(track);
            return;
        }
        for(int i = 0; i < nums.size(); ++i)
        {
            if(used[i])
            {
                continue;
            }
            track.push_back(nums[i]);
            used[i] = true;
            backtrack(nums, track, used);
            track.pop_back();
            used[i] = false;
        }

    }

    vector<vector<int>> permute(vector<int>& nums) 
    {
        vector<int> track;
        int len = nums.size();
        bool used[len];
        for(int i = 0; i < len; ++i)
        {
            used[i] = false;
        }
        backtrack(nums, track, used);
        return res;
    }
};
*/