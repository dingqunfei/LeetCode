/**
 * @file p56_1.cpp
 * @brief 
 * @author dingqunfei (dqflying@gmail.com)
 * @version 1.0
 * @date 2021-09-01
 * 
 * @copyright Copyright (c) 2021 DQFLYING
 * 
 * @par :
 * 
 * 
 * Date        : 2021-09-01
 * Version     : 1.0
 * Author      : dqflying
 * Lisence     : 
 * Description : 
 * 
 * 
 * 
 * 
 */



//超出时间限制
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int> a, vector<int> b){return a[0]<b[0];});
        int size = intervals.size();
        if(size < 2)
        {
            return intervals;
        }
        int i = 0;
        while(i < size-1)
        {
            if(intervals[i][1] >= intervals[i+1][0])
            {
                intervals.insert(intervals.begin()+i, vector<int>{intervals[i][0], max(intervals[i][1],intervals[i+1][1])});
                intervals.erase(intervals.begin()+i+1, intervals.begin()+i+3);
                size -= 1;
            }
            else
            {
                ++i;
            }
        }
        return intervals;
    }
};