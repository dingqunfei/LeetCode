/**
 * @file p28_2.cpp
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
        
        int i = 0, j = 0;
        while(i < m && j < n)
        {
            if(haystack[i] == needle[j])
            {
                ++j;
                ++i;
            }
            else
            {
                i = i-j+1;
                j = 0;
            }
        }
        if(j == n)
        {
            return i-j;
        }
        return -1;
    }
};