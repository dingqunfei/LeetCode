/**
 * @file p77_1.cpp
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
    void backtrack(int n, int k, int start, vector<int> &track)
    {
        if(track.size() == k)
        {
            res.push_back(track);
            return;
        }
        for(int i = start; i < n; ++i)
        {
            track.push_back(i+1);
            backtrack(n, k, i+1, track);
            track.pop_back();
        }
    }

public:
    vector<vector<int>> combine(int n, int k) 
    {
        vector<int> track;
        backtrack(n, k, 0, track);
        return res;
    }
};