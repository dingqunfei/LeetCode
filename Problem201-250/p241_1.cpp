/**
 * @file p241_1.cpp
 * @brief 
 * @author dingqunfei (dqflying@gmail.com)
 * @version 1.0
 * @date 2021-05-30
 * 
 * @copyright Copyright (c) 2021 DQFLYING
 * 
 * @par :
 * 
 * 
 * Date        : 2021-05-30
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
    vector<int> diffWaysToCompute(string expression) {
        vector<int> res;
        int size = expression.size();
        vector<int> left;
        vector<int> right;
        for(int i = 0; i < size; ++i)
        {
            if(expression[i] == '+' || expression[i] == '-' || expression[i] == '*')
            {
                vector<int> left = diffWaysToCompute(string(expression.begin(), expression.begin()+i));
                vector<int> right = diffWaysToCompute(string(expression.begin()+i+1, expression.end()));

                for(auto l_val: left)
                {
                    for(auto r_val: right)
                    {
                        if(expression[i] == '+')
                        {
                            res.push_back(l_val+r_val);
                        }
                        if(expression[i] == '-')
                        {
                            res.push_back(l_val-r_val);
                        }
                        if(expression[i] == '*')
                        {
                            res.push_back(l_val*r_val);
                        }
                    }
                }
            }
        }
        if(res.empty())
        {
            istringstream in(expression);
            int val;
            in >> val;
            res.push_back(val);
        }
        return res;
    }
};