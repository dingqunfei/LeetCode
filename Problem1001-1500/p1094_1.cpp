class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int n = 1001;
        vector<int> seats(n, 0);
        for(auto item: trips)
        {
            seats[item[1]] += item[0];
            if(item[2] < n)
            {
                seats[item[2]] -= item[0];
            }
        }
        if(seats[0] > capacity)
        {
            return false;
        }
        for(int i = 1; i < n; ++i)
        {
            seats[i] += seats[i-1];
            if(seats[i] > capacity)
            {
                return false;
            }
        }
        return true;
    }
};