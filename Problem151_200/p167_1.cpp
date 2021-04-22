/**
 * @file p167_1.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-04-22
 * 
 * @copyright Copyright (c) 2021
 * 
 */

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int lhs = 0, rhs = numbers.size()-1;
        while(lhs < rhs)
        {
            int sum = numbers[lhs] + numbers[rhs];
            if(sum == target)
            {
                return {lhs+1, rhs+1};
            }
            else if(sum < target)
            {
                ++lhs;
            }
            else if(sum > target)
            {
                --rhs;
            }
        }
        return {-1, -1};

    }
};