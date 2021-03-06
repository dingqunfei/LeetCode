/**
 * @file p1248_2.cpp
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
        int n = (int)nums.size();
        vector<int> cnt(n+1, 0);
        int odd = 0, ans = 0;
        cnt[0] = 1;
        for (int i = 0; i < n; ++i) {
            odd += nums[i] & 1;
            ans += odd >= k ? cnt[odd - k] : 0;
            cnt[odd] += 1;
        }
        return ans;
    }
};




//my version
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int size = nums.size();
        vector<int> preOddFreq(size+1, 0);
        int times = 0;
        int num = 0;
        preOddFreq[0] = 1;
        for(int i = 0; i < size; ++i)
        {
            times += nums[i]%2;
            if(times-k > -1)
            {
                num += preOddFreq[times-k];
            }
            ++preOddFreq[times];
        }
        return num;
    }
};