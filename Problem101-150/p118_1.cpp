/**
 * @file p118_1.cpp
 * @brief 
 * @author dingqunfei (dqflying@gmail.com)
 * @version 1.0
 * @date 2021-08-30
 * 
 * @copyright Copyright (c) 2021 DQFLYING
 * 
 * @par :
 * 
 * 
 * Date        : 2021-08-30
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
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>  ans;
        for(int i = 1; i <= numRows; ++i)
        {
            ans.push_back(vector<int>(i, 1));
            for(int j = 1; j < i-1; ++j)
            {
                ans[i-1][j] = ans[i-2][j-1]+ans[i-2][j];
            }
        }
        return ans;
    }
};