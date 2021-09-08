/**
 * @file p151_2.cpp
 * @brief 
 * @author dingqunfei (dqflying@gmail.com)
 * @version 1.0
 * @date 2021-09-09
 * 
 * @copyright Copyright (c) 2021 DQFLYING
 * 
 * @par :
 * 
 * 
 * Date        : 2021-09-09
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
    string reverseWords(string s) {
        string tempStr = "";
        string ans = "";
        bool isSpace = false;
        int sLen = s.size();
        for(int i = sLen-1; i >= 0; --i)
        {
            if(s[i] != ' ')
            {
                tempStr += s[i];
            }
            else
            {
                if(tempStr != "")
                {
                    reverse(tempStr.begin(), tempStr.end());
                    ans += (tempStr+" ");
                    tempStr = "";
                }
                isSpace = true;
            }
        }
        if(tempStr != "")
        {
            reverse(tempStr.begin(), tempStr.end());
            ans += tempStr;
        }
        else
        {
            ans.erase(ans.end()-1);
        }
        
        //reverse(ans.begin(), ans.end());
        return ans;
    }
};