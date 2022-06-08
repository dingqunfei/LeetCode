class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int res = 0;
        vector<int> left_max(n, 0);
        vector<int> right_max(n, 0);
        int left = 0;
        for(int i = 0; i < n-1; ++i)
        {
            left = max(left, height[i]);
            left_max[i+1] = left;
        }
        int right = 0;
        for(int i = n-1; i > 0; --i)
        {
            right = max(right, height[i]);
            right_max[i-1] = right;
        }
        for(int i = 1; i < n-1; ++i)
        {
            int val = min(left_max[i], right_max[i]) - height[i];
            if(val > 0)
            {
                res += val;
            }
        }
        
        return res;
    }
};