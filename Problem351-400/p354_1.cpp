/**
 * @file p354_1.cpp
 * @brief 
 * @author dingqunfei (dqflying@gmail.com)
 * @version 1.0
 * @date 2021-06-09
 * 
 * @copyright Copyright (c) 2021 DQFLYING
 * 
 * @par :
 * 
 * 
 * Date        : 2021-06-09
 * Version     : 1.0
 * Author      : dqflying
 * Lisence     : 
 * Description : 
 * 
 * 
 * 
 * 
 */

//此方法行不通
//[[2,100],[3,200],[4,300],[5,500],[5,400],[5,250],[6,370],[6,360],[7,380]]
//考虑此数组，第一次遍历中，前面的数组已经被标记，但是实际后面的数组还要使用
//彼此一起才构成最优解
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), [](auto &a, auto &b){return a[0]<b[0];});
        int count = 0, start = 0;
        int len = envelopes.size();
        vector<bool> label(len, false);
        while(start < len)
        {
            while(label[start])
            {
                ++start;
            }
            int new_start = start;
            int curr_count = 0;
            int first = 0;
            int second = 0;
            while(new_start < len)
            {
                if(envelopes[new_start][1] > second && envelopes[new_start][0] > first)
                //if(envelopes[new_start][1] > second)
                {
                    label[new_start] = true;
                    second = envelopes[new_start][1];
                    first = envelopes[new_start][0];
                    ++curr_count;
                }
                ++new_start;
            }
            if(curr_count > count)
            {
                count = curr_count;
            }
        }
        return count;
    }
};