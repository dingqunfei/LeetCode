/**
 * @file p51_1.cpp
 * @brief 
 * @author dingqunfei (dqflying@gmail.com)
 * @version 1.0
 * @date 2021-05-16
 * 
 * @copyright Copyright (c) 2021 DQFLYING
 * 
 * @par :
 * 
 * 
 * Date        : 2021-05-16
 * Version     : 1.0
 * Author      : dqflying
 * Lisence     : 
 * Description : 
 * 
 * 
 * 
 * 
 */

//终于解决了N皇后问题, happy happy

class Solution {
private:
    vector<vector<int>> label;

    //这个转换过程有点绕
    void convert(vector<vector<string>> &res)
    {
        for(int i = 0; i < label.size(); ++i)
        {
            vector<int> ans = label[i];
            for(int j = 0; j < ans.size(); ++j)
            {
                res[i][j][ans[j]] = 'Q';
            }
        }
    }

    bool isLegal(vector<int> &track)
    {
        int size = track.size();
        if(size <= 1)
        {
            return true;
        }
        for(int i = 0; i < size-1; ++i)
        {
            if( (track[i] == track[size-1]) || 
            ((track[size-1]-track[i]) == (size-1-i)) ||
            ((track[size-1]-track[i]) == -(size-1-i)) )
            {
                return false;
            }
        }
        return true;
    }

    void backtrack(int n, vector<int> &track)
    {
        if(track.size() == n)
        {
            label.push_back(track);
            return;
        }
        for(int i = 0; i < n; ++i)
        {
            track.push_back(i);
            if(isLegal(track))
            {
                backtrack(n, track);
            }
            track.pop_back();
        }

    }

public:
    vector<vector<string>> solveNQueens(int n) 
    {
        vector<int> track;
        backtrack(n, track);

        vector<vector<string>> res(label.size(), vector(n, string(n, '.')));
        convert(res);
        return res;
    }
};