/**
 * @file p1024_1.cpp
 * @brief 
 * @author dingqunfei (dqflying@gmail.com)
 * @version 1.0
 * @date 2021-07-26
 * 
 * @copyright Copyright (c) 2021 DQFLYING
 * 
 * @par :
 * 
 * 
 * Date        : 2021-07-26
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
    int videoStitching(vector<vector<int>>& clips, int time) {
        int size = clips.size();
        int length = time+1;
        vector<int> distance(length, 0);
        for(int i = 0; i < size; ++i)
        {
            int start = clips[i][0];
            int end = clips[i][1];
            if(start < length && end-start > distance[start])
            {
                distance[start] = end-start;
            }
        }
        int end = 0, farthest = 0;
        int jumps = 0;
        for(int i = 0; i < length-1; ++i)
        {
            farthest = max(farthest, i+distance[i]);
            if(farthest == i)
            {
                return -1;
            }
            if(end == i)
            {
                ++jumps;
                end = farthest;
            }
        }

        return jumps;
    }
};