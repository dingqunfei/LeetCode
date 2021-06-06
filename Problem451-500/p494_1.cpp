/**
 * @file p494_1.cpp
 * @brief 
 * @author dingqunfei (dqflying@gmail.com)
 * @version 1.0
 * @date 2021-06-06
 * 
 * @copyright Copyright (c) 2021 DQFLYING
 * 
 * @par :
 * 
 * 
 * Date        : 2021-06-06
 * Version     : 1.0
 * Author      : dqflying
 * Lisence     : 
 * Description : 
 * 
 * 
 * 
 * 
 */


//接近超时的算法，未超时
class Solution {
private:
    int count;
    void backtrack(vector<int> &nums, int track, int start, int target)
    {
        if((start == nums.size()) && (track == target))
        {
            count += 1;
            return;
        }
        if(start == nums.size())
        {
            return;
        }
        backtrack(nums, track+nums[start], start+1, target);
        backtrack(nums, track-nums[start], start+1, target);
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        count = 0;
        int track = 0;
        backtrack(nums, track, 0, target);
        return count;
    }
};



//超时算法
class Solution {
private:
    int count;
    void backtrack(vector<int> &nums, int start, int rest)
    {
        if(start == nums.size())
        {
            if(rest == 0)
            {
                count += 1;
            }
            return;
        }
        
        rest += nums[start];
        backtrack(nums, start+1, rest);
        rest -= nums[start];

        rest -= nums[start];
        backtrack(nums, start+1, rest);
        rest += nums[start];
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        count = 0;
        backtrack(nums, 0, target);
        return count;
    }
};