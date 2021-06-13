/**
 * @file p1143_1.cpp
 * @brief 
 * @author dingqunfei (dqflying@gmail.com)
 * @version 1.0
 * @date 2021-06-13
 * 
 * @copyright Copyright (c) 2021 DQFLYING
 * 
 * @par :
 * 
 * 
 * Date        : 2021-06-13
 * Version     : 1.0
 * Author      : dqflying
 * Lisence     : 
 * Description : 
 * 
 * 
 * 
 * 
 */


//超时，使用备忘录优化
class Solution {

public:
    int longestCommonSubsequence(string text1, string text2) {
        return dp(text1, 0, text2, 0);
    }

private:

    int dp(string &text1, int len1, string &text2, int len2)
    {
        if(len1 == text1.size() || len2 == text2.size())
        {
            return 0;
        }
        if(text1[len1] == text2[len2])
        {
            return 1+dp(text1, len1+1, text2, len2+1);
        }
        else
        {
            return max(dp(text1, len1+1, text2, len2), dp(text1, len1, text2, len2+1));
        }
        return 0;
    }
};



//解决超时
class Solution {

public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size(), n = text2.size();
        vector<vector<int>> memo(m, vector<int>(n, -1));
        return dp(text1, 0, text2, 0, memo);
    }

private:

    int dp(string &text1, int len1, string &text2, int len2, vector<vector<int>> &memo)
    {
        if(len1 == text1.size() || len2 == text2.size())
        {
            return 0;
        }
        if(memo[len1][len2] != -1)
        {
            return memo[len1][len2];
        }
        if(text1[len1] == text2[len2])
        {
            memo[len1][len2] = 1+dp(text1, len1+1, text2, len2+1, memo);
        }
        else
        {
            memo[len1][len2] = max(dp(text1, len1+1, text2, len2, memo), 
            dp(text1, len1, text2, len2+1, memo));
        }
        return memo[len1][len2];
    }
};