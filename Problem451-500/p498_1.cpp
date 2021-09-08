/**
 * @file p498_1.cpp
 * @brief 
 * @author dingqunfei (dqflying@gmail.com)
 * @version 1.0
 * @date 2021-09-09
 * 
 * @copyright Copyright (c) 2021 DQFLYING
 * 
 * @par :
 * 
 * 
 * Date        : 2021-09-09
 * Version     : 1.0
 * Author      : dqflying
 * Lisence     : 
 * Description : 
 * 
 * 
 * 
 * 
 */


class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int row = mat.size();
        if(row == 0)
        {
            return vector<int>();
        }
        int col = mat[0].size();
        vector<int> rlt(col*row, 0);
        int r = 0, c = 0;
        for(int i = 0; i < col*row; ++i)
        {
            rlt[i] = mat[r][c];
            if((r+c)%2 == 0)
            {
                if(c == col-1)
                {
                    r++;
                }
                else if(r == 0)
                {
                    c++;
                }
                else
                {
                    r--;
                    c++;
                }
            }
            else
            {
                if(r == row-1)
                {
                    c++;
                }
                else if(c == 0)
                {
                    r++;
                }
                else
                {
                    r++;
                    c--;
                }
            }
        }
        return rlt;
    }
};