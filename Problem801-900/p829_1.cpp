/**
 * @file p829_1.cpp
 * @brief 
 * @author dingqunfei (dqflying@gmail.com)
 * @version 1.0
 * @date 2021-04-07
 * 
 * @copyright Copyright (c) 2021 DQFLYING
 * 
 * @par :
 * 
 * 
 * Date        : 2021-04-07
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
    int consecutiveNumbersSum(int N) {
        int count = 0;
        long long max_value = N;
        long long max_range = sqrt(2 * N) + 10;
        for(long long i = 1; i <= max_range; ++i)
        {
            long long diff = (i*i-i)/2;
            if (((max_value-diff) >= i) && (((max_value-diff)%i) == 0))
            {
                ++count;
            }
        }
        return count;

    }
};