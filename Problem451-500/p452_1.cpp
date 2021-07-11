/**
 * @file p452_1.cpp
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
    int findMinArrowShots(vector<vector<int>>& points) {
        int size = points.size();
        if(size < 2)
        {
            return size;
        }
        sort(points.begin(), points.end(), [](auto &a, auto &b){return a[1] < b[1];});
        int shots = 1;
        int start = points[0][1];
        for(int i = 1; i < size; ++i)
        {
            if(points[i][0] > start)
            {
                ++shots;
                start = points[i][1];
            }
        }
        return shots;
    }
};