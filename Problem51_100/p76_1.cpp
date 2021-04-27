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

        unordered_map<char, int> needs, window;
        for(auto i: t)
        {
            ++needs[i];
        }

        int lhs = 0, rhs = 0;
        int vaild = 0;
        int start = 0, len = INT_MAX;

        while(rhs < s.size())
        {
            char a = s[rhs];
            ++rhs;
            if(needs.count(a))
            {
                ++window[a];
                if(needs[a] == window[a])
                {
                    ++vaild;
                }
            }

            while(vaild == needs.size())
            {
                if(rhs - lhs < len)
                {
                    len = rhs - lhs;
                    start = lhs;
                }
                char b = s[lhs];
                ++lhs;
                if(needs.count(b))
                {
                    //换一种写法
                    #if 0
                    --window[b];
                    if(window[b] < needs[b])
                    {
                        --vaild;
                    }
                    #else
                    if(window[b] == needs[b])
                    {
                        --vaild;
                    }
                    --window[b];
                    #endif
                }
            }
        }
        return len == INT_MAX ? "" : s.substr(start, len);

    }
};