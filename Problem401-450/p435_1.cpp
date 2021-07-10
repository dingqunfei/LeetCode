/**
 * @file p435_1.cpp
 * @brief 
 * @author dingqunfei (dqflying@gmail.com)
 * @version 1.0
 * @date 2021-07-11
 * 
 * @copyright Copyright (c) 2021 DQFLYING
 * 
 * @par :
 * 
 * 
 * Date        : 2021-07-11
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
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int size = intervals.size();
        if(size < 2)
        {
            return 0;
        }
        sort(intervals.begin(), intervals.end(), [](vector<int> &a, vector<int> &b){return a[1] < b[1];});
        int count = 1;
        vector<int> &start = intervals[0];
        for(int i = 1; i < size; ++i)
        {
            if(intervals[i][0] >= start[1])
            {
                ++count;
                start = intervals[i];
            }
        }
        return size-count;
    }
};