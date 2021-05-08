/**
 * @file p503_1.cpp
 * @brief 
 * @author dingqunfei (dqflying@gmail.com)
 * @version 1.0
 * @date 2021-05-08
 * 
 * @copyright Copyright (c) 2021 DQFLYING
 * 
 * @par :
 * 
 * 
 * Date        : 2021-05-08
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
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);
        stack<int> s;
        for(int i = n - 1; i >= 0; --i)
        {
            s.push(nums[i]);
        }
        for(int i = n - 1; i >= 0; --i)
        {
            while(!s.empty() && s.top() <= nums[i])
            {
                s.pop();
            }
            res[i] = (s.empty() ? -1 : s.top());
            s.push(nums[i]);
        }
        return res;
    }
};