/**
 * @file p793_1.cpp
 * @brief 
 * @author dingqunfei (dqflying@gmail.com)
 * @version 1.0
 * @date 2021-05-15
 * 
 * @copyright Copyright (c) 2021 DQFLYING
 * 
 * @par :
 * 
 * 
 * Date        : 2021-05-15
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
    long f(long x)
    {
        long count = 0;
        while(x >= 5)
        {
            count += x/5;
            x = x/5;
        }
        return count;
    }
    
public:
    int preimageSizeFZF(long k) {
        if(k == 0)
        {
            return 5;
        }
        long lhs = 0;
        long rhs = 5*k;
        long val = -1;
        while(lhs <= rhs)
        {
            size_t mid = (lhs+rhs)/2;
            size_t zero_num = f(mid);
            if(zero_num > k)
            {
                rhs = mid-1;
            }
            else if(zero_num < k)
            {
                lhs = mid+1;
            }
            else
            {
                val = mid;
                break;
            }
        }
        if(val > 0)
        {
            return 5;
        }
        return 0;
    }
};