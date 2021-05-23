/**
 * @file p22_2.cpp
 * @brief 
 * @author dingqunfei (dqflying@gmail.com)
 * @version 1.0
 * @date 2021-05-23
 * 
 * @copyright Copyright (c) 2021 DQFLYING
 * 
 * @par :
 * 
 * 
 * Date        : 2021-05-23
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

    void backtrack(string &track, int left, int right)
    {
        if(left > right)
        {
            return;
        }
        if(right < 0 || left < 0)
        {
            return;
        }
        if(left == 0 && right == 0)
        {
            res.push_back(track);
        }

        track.push_back('(');
        backtrack(track, left-1, right);
        track.pop_back();

        track.push_back(')');
        backtrack(track, left, right-1);
        track.pop_back();
    }
public:
    vector<string> generateParenthesis(int n) {
        string track;
        backtrack(track, n, n);
        return res;
    }
};