/**
 * @file p514_1.cpp
 * @brief 
 * @author dingqunfei (dqflying@gmail.com)
 * @version 1.0
 * @date 2021-08-10
 * 
 * @copyright Copyright (c) 2021 DQFLYING
 * 
 * @par :
 * 
 * 
 * Date        : 2021-08-10
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
    int clac(int len, int a, int b) {
        return min((len + a - b) % len, (len + b - a) % len);
    }


    int findRotateSteps(string ring, string key) {
        int m = key.size(), n = ring.size();
        vector<int> pos[26];
        for(int i = 0; i < n; ++i)
        {
            pos[ring[i]-'a'].push_back(i);
        }

        vector<vector<int>> dp(m, vector<int>(n, INT_MAX));
        for(int i = 0; i < m; ++i)
        {
            for(auto j: pos[key[i]-'a'])
            {
                if(i == 0)
                {
                    dp[i][j] = min(dp[i][j], clac(n, 0, j)+1);
                    continue;
                }

                for(auto k: pos[key[i-1]-'a'])
                {
                    dp[i][j] = min(dp[i][j], dp[i-1][k]+clac(n, k, j)+1);
                }
            }
        }

        return *min_element(dp.back().begin(), dp.back().end()); 
    }
};