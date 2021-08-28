/**
 * @file p384_1.cpp
 * @brief 
 * @author dingqunfei (dqflying@gmail.com)
 * @version 1.0
 * @date 2021-08-29
 * 
 * @copyright Copyright (c) 2021 DQFLYING
 * 
 * @par :
 * 
 * 
 * Date        : 2021-08-29
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
    Solution(vector<int>& nums) {
        Elements = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return Elements;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> Shuffles = Elements;
        for(int i = 1; i < Shuffles.size(); ++i)
        {
            int change = rand()%(i+1);
            if(change != i)
            {
                swap(Shuffles[change], Shuffles[i]);
            }
        }
        return Shuffles;
    }
public:
    vector<int> Elements;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */