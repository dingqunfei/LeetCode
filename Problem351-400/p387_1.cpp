/**
 * @file p387_1.cpp
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
    int firstUniqChar(string s) {
        int arr[26] = {0};
        for(char ch: s)
        {
            ++arr[ch-'a'];
        }
        for(int i = 0; i < s.size(); ++i)
        {
            if(arr[s[i]-'a'] == 1)
            {
                return i;
            }
        }
        return -1;
    }
};