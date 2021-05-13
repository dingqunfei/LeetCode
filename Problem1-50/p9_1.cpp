/**
 * @file p9_1.cpp
 * @brief 
 * @author dqflying (dqflying@gmail.com)
 * @version 1.0
 * @date 2020-05-25
 * 
 * @copyright Copyright (c) 2020  DQFLYING.INC
 * 
 * @par 新增文件:
 * 
 * 
 * Date              Version        Author         LISENCE
 * 2020-05-25        1.0            dqflying       XXXXXXX
 * Description:
 * 
 * 
 */


/*
Description:
9. Palindrome Number
Determine whether an integer is a palindrome. An integer is a palindrome when it reads the same backward as forward.

Example 1:
Input: 121
Output: true

Example 2:
Input: -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.

Example 3:
Input: 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.

Follow up:
Coud you solve it without converting the integer to a string?
*/

/*
Solution:
回文数逆序后，值与原数相等
*/

/*
Result:
Runtime: 12 ms, faster than 74.22% of C++ online submissions for Palindrome Number.
Memory Usage: 5.8 MB, less than 100.00% of C++ online submissions for Palindrome Number.
*/

class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0)
        {
            return false;
        }
        int temp = x;
        long long reserveX = 0;
        while(temp > 0)
        {
            int carry = temp % 10;
            temp /= 10;
            reserveX = reserveX * 10 + carry;
        }
        return (reserveX==x)?true:false;
    }
};