/**
 * @file p1_3.cpp
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
这个解法想到过，但是觉得排序也占时间，没有实现，结果是高效的算法-_-||。
这个解法实际上是将所有元素从小到大排序，然后从左右向中间逼近，比较左+右与target值的大小，
若是小则左侧索引增加，若是大则右则索引增加。
此外，需要使用额外的结构保存值-索引对。
*/

/*
Result:
Runtime: 16 ms, faster than 57.86% of C++ online submissions for Two Sum.
Memory Usage: 9.3 MB, less than 74.93% of C++ online submissions for Two Sum..
*/