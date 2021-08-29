/**
 * @file p20_1.cpp
 * @brief 
 * @author dingqunfei (dqflying@gmail.com)
 * @version 1.0
 * @date 2021-08-29
 * 
 * @copyright Copyright (c) 2021 DQFLYING
 * 
 * @par :
 * 
 * 
 * Date        : 2021-08-29
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
    bool isValid(string s) {
        stack<char> charStack;
        for(int i = 0; i < s.size(); ++i)
        {
            switch(s[i])
            {
                case ']':
                    if(!charStack.empty() && charStack.top() == '[')
                    {
                        charStack.pop();
                    }
                    else
                    {
                        charStack.push(s[i]);
                    }
                    break;
                case ')':
                    if(!charStack.empty() && charStack.top() == '(')
                    {
                        charStack.pop();
                    }
                    else
                    {
                        charStack.push(s[i]);
                    }
                    break;
                case '}':
                    if(!charStack.empty() && charStack.top() == '{')
                    {
                        charStack.pop();
                    }
                    else
                    {
                        charStack.push(s[i]);
                    }
                    break;
                default:
                    charStack.push(s[i]);
                    break;
            }
        }
        return charStack.empty();
    }
};