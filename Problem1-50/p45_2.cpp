/**
 * @file p45_2.cpp
 * @brief 
 * @author dingqunfei (dqflying@gmail.com)
 * @version 1.0
 * @date 2021-07-19
 * 
 * @copyright Copyright (c) 2021 DQFLYING
 * 
 * @par :
 * 
 * 
 * Date        : 2021-07-19
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
    int jump(vector<int>& nums) {

        int size = nums.size();
        if(size < 2)
        {
            return 0;
        }
        int step = 0;
        int index = 0;
        int distance = 0;
        while(index+nums[index] < size-1)
        {
            int start = index+1;
            int end = index+nums[index]+1;
            while(start < end)
            {
                if(start+nums[start] > distance)
                {
                    index = start;
                    distance = start+nums[start];
                }
                ++start;
            }
            
            ++step;
        }
        ++step;
        return step;
    }
};