/**
 * @file p76_1.cpp
 * @brief 
 * @author dingqunfei (dqflying@gmail.com)
 * @version 1.0
 * @date 2021-04-26
 * 
 * @copyright Copyright (c) 2021 DQFLYING
 * 
 * @par :
 * 
 * 
 * Date        : 2021-04-26
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
public:
    string minWindow(string s, string t) {
        map<char, int> needs, window;
        for(auto i: t)
        {
            ++needs[i];
        }

        int lhs = 0, rhs = 0;
        int vaild = 0;
        int start = 0, len = INT_MAX;
        while(rhs < s.size())
        {
            char tmp = s[rhs];
            ++rhs;
            if(needs.count(tmp))
            {
                ++window[tmp];
                if(window[tmp] == needs[tmp])
                {
                    ++vaild;
                }
            }

            while(vaild == needs.size())
            {
                if(rhs - lhs < len)
                {
                    start = lhs;
                    len = rhs - lhs;
                }
                char d = s[lhs];
                ++lhs;
                if(needs.count(d))
                {
                    if(needs[d] == window[d])
                    {
                        --vaild;
                    }
                    --window[d];
                }
                
            }
        }
        return (len == INT_MAX) ?"":s.substr(start, len);
    }
};