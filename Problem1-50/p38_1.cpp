/**
 * @file p38_1.cpp
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
    string countAndSay(int n) {
        string ans = "1";
        
        while(n > 1)
        {
            vector<char> charVec={'a'};
            vector<char> intVec = {'0'};
            for(char ch: ans)
            {
                if(ch == charVec.back())
                {
                    intVec.back() += 1;
                }
                else
                {
                    charVec.push_back(ch);
                    intVec.push_back('1');
                }
            }
            int size = charVec.size();
            ans.clear();
            for(int i = 1; i < size; ++i)
            {
                ans.push_back(intVec[i]);
                ans.push_back(charVec[i]);
            }

            --n;
        }
        return ans;

    }
};