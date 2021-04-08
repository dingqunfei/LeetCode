/**
 * @file p829_2.cpp
 * @brief 
 * @author dingqunfei (dqflying@gmail.com)
 * @version 1.0
 * @date 2021-04-07
 * 
 * @copyright Copyright (c) 2021 DQFLYING
 * 
 * @par :
 * 
 * 
 * Date        : 2021-04-07
 * Version     : 1.0
 * Author      : dqflying
 * Lisence     : 
 * Description : 
 * 
 * 
 * 
 * 
 */

//累加和，使用累加代替N^2/2的计算，减少计算量，同时得以将long long修改为int类型，减少内存占用

class Solution {
public:
    int consecutiveNumbersSum(int N) {
        int count = 0;
        int sum = 0;
        int max_value = N;
        int max_range = sqrt(2 * N) + 10;
        for(int i = 1; i <= max_range; ++i)
        {
            sum += (i-1);
            if (((max_value-sum) >= i) && (((max_value-sum)%i) == 0))
            {
                ++count;
            }
        }
        return count;

    }
};