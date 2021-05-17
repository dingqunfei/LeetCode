/**
 * @file p372_1.cpp
 * @brief 
 * @author dingqunfei (dqflying@gmail.com)
 * @version 1.0
 * @date 2021-05-16
 * 
 * @copyright Copyright (c) 2021 DQFLYING
 * 
 * @par :
 * 
 * 
 * Date        : 2021-05-16
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
private:
    int base = 1337;
    int mypow(int a, int b)
    {
        a = a % base;
        int res = 1;
        for(int i = 0; i < b; ++i)
        {
            res *= a;
            res %= base;
        }
        return res;
    }
public:
    int superPow(int a, vector<int>& b) {
        int res = 1;
        if(b.empty())
        {
            return res;
        }
            
        int last = b.back();
        b.pop_back();
        res = mypow(a, last) * mypow(superPow(a, b), 10) % base;
        
        return res;
    }
};