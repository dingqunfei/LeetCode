/**
 * @file p409_1.cpp
 * @brief 
 * @author dingqunfei (dqflying@gmail.com)
 * @version 1.0
 * @date 2021-06-18
 * 
 * @copyright Copyright (c) 2021 DQFLYING
 * 
 * @par :
 * 
 * 
 * Date        : 2021-06-18
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
    int longestPalindrome(string s) {
        vector<int> container('z'-'A'+1, 0);
        int size = s.size();
        for(int i = 0; i < size; ++i)
        {
            container[s[i]-'A'] += 1;
        }
        bool isOdd = false;
        int length = 0;
        for(int j = 0; j < container.size(); ++j)
        {
            if(container[j]%2 == 1)
            {
                isOdd = true;
            }
            length += container[j]/2*2;
        }

        return isOdd ? length+1:length;
    }
};



class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> container('z'-'A'+1, 0);
        int size = s.size();
        for(int i = 0; i < size; ++i)
        {
            container[s[i]-'A'] += 1;
        }
        bool isOdd = false;
        int length = 0;
        for(int j = 0; j < container.size(); ++j)
        {
            //改进后更快，100%
            if(!isOdd && (container[j]%2 == 1))
            {
                isOdd = true;
            }
            length += container[j]/2*2;
        }

        return isOdd ? length+1:length;
    }
};