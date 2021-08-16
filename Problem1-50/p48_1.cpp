/**
 * @file p48_1.cpp
 * @brief 
 * @author dingqunfei (dqflying@gmail.com)
 * @version 1.0
 * @date 2021-08-17
 * 
 * @copyright Copyright (c) 2021 DQFLYING
 * 
 * @par :
 * 
 * 
 * Date        : 2021-08-17
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
    void rotate(vector<vector<int>>& matrix) {
        int size = matrix.size();
        int start = 0;
        while(start < size/2)
        {
            swap(matrix[start], matrix[size-1-start]);
            ++start;
        }
        for(int i = 0; i < size; ++i)
        {
            for(int j = i; j < size; ++j)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
};