/**
 * @file p12_1.cpp
 * @brief 
 * @author dqflying (dqflying@gmail.com)
 * @version 1.0
 * @date 2020-05-27
 * 
 * @copyright Copyright (c) 2020  DQFLYING.INC
 * 
 * @par 新增文件:
 * 
 * 
 * Date              Version        Author         LISENCE
 * 2020-05-27        1.0            dqflying       XXXXXXX
 * Description:
 * 
 * 
 */


/*
Description:
12. Integer to Roman
Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
For example, two is written as II in Roman numeral, just two one's added together. 
Twelve is written as, XII, which is simply X + II. The number twenty seven is written as XXVII, which is XX + V + II.

Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. 
Instead, the number four is written as IV. Because the one is before the five we subtract it making four. 
The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:

I can be placed before V (5) and X (10) to make 4 and 9. 
X can be placed before L (50) and C (100) to make 40 and 90. 
C can be placed before D (500) and M (1000) to make 400 and 900.
Given an integer, convert it to a roman numeral. Input is guaranteed to be within the range from 1 to 3999.

Example 1:
Input: 3
Output: "III"

Example 2:
Input: 4
Output: "IV"

Example 3:
Input: 9
Output: "IX"

Example 4:
Input: 58
Output: "LVIII"
Explanation: L = 50, V = 5, III = 3.

Example 5:
Input: 1994
Output: "MCMXCIV"
Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
*/

/*
Solution:
******
*/

/*
Result:
Runtime: 8 ms, faster than 86.03% of C++ online submissions for Integer to Roman.
Memory Usage: 6.1 MB, less than 100.00% of C++ online submissions for Integer to Roman.
*/

class Solution {
public:
    string intToRoman(int n) {
        string returnval="";
        while(n/1000){
            returnval+='M';
            n-=1000;
        }
        while(n/900){
            returnval+='C';
            returnval+='M';
            n-=900;
        }
        while(n/500){
            returnval+='D';
            n-=500;
        }
        while(n/400){
            returnval+='C';
            returnval+='D';
            n-=400;
        }
        while(n/100){
            returnval+='C';
            n-=100;
        }
        while(n/90){
            returnval+='X';
            returnval+='C';
            n-=90;
        }
        while(n/50){
            returnval+='L';
            n-=50;
        }
        while(n/40){
            returnval+='X';
            returnval+='L';
            n-=40;
        }
        while(n/10){
            returnval+='X';
            n-=10;
        }
        while(n/9){
            returnval+='I';
            returnval+='X';
            n-=9;
        }
        while(n/5){
            returnval+='V';
            n-=5;
        }
        while(n/4){
            returnval+='I';
            returnval+='V';
            n-=4;
        }
        while(n){
            returnval+='I';
            n--;
        }
        return returnval;
    }
};


class Solution {
public:
    string intToRoman(int num) {
        string res;
        string sym[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        int val[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        
        for(int i=0; num != 0; i++)
        {
            while(num >= val[i])
            {
                num -= val[i];
                res += sym[i];
            }
        }
        
        return res;
    }
};


