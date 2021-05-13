/**
 * @file p38_1.cpp
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
    vector<string> res;

private:
    void backtrack(string &s, vector<bool> &used, string &track)
    {
        if(track.size() == s.size())
        {
            res.push_back(track);
        }
        char last = '0';
        for(int i = 0; i < s.size(); ++i)
        {
            if(!used[i] && s[i] != last)
            {
                track.push_back(s[i]);
                used[i] = true;
                backtrack(s, used, track);
                track.pop_back();
                used[i] = false;
                last = s[i];
            }
        }
    }

public:
    vector<string> permutation(string s) 
    {
        string track;
        vector<bool> used;
        for(int i = 0; i < s.size(); ++i)
        {
            used.push_back(false);
        }
        sort(s.begin(), s.end());
        backtrack(s, used, track);
        return res;
    }
};