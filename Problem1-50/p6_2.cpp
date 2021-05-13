/**
 * @file p6_2.cpp
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
6. ZigZag Conversion
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)
P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number of rows:
string convert(string s, int numRows);

Example 1:
Input: s = "PAYPALISHIRING", numRows = 3
Output: "PAHNAPLSIIGYIR"

Example 2:
Input: s = "PAYPALISHIRING", numRows = 4
Output: "PINALSIGYAHRPI"
Explanation:
P     I    N
A   L S  I G
Y A   H R
P     I
*/

/*
Solution:
******
*/

/*
Result:
Runtime: 12 ms, faster than 93.93% of C++ online submissions for ZigZag Conversion.
Memory Usage: 7.8 MB, less than 100.00% of C++ online submissions for ZigZag Conversion.
*/

class Solution {
public:
    string convert(string s, int numRows) {
        if(1 == numRows) return s;
        int d = (numRows - 1) << 1;
        int count = 0;
        string ret(s.size(), '0');
        int step = d;
        int beginI = 0;
        
        while(step >= 0)
        {
            int index = beginI;
            while(index < s.size())
            {
                if(step > 0)
                {
                    ret[count++] = s[index];
                    index += step;
                }
                
                if(step < d && index < s.size())
                {
                    ret[count++] = s[index];
                    index += (d - step);
                }
            }
            beginI++;
            step -= 2;
        }

        return ret;
    }
};