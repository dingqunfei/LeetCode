class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        int firstSize = firstList.size();
        int secondSize = secondList.size();
        vector<vector<int>> overlap;
        int i = 0, j = 0;
        while(i < firstSize && j < secondSize)
        {
            int left = max(firstList[i][0], secondList[j][0]);
            int right = min(firstList[i][1], secondList[j][1]);
            if(left <= right)
            {
                overlap.push_back({left, right});
            }
            if(firstList[i][1] > secondList[j][1])
            {
                ++j;
            }
            else
            {
                ++i;
            }
        }
        return overlap;
    }
};