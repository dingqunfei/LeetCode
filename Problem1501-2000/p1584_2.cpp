class Solution {
public:
    int prim(vector<vector<int>>& points, int start)
    {
        int n = points.size();
        vector<vector<int>> graph(n, vector<int>(n, 0));
        for(int i = 0; i < n; ++i)
        {
            for(int j = i+1; j < n; ++j)
            {
                int dis = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                graph[i][j] = dis;
                graph[j][i] = dis;
            }
        }
        vector<int> lowcost(n, INT_MAX);
        vector<int> v(n, -1);
        v[start] = 0;
        for(int i = 0; i < n; ++i)
        {
            if(i == start)
            {
                continue;
            }
            if(graph[start][i] < lowcost[i])
            {
                lowcost[i] = graph[start][i];
            }
        }
        int total = 0;

        for(int i = 1; i < n; ++i)
        {
            int minIdx = -1;
            int minVal = INT_MAX;
            for(int j = 0; j < n; ++j)
            {
                if(v[j] != 0 && lowcost[j] < minVal)
                {
                    minVal = lowcost[j];
                    minIdx = j;
                }
            }
            total += minVal;
            v[minIdx] = 0;
            lowcost[minIdx] = -1;
            for(int k = 0; k < n; ++k)
            {
                if(v[k] == -1 && graph[minIdx][k] < lowcost[k])
                {
                    lowcost[k] = graph[minIdx][k];
                }
            }
        }
        return total;
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        return prim(points, 0);
    }
};