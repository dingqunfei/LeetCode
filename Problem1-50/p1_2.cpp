/**
 * @file p1_2.cpp
 * @brief 
 * @author dqflying (dqflying@gmail.com)
 * @version 1.0
 * @date 2020-05-13
 * 
 * @copyright Copyright (c) 2020  DQFLYING.INC
 * 
 * @par 新增文件:
 * <table>
 * <tr><th>Date            <th>Version      <th>Author       <th>Description
 * <tr><td>2020-05-13      <td>1.0          <td>dqflying     <td>内容
 * </table>
 */

/*
Description:
1. Two Sum

Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:

Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
*/

/*
Solution:
使用map构成值-索引对，在map中寻找target-nums[i]的值，找到就返回其索引，否则将当前值-索引对
加入到map中。同时，已经在map中的索引必然小于i，故而i在后。
*/

/*
Result:
Runtime: 12 ms, faster than 78.85% of C++ online submissions for Two Sum.
Memory Usage: 10 MB, less than 56.40% of C++ online submissions for Two Sum.
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> valueIndex;
        int len = nums.size();
        for(int i = 0; i < len; ++i)
        {
            int value = nums[i];
            if(valueIndex.count(target-value))
            {
                return {valueIndex[target-value], i};
            }
            else
            {
                valueIndex.insert({value, i});
            }
        }
        return vector<int>();
        
    }
};