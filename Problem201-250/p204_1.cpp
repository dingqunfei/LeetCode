/**
 * @file p204_1.cpp
 * @brief 
 * @author dingqunfei (dqflying@gmail.com)
 * @version 1.0
 * @date 2021-08-29
 * 
 * @copyright Copyright (c) 2021 DQFLYING
 * 
 * @par :
 * 
 * 
 * Date        : 2021-08-29
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

    int countPrimes(int n) {
        vector<bool> label(n, true);
        for(int i = 2; i*i <= n; ++i)
        {
            if(label[i])
            {
                for(int j = i*i; j < n; j += i)
                {
                    label[j] = false;
                }
            }
        }
        int ans = 0;
        for(int i = 2; i < n; ++i)
        {
            if(label[i])
            {
                ++ans;
            }
        }
        return ans;
    }
};