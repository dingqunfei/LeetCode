class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int m = matrix.size();
        int n = matrix[0].size();
        if(n == 0)
        {
            return res;
        }
        int left = 0, right = n-1, top = 0, bottom = m-1;
        
        while(res.size() < m*n)
        {
            if(top <= bottom)
            {
                for(int i = left; i <= right; ++i)
                {
                    res.push_back(matrix[top][i]);
                }
                ++top;
            }
            if(right >= left)
            {
                for(int i = top; i <= bottom; ++i)
                {
                    res.push_back(matrix[i][right]);
                }
                --right;
            }
            if(bottom >= top)
            {
                for(int i = right; i >= left; --i)
                {
                    res.push_back(matrix[bottom][i]);
                }
                --bottom;
            }
            if(left <= right)
            {
                for(int i = bottom; i >= top; --i)
                {
                    res.push_back(matrix[i][left]);
                }
                ++left;
            }
        }
        return res;
    }
};