/**
 * @file p344_1.cpp
 * @brief 
 * @author dingqunfei (dqflying@gmail.com)
 * @version 1.0
 * @date 2021-08-17
 * 
 * @copyright Copyright (c) 2021 DQFLYING
 * 
 * @par :
 * 
 * 
 * Date        : 2021-08-17
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
    void reverseString(vector<char>& s) {
        int size = s.size();
        int i = 0;
        while(i < size/2)
        {
            char temp = s[i];
            s[i] = s[size-1-i];
            s[size-1-i] = temp;
            ++i;
        }
    }
};