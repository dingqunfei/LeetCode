/**
 * @file p8_2.cpp
 * @brief 
 * @author dingqunfei (dqflying@gmail.com)
 * @version 1.0
 * @date 2021-08-20
 * 
 * @copyright Copyright (c) 2021 DQFLYING
 * 
 * @par :
 * 
 * 
 * Date        : 2021-08-20
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
    int myAtoi(string s) {
        int index = 0, n = s.size();
        while(index < n && s[index] == ' ')
        {
            ++index;
        }
        if(index == n)
        {
            return 0;
        }
        int sign = 1;
        if(s[index] == '-')
        {
            sign = -1;
            ++index;
        }else if(s[index] == '+')
        {
            ++index;
        }
        int ans = 0;
        while(index < n)
        {
            char cur = s[index];
            if(cur < '0' || cur > '9')
            {
                break;
            }
            if(ans > INT_MAX/10 || ((ans == INT_MAX/10) && (cur-'0' > INT_MAX%10)))
            {
                return INT_MAX;
            }
            if(ans < INT_MIN/10 || ((ans == INT_MIN/10) && (cur-'0' > -(INT_MIN%10))))
            {
                return INT_MIN;
            }
            ans = ans * 10 + sign * (cur - '0');
            index++;
        }
        return ans;
    }
};