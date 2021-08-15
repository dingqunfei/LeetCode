/**
 * @file p349_1.cpp
 * @brief 
 * @author dingqunfei (dqflying@gmail.com)
 * @version 1.0
 * @date 2021-08-15
 * 
 * @copyright Copyright (c) 2021 DQFLYING
 * 
 * @par :
 * 
 * 
 * Date        : 2021-08-15
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
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> numSet(nums1.begin(), nums1.end());
        set<int> ans;
        for(int i = 0; i < nums2.size(); ++i)
        {
            if(numSet.count(nums2[i]))
            {
                ans.insert(nums2[i]);
            }
        }
        return vector<int>(ans.begin(), ans.end());
    }
};