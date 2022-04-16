class Solution {
public:
    int count;
    unordered_map<int, int> mapping;
    Solution(int n, vector<int>& blacklist) {
        count = n - blacklist.size();
        for(int i = 0; i < blacklist.size(); ++i)
        {
            mapping[blacklist[i]] = INT_MAX;
        }
        int value = n-1; 
        for(int i = 0; i < blacklist.size(); ++i)
        {
            if(blacklist[i] >= count)
            {
                continue;
            }
            while(mapping.count(value))
            {
                --value;
            }
            mapping[blacklist[i]] = value;
            --value;
        }
    }
    
    int pick() {
        int index = rand()%count;
        if(mapping.count(index))
        {
            return mapping[index];
        }
        return index;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(n, blacklist);
 * int param_1 = obj->pick();
 */