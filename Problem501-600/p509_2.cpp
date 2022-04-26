class Solution {
public:
    int helper(vector<int>& dp, int n)
    {
        if(n == 0)
        {
            dp[n] = 0;
            return 0;
        }
        if(n == 1)
        {
            dp[n] = 1;
            return 1;
        }
        if(dp[n] != 0)
        {
            return dp[n];
        }
        return helper(dp, n-1) + helper(dp, n-2);
    }
    int fib(int n) {
        vector<int> dp(n+1, 0);
        return helper(dp, n);
    }
};