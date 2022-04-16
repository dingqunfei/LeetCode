/**
 * @file 1137_1.cpp
 * @brief 
 * @author dingqunfei (dqflying@gmail.com)
 * @version 1.0
 * @date 2021-09-12
 * 
 * @copyright Copyright (c) 2021 DQFLYING
 * 
 * @par :
 * 
 * 
 * Date        : 2021-09-12
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
    int tribonacci(int n) {
        if(n == 0)
        {
            return 0;
        }
        else if(n == 1 || n == 2)
        {
            return 1;
        }
        int left = 0, mid = 1, right = 1, ans = 0;
        for(int i = 3; i <= n; ++i)
        {
            ans = left+mid+right;
            left = mid;
            mid = right;
            right = ans;
        }
        return ans;
    }
};