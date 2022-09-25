class Solution {
public:

    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        if(m < 1)
        {
            return -1;
        }
        int n = heights[0].size();

        vector<vector<pair<int, int>>> g(m*n);
        vector<vector<int>> direction = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                for(auto d : direction)
                {
                    int nYm = i + d[0];
                    int nYn = j + d[1];
                    if(nYm >= 0 && nYm < m && nYn >= 0 && nYn < n)
                    {

                        int nXIndex = i * n + j;
                        int nXValue = heights[i][j];
                        int nYIndex = nYm * n + nYn;
                        int nYValue = heights[nYm][nYn];
                        g[nXIndex].emplace_back(nYIndex, abs(nYValue-nXValue));
                    }
                }
            }
        }

        vector<int> dist(m*n, INT_MAX);
        dist[0] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;
        q.emplace(dist[0], 0);
        while(!q.empty())
        {
            auto p = q.top();
            q.pop();
            int h = p.first;
            int x = p.second;
            if(x == m*n-1)
            {
                return dist[x];
            }
            if(h > dist[x])
            {
                continue;
            }
            for(auto item: g[x])
            {
                int next = item.first;
                int nexth = item.second;
                int cost = max(nexth, dist[x]);
                if(dist[next] > cost)
                {
                    dist[next] = cost;
                    q.emplace(cost, next);
                }
            }
        }

        return -1;
    }
};