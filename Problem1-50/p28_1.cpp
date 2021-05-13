/**
 * @file p28_1.cpp
 * @brief 
 * @author dingqunfei (dqflying@gmail.com)
 * @version 1.0
 * @date 2021-04-20
 * 
 * @copyright Copyright (c) 2021 DQFLYING
 * 
 * @par :
 * 
 * 
 * Date        : 2021-04-20
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
        int increment = 0;
        while(i+increment < m && j < n)
        {
            
            if(haystack[i+increment] == needle[j])
            {
                if(j == n-1)
                {
                    return i;
                }
                ++increment;
                ++j;
            }
            else
            {   
                increment = 0;
                j = 0;
                ++i;
            }
        }
        return -1;
    }
};