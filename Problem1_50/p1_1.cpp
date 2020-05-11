/**
 * @file p1_1.cpp
 * @brief 
 * @author dqflying (dqflying@gmail.com)
 * @version 1.0
 * @date 2020-05-12
 * 
 * @copyright Copyright (c) 2020  DQFLYING.INC
 * 
 * @par 新增文件:
 * <table>
 * <tr><th>Date            <th>Version      <th>Author       <th>Description
 * <tr><td>2020-05-12      <td>1.0          <td>dqflying     <td>内容
 * </table>
 */

/*
*暴力解法
*Runtime: 556 ms, faster than 20.87% of C++ online submissions for Two Sum.
*Memory Usage: 9.1 MB, less than 100.00% of C++ online submissions for Two Sum.
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int len = nums.size();
        vector<int> res;
        for(int i = 0; i < len-1; ++i)
        {
            for(int j = i+1; j < len; ++j)
            {
                if(nums[i] + nums[j] == target)
                {
                    res.push_back(i);
                    res.push_back(j);
                    break;
                }
            }
        }
        return res;
    }
};