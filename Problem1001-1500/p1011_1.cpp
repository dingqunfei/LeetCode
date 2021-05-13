/**
 * @file p1011_1.cpp
 * @brief 
 * @author dingqunfei (dqflying@gmail.com)
 * @version 1.0
 * @date 2021-04-21
 * 
 * @copyright Copyright (c) 2021 DQFLYING
 * 
 * @par :
 * 
 * 
 * Date        : 2021-04-21
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
    int using_days(vector<int> &weights, int payload)
    {
        int days = 0;
        int size = weights.size();
        int curr_payload = 0;
        for(int i = 0; i < size; ++i)
        {
            if(weights[i] + curr_payload <= payload)
            {
                curr_payload += weights[i];
            }
            else
            {
                curr_payload = weights[i];  //特别注意此处，不是curr_payload = 0;
                days += 1;
            }
        }
        if(curr_payload > 0)
        {
            days += 1;
        }
        return days;
    }

public:
    int shipWithinDays(vector<int>& weights, int D) {
        //最大运载能力，一天运输所有
        //最小运载能力，一天只能运输一个包裹，那么最小运载能力就是最大包裹的重量
        int max_payload = 0;
        for(auto iter = weights.cbegin(); iter != weights.cend(); ++iter)
        {
            max_payload += *iter;
        }
        int min_payload = *max_element(weights.cbegin(), weights.cend());

        int lhs = min_payload, rhs = max_payload;
        while(lhs < rhs)
        {
            int mid = (lhs + rhs)/2;
            int days = using_days(weights, mid);
            if(days > D)
            {
                lhs = mid + 1;
            }
            else if(days <= D)
            {
                rhs = mid;
            }
        }

        return lhs;
    }
};