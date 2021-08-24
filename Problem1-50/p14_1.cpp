/**
 * @file p14_1.cpp
 * @brief 
 * @author dingqunfei (dqflying@gmail.com)
 * @version 1.0
 * @date 2021-08-25
 * 
 * @copyright Copyright (c) 2021 DQFLYING
 * 
 * @par :
 * 
 * 
 * Date        : 2021-08-25
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
    string longestCommonPrefix(vector<string>& strs) {
        
        int size = strs.size();
        if(size < 2)
        {
            return strs[0];
        }
        string ans;
        int min_length = INT_MAX;
        for(int i = 0; i < size; ++i)
        {
            min_length = min_length<strs[i].size()?min_length:strs[i].size();
        }
        for(int i = 0; i < min_length; ++i)
        {
            int j = 0;
            while((j < size-1) && (strs[j][i] == strs[j+1][i]))
            {
                ++j;
            }
            if(j == size-1)
            {
                ans.push_back(strs[0][i]);
            }
            else
            {
                break;
            }
        }
        return ans;
    }
};