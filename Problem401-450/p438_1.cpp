/**
 * @file p438_1.cpp
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
        int windowSize = p.size();
        int sSize = s.size();
        vector<int> res;

        if(windowSize > sSize)
        {
            return res;
        }

        vector<int> hashmap1(26, 0), hashmap2(26, 0);
        for(int i = 0; i < windowSize; ++i)
        {
            ++hashmap1[p[i] - 'a'];
            ++hashmap2[s[i] - 'a'];
        }
        int i = windowSize;
        for(; i < sSize; ++i)
        {
            if(hashmap1 == hashmap2)
            {
                res.push_back(i - windowSize);
            }
            --hashmap2[s[i - windowSize] - 'a'];
            ++hashmap2[s[i] - 'a'];
        }
        if(hashmap1 == hashmap2)
        {
            res.push_back(i - windowSize);
        }
        return res;
    }
};