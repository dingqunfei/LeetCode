/**
 * @file p66_1.cpp
 * @brief 
 * @author dingqunfei (dqflying@gmail.com)
 * @version 1.0
 * @date 2021-08-16
 * 
 * @copyright Copyright (c) 2021 DQFLYING
 * 
 * @par :
 * 
 * 
 * Date        : 2021-08-16
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
    vector<int> plusOne(vector<int>& digits) {
        vector<int> ans(digits.size(), 0);
        int addition = 1;
        for(int i = digits.size()-1; i >= 0; --i)
        {
            int value = digits[i]+addition;
            if(value == 10)
            {
                value = 0;
                addition = 1;
            }
            else
            {
                addition = 0;
            }
            ans[i] = value;
        }
        if(addition == 1)
        {
            ans.insert(ans.begin(), 1);
        }
        return ans;
    }
};