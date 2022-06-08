//超时
class Solution {
public:
    int trap(vector<int>& height) {
        int res = 0;
        for(int i = 1; i < height.size()-1; ++i)
        {
            int left_max = 0, right_max = 0;
            for(int j = 0; j < i; ++j)
            {
                left_max = max(left_max, height[j]);
            }
            for(int j = i+1; j < height.size(); ++j)
            {
                right_max = max(right_max, height[j]);
            }
            int val = min(left_max, right_max) - height[i];
            if(val > 0)
            {
                res += val;
            }
        }
        return res;
    }
};