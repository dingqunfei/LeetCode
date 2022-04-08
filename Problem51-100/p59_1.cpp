class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n, 0));

        int left = 0, right = n-1, top = 0, bottom = n-1;
        int val = 1;
        while(val <= n*n)
        {
            if(top <= bottom)
            {
                for(int i = left; i <= right; ++i)
                {
                    matrix[top][i] = val;
                    ++val;
                }
                ++top;
            }
            if(right >= left)
            {
                for(int i = top; i <= bottom; ++i)
                {
                    matrix[i][right] = val;
                    ++val;
                }
                --right;
            }
            if(bottom >= top)
            {
                for(int i = right; i >= left; --i)
                {
                    matrix[bottom][i] = val;
                    ++val;
                }
                --bottom;
            }
            if(left <= right)
            {
                for(int i = bottom; i >= top; --i)
                {
                    matrix[i][left] = val;
                    ++val;
                }
                ++left;
            }
        }
        return matrix;

    }
};