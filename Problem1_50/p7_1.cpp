/**
 * @file p7_1.cpp
 * @brief 
 * @author dqflying (dqflying@gmail.com)
 * @version 1.0
 * @date 2020-05-24
 * 
 * @copyright Copyright (c) 2020  DQFLYING.INC
 * 
 * @par 新增文件:
 * 
 * 
 * Date              Version        Author         LISENCE
 * 2020-05-24        1.0            dqflying       XXXXXXX
 * Description:
 * 
 * 
 */


/*
Description:
7. Reverse Integer
Given a 32-bit signed integer, reverse digits of an integer.

Example 1:
Input: 123
Output: 321

Example 2:
Input: -123
Output: -321

Example 3:
Input: 120
Output: 21
Note:
Assume we are dealing with an environment which could only store integers 
within the 32-bit signed integer range: [−231,  231 − 1]. For the purpose of this problem,
 assume that your function returns 0 when the reversed integer overflows.
*/

/*
Solution:
******
*/

/*
Result:
Runtime: 4 ms, faster than 47.92% of C++ online submissions for Reverse Integer.
Memory Usage: 5.8 MB, less than 100.00% of C++ online submissions for Reverse Integer.
*/

class Solution {
public:
    int reverse(int x) {

        long long res = 0;
        while(x) {
            res = res*10 + x%10;
            x /= 10;
        }
        return (res<INT_MIN || res>INT_MAX) ? 0 : res;
    }
};