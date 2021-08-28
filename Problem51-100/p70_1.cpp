/**
 * @file p70_1.cpp
 * @brief 
 * @author dingqunfei (dqflying@gmail.com)
 * @version 1.0
 * @date 2021-08-28
 * 
 * @copyright Copyright (c) 2021 DQFLYING
 * 
 * @par :
 * 
 * 
 * Date        : 2021-08-28
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
    int climbStairs(int n) {
        if(n == 1)
        {
            return 1;
        }
        if(n == 2)
        {
            return 2;
        }
        int a = 1, b = 2, temp;
        for(int i = 3; i <= n; ++i)
        {
            temp = a;
            a = b;
            b = temp+b;
        }
        return b;
    }
};