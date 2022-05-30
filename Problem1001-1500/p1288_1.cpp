class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b){return a[0] < b[0] || (a[0] == b[0] && a[1] > b[1]);});

        int n = intervals.size();
        int total = n;
        int rmax = intervals[0][1];
        for(int i = 1; i < n; ++i)
        {
            if(rmax >= intervals[i][1])
            {
                --total;
            }
            else
            {
                rmax = intervals[i][1];
            }
        }
        return total;
    }
};