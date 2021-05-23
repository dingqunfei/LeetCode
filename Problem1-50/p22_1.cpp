/**
 * @file p22_1.cpp
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

//回溯法，在字符串中，不断插入一个"()"，直到长度达到2*n，使用set去除重复元素
//耗时较长，内存占用较多

class Solution {
private:
    set<string> res;
    //string &track 引用，内存占用减少
    void backtrack(string &track, int n)
    {
        if(track.size() == 2*n)
        {
            res.insert(track);
            return;
        }
        for(int i = 0; i <= track.size(); ++i)
        {
            track.insert(i, "()");
            backtrack(track, n);
            track.erase(i, 2);
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        string track;
        backtrack(track, n);
        return vector(res.begin(), res.end());
    }
};