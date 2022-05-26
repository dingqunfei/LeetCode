class Solution {
public:
    vector<int> data;
    Solution(vector<int>& nums) {
        data = nums;
    }
    
    int pick(int target) {
        int ret = 0, count = 0;
        for(int i = 0; i < data.size(); ++i)
        {
            if(data[i] == target)
            {
                ++count;
                if(rand()%count == 0)
                {
                    ret = i;
                }
            }
        }
        return ret;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */