/**
 * @file p121_1.cpp
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
    int maxProfit(vector<int>& prices) {
        int size = prices.size();
        if(size <= 1)
        {
            return 0;
        }
        int minPrice = prices[0], maxProfit = 0;
        for(int i = 1; i < size; ++i)
        {
            maxProfit = max(maxProfit, prices[i]-minPrice);
            minPrice = min(minPrice, prices[i]);
        }
        return maxProfit;
    }
};