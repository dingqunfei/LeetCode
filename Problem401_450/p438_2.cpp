/**
 * @file p438_2.cpp
 * @brief 
 * @author dingqunfei (dqflying@gmail.com)
 * @version 1.0
 * @date 2021-04-29
 * 
 * @copyright Copyright (c) 2021 DQFLYING
 * 
 * @par :
 * 
 * 
 * Date        : 2021-04-29
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
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        unordered_map<char, int> need, window;
        for(auto c: p)
        {
            ++need[c];
        }

        int lhs = 0, rhs = 0, valid = 0;
        while(rhs < s.size())
        {
            char a = s[rhs];
            ++rhs;
            if(need.count(a))
            {
                ++window[a];
                if(window[a] == need[a])
                {
                    ++valid;
                }
            }

            while(rhs - lhs == p.size())
            {
                if(valid == need.size())
                {
                    res.push_back(lhs);
                }
                char b = s[lhs];
                ++lhs;
                if(need.count(b))
                {
                    if(need[b] == window[b])
                    {
                        --valid;
                    }
                    --window[b];
                }
            }
        }
        return res;
    }
};