/**
 * @file p322_1.cpp
 * @brief 
 * @author dingqunfei (dqflying@gmail.com)
 * @version 1.0
 * @date 2021-06-04
 * 
 * @copyright Copyright (c) 2021 DQFLYING
 * 
 * @par :
 * 
 * 
 * Date        : 2021-06-04
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
    int coinChange(vector<int>& coins, int amount) {
        vector<int> res(amount+1, -1);
        res[0] = 0; 
        for(int i = 1; i <= amount; ++i)
        {
            int times = INT_MAX;
            for(auto j: coins)
            {
                if(i-j >= 0 && res[i-j] >= 0)
                {
                    times = min(times, res[i-j]+1);
                    res[i] = times;
                }
            }
        }
        return res[amount];
    }
};