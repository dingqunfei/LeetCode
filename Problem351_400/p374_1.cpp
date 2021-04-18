/**
 * @file p374_1.cpp
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


/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        long long rhs = 0;
        long long lhs = n;
        while(rhs <= n)
        {
            long mid = (rhs+lhs)/2;
            int res = guess(mid);
            if(res == 0)
            {
                return mid;
            }
            else if(res == -1)
            {
                lhs = mid-1;
            }
            else if(res == 1)
            {
                rhs = mid+1;
            }
        }
        return -1;
    }
};