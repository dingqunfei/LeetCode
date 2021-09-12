/**
 * @file p28_3.cpp
 * @brief 
 * @author dingqunfei (dqflying@gmail.com)
 * @version 1.0
 * @date 2021-09-12
 * 
 * @copyright Copyright (c) 2021 DQFLYING
 * 
 * @par :
 * 
 * 
 * Date        : 2021-09-12
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
    vector<int> getNext(string pattern)
    {
        int size = pattern.size();
        vector<int> next(size, 0);
        next[0] = -1;
        int k = -1, j = 0;
        while(j < size-1)
        {
            if(k == -1 || pattern[j] == pattern[k])
            {
                ++k;
                ++j;
                next[j] = k;
            }
            else
            {
                k = next[k];
            }
        }

        return next;
    }
public:
    int strStr(string haystack, string needle) {
        int m = haystack.size();
        int n = needle.size();
        if(n == 0)
        {
            return 0;
        }
        if(m == 0)
        {
            return -1;
        }
        vector<int> next = getNext(needle);
        int i = 0, j = 0;
        while(i < m && j < n)
        {
            if(j == -1 || haystack[i] == needle[j])
            {
                ++j;
                ++i;
            }
            else
            {
                //i = i-j+1;
                j = next[j];
            }
        }
        if(j == n)
        {
            return i-j;
        }
        return -1;
    }
};