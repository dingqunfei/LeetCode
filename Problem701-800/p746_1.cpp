/**
 * @file p746_1.cpp
 * @brief 
 * @author dingqunfei (dqflying@gmail.com)
 * @version 1.0
 * @date 2021-09-14
 * 
 * @copyright Copyright (c) 2021 DQFLYING
 * 
 * @par :
 * 
 * 
 * Date        : 2021-09-14
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
    int minCostClimbingStairs(vector<int>& cost) {
        int size = cost.size();
        if(size < 2)
        {
            return 0;
        }
        cost.push_back(0);
        int forwardOne = cost[0], forwardTwo = cost[1], cur = 0;
        for(int i = 2; i <= size; ++i)
        {
            cur = min(forwardOne, forwardTwo)+cost[i];
            forwardOne = forwardTwo;
            forwardTwo = cur;
        }
        return cur;
    }
};