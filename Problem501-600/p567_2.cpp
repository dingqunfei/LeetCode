/**
 * @file p567_2.cpp
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
        if(s1.size() > s2.size())
        {
            return false;
        }

        int windowSize = s1.size();
        vector<int> hashmap1(26, 0);
        vector<int> hashmap2(26, 0);

        for(int i = 0; i < windowSize; ++i)
        {
            ++hashmap1[s1[i] - 'a'];
            ++hashmap2[s2[i] - 'a'];
        }

        for(int i = windowSize; i < s2.size(); ++i)
        {
            if(hashmap1 == hashmap2)
            {
                return true;
            }
            --hashmap2[s2[i - windowSize] - 'a'];
            ++hashmap2[s2[i] - 'a'];
        }

        return hashmap1 == hashmap2;
    }
};