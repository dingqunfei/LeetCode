/**
 * @file p1248_1.cpp
 * @brief 
 * @author dingqunfei (dqflying@gmail.com)
 * @version 1.0
 * @date 2021-05-29
 * 
 * @copyright Copyright (c) 2021 DQFLYING
 * 
 * @par :
 * 
 * 
 * Date        : 2021-05-29
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
    int numberOfSubarrays(vector<int>& nums, int k) {
        int size = nums.size();
        unordered_map<int, int> preOddFreq;
        int times = 0;
        int num = 0;
        preOddFreq[0] = 1;
        for(int i = 0; i < size; ++i)
        {
            times += nums[i]%2;
            if(preOddFreq.count(times-k))
            {
                num += preOddFreq[times-k];
            }
            ++preOddFreq[times];
        }
        return num;
    }
};