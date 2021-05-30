/**
 * @file p528_1.cpp
 * @brief 
 * @author dingqunfei (dqflying@gmail.com)
 * @version 1.0
 * @date 2021-05-31
 * 
 * @copyright Copyright (c) 2021 DQFLYING
 * 
 * @par :
 * 
 * 
 * Date        : 2021-05-31
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
private:
    vector<int> weight;
    vector<int> preSum;
    int total;
public:
    Solution(vector<int>& w) {
        weight = w;
        total = 0;
        //preSum.push_back(0);
        for(auto i: w)
        {
            total += i;
            preSum.push_back(total);
        }
    }

    //二分查找，为什么要这样
    int getIndex(int value)
    {
        int left = 0, right = preSum.size()-1;
        while(left < right)
        {
            int mid = (left+right)/2;
            if(preSum[mid] <= value)
            {
                left = mid+1;
            }
            else
            {
                right = mid;
            }
        }
        return right;
    }
    
    int pickIndex() {
        return getIndex(rand()%total);
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */