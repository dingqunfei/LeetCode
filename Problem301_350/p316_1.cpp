/**
 * @file p316_1.cpp
 * @brief 
 * @author dingqunfei (dqflying@gmail.com)
 * @version 1.0
 * @date 2021-05-09
 * 
 * @copyright Copyright (c) 2021 DQFLYING
 * 
 * @par :
 * 
 * 
 * Date        : 2021-05-09
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
    string removeDuplicateLetters(string s) {
        int charIndexMap[256] = {0};
        stack<char> charStack;
        bool label[256] = {false};
        for(char ch: s)
        {
            ++charIndexMap[ch];
        }
        for(char ch: s)
        {
            --charIndexMap[ch];
            if(label[ch])
            {
                continue;
            }
            while(!charStack.empty() && charStack.top() > ch)
            {
                
                if(charIndexMap[charStack.top()] == 0)
                {
                    break;
                }
                label[charStack.top()] = false;
                charStack.pop();
            }
            charStack.push(ch);
            label[ch] = true;
        }
        string res;
        while(!charStack.empty())
        {
            res.insert(0, 1, charStack.top());
            charStack.pop();
        }

        return res;
    }
};