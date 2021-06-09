/**
 * @file p354_1.cpp
 * @brief 
 * @author dingqunfei (dqflying@gmail.com)
 * @version 1.0
 * @date 2021-06-09
 * 
 * @copyright Copyright (c) 2021 DQFLYING
 * 
 * @par :
 * 
 * 
 * Date        : 2021-06-09
 * Version     : 1.0
 * Author      : dqflying
 * Lisence     : 
 * Description : 
 * 
 * 
 * 
 * 
 */

//此方法行不通
//[[2,100],[3,200],[4,300],[5,500],[5,400],[5,250],[6,370],[6,360],[7,380]]
//考虑此数组，第一次遍历中，前面的数组已经被标记，但是实际后面的数组还要使用
//彼此一起才构成最优解
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), [](auto &a, auto &b){return a[0]<b[0];});
        int count = 0, start = 0;
        int len = envelopes.size();
        vector<bool> label(len, false);
        while(start < len)
        {
            while(label[start])
            {
                ++start;
            }
            int new_start = start;
            int curr_count = 0;
            int first = 0;
            int second = 0;
            while(new_start < len)
            {
                if(envelopes[new_start][1] > second && envelopes[new_start][0] > first)
                //if(envelopes[new_start][1] > second)
                {
                    label[new_start] = true;
                    second = envelopes[new_start][1];
                    first = envelopes[new_start][0];
                    ++curr_count;
                }
                ++new_start;
            }
            if(curr_count > count)
            {
                count = curr_count;
            }
        }
        return count;
    }
};



//优化效率
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int size = envelopes.size();
        if(size < 1)
        {
            return 0;
        }
        //对于宽度w相同的数对，要对其高度h进行降序排序
        //因为两个宽度相同的信封不能相互包含的，而逆序排序保证在w相同的数对中最多只选取一个计入 
        sort(envelopes.begin(), envelopes.end(), [](auto &a, auto &b){return (a[0] == b[0])?(a[1]>b[1]):a[0]<b[0];});

        //此时转换为求最长递增子序列问题
        //dp[i]是以i为结尾的最长递增子序列的长度
        vector<int> dp(size, 0);
        dp[0] = 1;
        for(int i = 1; i < size; ++i)
        {
                int temp = i-1;
                int larger = 0;
                while(temp >= 0)
                {
                    if(envelopes[i][1] > envelopes[temp][1])
                    {
                        larger = (dp[temp] > larger)? dp[temp]:larger;
                    }
                    --temp;
                }
                dp[i] = larger+1;
        }
        
        return *(max_element(dp.begin(), dp.end()));
    }
};