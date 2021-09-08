/**
 * @file p151_1.cpp
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
        vector<string> strVec;
        string tempStr = "";
        bool isSpace = false;
        for(auto ch: s)
        {
            if(ch != ' ')
            {
                tempStr += ch;
            }
            else
            {
                if(tempStr != "")
                {
                    strVec.push_back(tempStr);
                    tempStr = "";
                }
                isSpace = true;
            }
        }
        if(tempStr != "")
        {
            strVec.push_back(tempStr);
        }
        string ans = "";
        int size = strVec.size();
        if(size > 0)
        {
            ans += strVec[size-1];
        }
        for(int i = size-2; i >= 0; --i)
        {
            ans += (" "+strVec[i]);
        }
        return ans;
    }
};