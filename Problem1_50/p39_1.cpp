/**
 * @file p39_1.cpp
 * @brief 
 * @author dingqunfei (dqflying@gmail.com)
 * @version 1.0
 * @date 2021-05-14
 * 
 * @copyright Copyright (c) 2021 DQFLYING
 * 
 * @par :
 * 
 * 
 * Date        : 2021-05-14
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
    void backtrack(vector<int> &candidates, int start, int target, vector<int> &track)
    {
        int total = accumulate(track.begin(), track.end(), 0);
        if(total > target)
        {
            return;
        }
        if(total == target)
        {
            res.push_back(track);
            return;
        }
        for(int i = start; i < candidates.size(); ++i)
        {
            track.push_back(candidates[i]);
            backtrack(candidates, i, target, track);
            track.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
        vector<int> track;
        backtrack(candidates, 0, target, track);
        return res;
    }
};