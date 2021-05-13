/**
 * @file p567_1.cpp
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
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> needs, window;
        for(auto c: s1)
        {
            ++needs[c];
        }

        int lhs = 0, rhs = 0;
        int valid = 0;
        while(rhs < s2.size())
        {
            char a = s2[rhs];
            ++rhs;
            if(needs.count(a))
            {
                ++window[a];
                if(window[a] == needs[a])
                {
                    ++valid;
                }
            }
            //while(rhs - lhs >= s1.size())
            while(rhs - lhs == s1.size())
            {
                if(valid == needs.size())
                {
                    return true;
                }
                char b = s2[lhs];
                ++lhs;
                if(needs.count(b))
                {
                    if(window[b] == needs[b])
                    {
                        --valid;
                    }
                    --window[b];
                }
            }
        }

        return false;
    }
};