class Solution {
public:
    int numTrees(int start, int end, vector<int>& store)
    {
        if(start >= end)
        {
            return 1;
        }
        if(store[end-start+1] != INT_MIN)
        {
            return store[end-start+1];
        }
        
        int count = 0;
        for(int i = start; i <= end; ++i)
        {
            count += numTrees(start, i-1, store) * numTrees(i+1, end, store);
        }
        store[end-start+1] = count;
        return count;
    }
    int numTrees(int n) {
        vector<int> store(n+1, INT_MIN);
        return numTrees(1, n, store);
    }
};