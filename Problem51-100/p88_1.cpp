/**
 * @file p88_1.cpp
 * @brief 
 * @author dingqunfei (dqflying@gmail.com)
 * @version 1.0
 * @date 2021-08-27
 * 
 * @copyright Copyright (c) 2021 DQFLYING
 * 
 * @par :
 * 
 * 
 * Date        : 2021-08-27
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
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int len = m+n-1;
        int l=m-1, r=n-1;
        while(l > -1 && r > -1)
        {
            if(nums1[l] > nums2[r])
            {
                nums1[len] = nums1[l];
                --l;
                --len;
            }
            else
            {
                nums1[len] = nums2[r];
                --r;
                --len;
            }
        }
        while(r > -1)
        {
            nums1[len] = nums2[r];
            --len;
            --r;
        }
    }
};