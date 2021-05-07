/**
 * @file p496_1.cpp
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
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> valueAndGreater;
        stack<int> s;
        vector<int> res;
        for(int i = nums2.size()-1; i >=0; --i)
        {
            while(!s.empty() && s.top() <= nums2[i])
            {
                s.pop();
            }
            int ans = (s.empty()?-1:s.top());
            valueAndGreater.insert({nums2[i], ans});
            s.push(nums2[i]);
        }
        for(int i = 0; i < nums1.size(); ++i)
        {
            res.push_back(valueAndGreater[nums1[i]]);
        }
        return res;
    }
};