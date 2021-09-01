/**
 * @file p56_2.cpp
 * @brief 
 * @author dingqunfei (dqflying@gmail.com)
 * @version 1.0
 * @date 2021-09-02
 * 
 * @copyright Copyright (c) 2021 DQFLYING
 * 
 * @par :
 * 
 * 
 * Date        : 2021-09-02
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
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int size = intervals.size();
        if(size < 2)
        {
            return intervals;
        }
        vector<vector<int>> ans;
        vector<int> starts, ends;
        for(int i = 0; i < size; ++i)
        {
            starts.push_back(intervals[i][0]);
            ends.push_back(intervals[i][1]);
        }
        sort(starts.begin(), starts.end());
        sort(ends.begin(), ends.end());

        for(int i = 0, j = 0; i < size; ++i)
        {
            if(i == size-1 || starts[i+1] > ends[i])
            {
                ans.push_back({starts[j], ends[i]});
                j = i+1;
            }
        }
        
        return ans;
    }
};