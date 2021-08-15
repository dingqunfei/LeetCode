/**
 * @file p350_1.cpp
 * @brief 
 * @author dingqunfei (dqflying@gmail.com)
 * @version 1.0
 * @date 2021-08-16
 * 
 * @copyright Copyright (c) 2021 DQFLYING
 * 
 * @par :
 * 
 * 
 * Date        : 2021-08-16
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
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        vector<int> ans;
        int fast = 0, slow = 0;
        while(fast < nums1.size() && slow < nums2.size())
        {
            if(nums1[fast] == nums2[slow])
            {
                ans.push_back(nums1[fast]);
                ++fast;
                ++slow;
            }
            else if(nums1[fast] < nums2[slow])
            {
                ++fast;
            }
            else
            {
                ++slow;
            }
        }
        return ans;
    }
};