/**
 * @file 122_1.cpp
 * @brief 
 * @author dingqunfei (dqflying@gmail.com)
 * @version 1.0
 * @date 2021-08-13
 * 
 * @copyright Copyright (c) 2021 DQFLYING
 * 
 * @par :
 * 
 * 
 * Date        : 2021-08-13
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
        if(size < 2)
        {
            return 0;
        }
        int profit = 0;
        int buy = 0, sale = 1;
        while(buy < sale && sale < size)
        {
            if(prices[buy] < prices[sale])
            {
                profit += prices[sale]-prices[buy];
            }
            ++buy;
            ++sale;
        }
        return profit;
    }
};