/**
 * @file p11_1.cpp
 * @brief 
 * @author dqflying (dqflying@gmail.com)
 * @version 1.0
 * @date 2020-05-26
 * 
 * @copyright Copyright (c) 2020  DQFLYING.INC
 * 
 * @par 新增文件:
 * 
 * 
 * Date              Version        Author         LISENCE
 * 2020-05-26        1.0            dqflying       XXXXXXX
 * Description:
 * 
 * 
 */


/*
Description:
11. Container With Most Water
Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container and n is at least 2.

Example:
Input: [1,8,6,2,5,4,8,3,7]
Output: 49
*/

/*
Solution:
https://leetcode.com/problems/container-with-most-water/discuss/6099/Yet-another-way-to-see-what-happens-in-the-O(n)-algorithm
*/

/*
Result:
Runtime: 32 ms, faster than 40.99% of C++ online submissions for Container With Most Water.
Memory Usage: 14.4 MB, less than 5.15% of C++ online submissions for Container With Most Water.
*/

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size()-1;
        int area = min(height[left], height[right]) * (right-left);
        while(left < right)
        {
            if(height[left]<height[right])
            {
                ++left;
            }
            else
            {
                --right;
            }
            area = max(area, min(height[left], height[right]) * (right-left));
        }
        return area;
    }
};