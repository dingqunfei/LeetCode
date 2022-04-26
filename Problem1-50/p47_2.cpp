class Solution {
public:
    vector<vector<int>> res;
    void backtrack(vector<int>& nums, vector<int>& track, vector<bool>& visited)
    {
        if(track.size() == nums.size())
        {
            res.push_back(track);
            return;
        }
        for(int i = 0; i < nums.size(); ++i)
        {
            if(visited[i])
            {
                continue;
            }
            if(i > 0 && nums[i] == nums[i-1] && !visited[i-1])
            {
                continue;
            }
            track.push_back(nums[i]);
            visited[i] = true;
            backtrack(nums, track, visited);
            track.pop_back();
            visited[i] = false;
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> track;
        int n = nums.size();
        vector<bool> visited(n, false);
        backtrack(nums, track, visited);
        return res;
    }
};