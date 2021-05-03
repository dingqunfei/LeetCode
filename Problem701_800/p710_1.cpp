/**
 * @file p710_1.cpp
 * @brief 
 * @author dingqunfei (dqflying@gmail.com)
 * @version 1.0
 * @date 2021-05-03
 * 
 * @copyright Copyright (c) 2021 DQFLYING
 * 
 * @par :
 * 
 * 
 * Date        : 2021-05-03
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
    int wLen;
    unordered_map<int, int> m;
public:
    Solution(int N, vector<int>& blacklist) {
        wLen = N - blacklist.size();
        unordered_set<int> w;
        for(int i = wLen; i < N; ++i)
        {
            w.insert(i);
        }
        for(int x: blacklist)
        {
            w.erase(x);
        }
        auto wi = w.begin();
        for(int x: blacklist)
        {
            if(x < wLen)
            {
                m[x] = *wi++;
            }
        } 
    }
    
    int pick() {
        int k = rand() % wLen;
        return m.count(k) ? m[k] : k;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(N, blacklist);
 * int param_1 = obj->pick();
 */