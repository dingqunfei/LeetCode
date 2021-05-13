/**
 * @file p875_1.cpp
 * @brief 
 * @author dingqunfei (dqflying@gmail.com)
 * @version 1.0
 * @date 2021-04-20
 * 
 * @copyright Copyright (c) 2021 DQFLYING
 * 
 * @par :
 * 
 * 
 * Date        : 2021-04-20
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
    int costTimes(vector<int> &piles, int speed)
    {   
        int cost_times = 0;
        for(int i = 0; i < piles.size(); ++i)
        {
            cost_times += piles[i]/speed;
            cost_times += (piles[i]%speed?1:0);
        }
        return cost_times;
    }

public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int size = piles.size(); //有size个堆，最快size个小时吃完
        int max_speed = *max_element(piles.cbegin(), piles.cend());
        if(h < size) //不可能吃完
        {
            return -1;
        }
        int lhs = 1, rhs = max_speed; //最小速度、最大速度
        while(lhs < rhs)
        {
            int mid = (lhs+rhs)/2;
            int using_time = costTimes(piles, mid);
            if(using_time == h)
            {
                rhs = mid;
            }
            else if(using_time > h)
            {
                lhs = mid+1;
            }
            else if(using_time < h)
            {
                rhs = mid;
            }
        }
        return rhs;

    }
};