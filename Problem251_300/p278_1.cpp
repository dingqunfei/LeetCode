/**
 * @file p278_1.cpp
 * @brief 
 * @author dingqunfei (dqflying@gmail.com)
 * @version 1.0
 * @date 2021-04-19
 * 
 * @copyright Copyright (c) 2021 DQFLYING
 * 
 * @par :
 * 
 * 
 * Date        : 2021-04-19
 * Version     : 1.0
 * Author      : dqflying
 * Lisence     : 
 * Description : 
 * 
 * 
 * 
 * 
 */

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        long long lhs = 1;
        long long rhs = n;
        while(lhs < rhs) //为什么不是lhs <= rhs
        {
            long long mid = (lhs+rhs)/2;
            bool guess = isBadVersion(mid);
            if(guess)
            {
                rhs = mid;
            }
            else
            {
                lhs = mid+1;
            }
        }
        return rhs;
    }
};