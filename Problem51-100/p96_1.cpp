class Solution {
public:
    int numTrees(int n) {
        vector<vector<int>> memo(n+1, vector<int>(n+1, 0));
        count(memo, 1, n);
        return memo[1][n];
    }
    int count(vector<vector<int>>& memo, int lhs, int rhs)
    {
        if(lhs > rhs)
        {
            return 1;
        }
        if(memo[lhs][rhs] != 0)
        {
            return memo[lhs][rhs];
        }
        for(int i = lhs; i <= rhs; ++i)
        {
            int left = count(memo, lhs, i-1);
            int right = count(memo, i+1, rhs);
            memo[lhs][rhs] += left*right;
        }
        return memo[lhs][rhs];
    }
};