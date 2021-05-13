/**
 * @file p136_1.cpp
 * @brief 
 * @author dingqunfei (dqflying@gmail.com)
 * @version 1.0
 * @date 2021-04-30
 * 
 * @copyright Copyright (c) 2021 DQFLYING
 * 
 * @par :
 * 
 * 
 * Date        : 2021-04-30
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
    int singleNumber(vector<int>& nums) {
        int res = 0;;
        for(int i = 0; i < nums.size(); ++i)
        {
            res = res ^ nums[i];
        }
        return res;
    }
};