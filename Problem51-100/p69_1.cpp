/**
 * @file p69_1.cpp
 * @brief 
 * @author dingqunfei (dqflying@gmail.com)
 * @version 1.0
 * @date 2021-04-18
 * 
 * @copyright Copyright (c) 2021 DQFLYING
 * 
 * @par :
 * 
 * 
 * Date        : 2021-04-18
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
    int mySqrt(int x) {
        long long rhs = 0;
        long long lhs = x;
        
        while(rhs <= lhs)
        {
            long long mid = (rhs + lhs)/2;
            if(mid * mid <= x && (mid+1)*(mid+1) > x)
            {
                return mid;
            }
            else if(mid * mid > x)
            {
                lhs = mid-1;
            }
            else if((mid+1)*(mid+1) < x)
            {
                rhs = mid+1;
            }
            else if((mid+1)*(mid+1) == x)
            {
                return mid+1;
            }
        }
        return 0;
    }
};