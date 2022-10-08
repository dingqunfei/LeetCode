class Solution {
public:
    int min(int a, int b, int c)
    {
        return std::min(a, std::min(b, c));
    }
    int dp(string &s1, int i, string &s2, int j, vector<vector<int>> &memo)
    {
        if(i == -1)
        {
            return j+1;
        }
        if(j == -1)
        {
            return i+1;
        }
        if(memo[i][j] != -1)
        {
            return memo[i][j];
        }
        if(s1[i] == s2[j])
        {
            memo[i][j] = dp(s1, i-1, s2, j-1, memo);
        }
        else
        {
            memo[i][j] = min(dp(s1, i-1, s2, j, memo)+1, dp(s1, i, s2, j-1, memo)+1, dp(s1, i-1, s2, j-1, memo)+1);
        }
        return memo[i][j];
    }

    int minDistance(string word1, string word2) {
        vector<vector<int>> memo(word1.size(), vector<int>(word2.size(), -1));
        return dp(word1, word1.size()-1, word2, word2.size()-1, memo);
    }
};