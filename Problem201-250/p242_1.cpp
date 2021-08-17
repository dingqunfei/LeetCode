/**
 * @file p242_1.cpp
 * @brief 
 * @author dingqunfei (dqflying@gmail.com)
 * @version 1.0
 * @date 2021-08-18
 * 
 * @copyright Copyright (c) 2021 DQFLYING
 * 
 * @par :
 * 
 * 
 * Date        : 2021-08-18
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
    bool isAnagram(string s, string t) {
        int arr[26] = {0};
        int sLen = s.size(), tLen = t.size();
        if(sLen != tLen)
        {
            return false;
        }
        for(int i = 0; i < sLen; ++i)
        {
            ++arr[s[i]-'a'];
            --arr[t[i]-'a'];
        }
        for(int i = 0; i < 26; ++i)
        {
            if(arr[i] != 0)
            {
                return false;
            }
        }
        return true;
    }
};