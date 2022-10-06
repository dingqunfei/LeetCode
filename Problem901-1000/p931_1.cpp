class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        dp[0] = matrix[0];

        vector<vector<int>> adj = {{-1, -1}, {-1, 0}, {-1, 1}};
        for(int i = 1; i < n; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                int value = INT_MAX;
                for(auto item: adj)
                {
                    if(j + item[1] >= 0 && j + item[1] < n)
                    {
                        value = min(value, dp[i+item[0]][j+item[1]] + matrix[i][j]);
                    }
                }
                dp[i][j] = value;
            }
        }

        return *min_element(dp[n-1].begin(), dp[n-1].end());
    }
};