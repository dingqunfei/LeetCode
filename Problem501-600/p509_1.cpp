/**
 * @file p509_1.cpp
 * @brief 
 * @author dingqunfei (dqflying@gmail.com)
 * @version 1.0
 * @date 2021-06-03
 * 
 * @copyright Copyright (c) 2021 DQFLYING
 * 
 * @par :
 * 
 * 
 * Date        : 2021-06-03
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
    int fib(int n) {
        vector<int> dp_table(n+2, 0);
        dp_table[1] = 1;
        for(int i = 2; i <= n; ++i)
        {
            dp_table[i] = dp_table[i-1]+dp_table[i-2];
        }
        return dp_table[n];
    }
};