/**
 * @file p15_1.cpp
 * @brief 
 * @author dingqunfei (dqflying@gmail.com)
 * @version 1.0
 * @date 2021-05-10
 * 
 * @copyright Copyright (c) 2021 DQFLYING
 * 
 * @par :
 * 
 * 
 * Date        : 2021-05-10
 * Version     : 1.0
 * Author      : dqflying
 * Lisence     : 
 * Description : 
 * 
 * 
 * 
 * 
 */

//我的解法，会导致结果偏少
//解决重复元素，是最大问题

/*
class Solution {

public:
    template<typename T>
    inline void ListRemoveAt(vector<T>&list, size_t idx)
    {
        if (idx  < list.size())
            list[idx] = list.back();
        list.pop_back();
    }

    void twoSum(vector<int>& nums, int target, vector<vector<int>> &res) {
        unordered_map<int, int> lack_index_map;
        for(int i = 0; i < nums.size(); ++i)
        {
            if(lack_index_map.count(nums[i]))
            {
                res.push_back({nums[lack_index_map[nums[i]]], nums[i]});
            }
            else
            {
                lack_index_map[target-nums[i]] = i;
            }
        }
    }

    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> res;
        vector<int> nums_bak = nums;
        for(int i = 0; i < nums_bak.size(); ++i)
        {   
            int val = nums_bak[i];
            int new_target = -val;
            ListRemoveAt(nums_bak, i);
            vector<vector<int>> twoRes;
            twoSum(nums_bak, new_target, twoRes);
            for(int i = 0; i < twoRes.size(); ++i)
            {
                twoRes[i].push_back(val);
                sort(twoRes[i].begin(), twoRes[i].end());
                res.insert(twoRes[i]);
            }
        }
        vector<vector<int>> res_vec(res.begin(), res.end());
        return res_vec;
    }
};
*/


class Solution {

public:
    
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        int n = nums.size();
        if(n < 3)
        {
            return res;
        }
        sort(nums.begin(), nums.end());
        int last_element = INT_MAX;
        for(int i = 0; i < n; ++i)
        {
            if(nums[i] > 0)
            {
                break;
            }
            if(nums[i] == last_element)
            {
                continue;
            }
            int L = i+1, R = n-1;
            while(L < R)
            {
                int sum_three_elem = nums[i] + nums[L] + nums[R];
                if(sum_three_elem > 0)
                {
                    --R;
                }
                else if(sum_three_elem < 0)
                {
                    ++L;
                }
                else
                {
                    res.push_back({nums[i], nums[L], nums[R]});
                    while(L < R && nums[L] == nums[L+1])
                    {
                        ++L;
                    }
                    while(L < R && nums[R] == nums[R-1])
                    {
                        --R;
                    }
                    //为什么要++L --R
                    ++L;
                    --R;
                }
            }
            last_element = nums[i];
        }
        
        return res;
    }
};