/**
 * @file p6_1.cpp
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
将每排字符放到第(numRows-1)个字符串中，遍历s字符串，正序时添加到0->(numRows-1)个字符串
逆序时添加到(numRows-1)->0个字符串中，使用isForward控制第index个字符串
*/

/*
Result:
Runtime: 28 ms, faster than 46.82% of C++ online submissions for ZigZag Conversion.
Memory Usage: 10.3 MB, less than 77.78% of C++ online submissions for ZigZag Conversion.
*/

class Solution {
public:
    string convert(string s, int numRows) {
        if(numsRows == 1)
        {
            return s;
        }
        vector<string> strVec(numRows, "");
        int index = 0, isForward = 1;
        for(int i = 0; i < s.size(); ++i)
        {
            strVec[index].push_back(s[i]);
            if(index == 0)
            {
                isForward = 1;
            }
            if(index == numRows-1)
            {
                isForward = -1;
            }
            /*
            if(numRows == 1)
            {
                isForward = 0;
            }
            */
            index += isForward;
        }
        string res = "";
        for(int i = 0; i < numRows; ++i)
        {
            res += strVec[i];
        }
        return res;
    }
};