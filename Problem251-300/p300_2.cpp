class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if(n < 2)
        {
            return n;
        }
        vector<int> dp(n+1, 1);
        dp[0] = 0;
        for(int i = 1; i <= n; ++i)
        {
            for(int j = 1; j < i; ++j)
            {
                if(nums[i-1] > nums[j-1])
                {
                    dp[i] = max(dp[i], dp[j]+1);
                }
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};