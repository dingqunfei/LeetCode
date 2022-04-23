class UnionFind{
public:
    UnionFind(int n):
    count(n)
    {
        size.resize(n);
        parent.resize(n);
        for(int i = 0; i < n; ++i)
        {
            size[i] = 1;
            parent[i] = i;
        }
    }

    int Find(int x)
    {
        while(x != parent[x])
        {
            parent[x] = parent[parent[x]];
            x = parent[x];
        }
        return x;
    }

    void Union(int p, int q)
    {
        int rootP = Find(p);
        int rootQ = Find(q);
        if(rootP == rootQ)
        {
            return;
        }
        if(size[rootP] >= size[rootQ])
        {
            parent[rootQ] = rootP;
            size[rootP] += size[rootQ];
        }
        else
        {
            parent[rootP] = rootQ;
            size[rootQ] += size[rootP];
        }
        --count;
    }

    int Count()
    {
        return count;
    }

    bool isConnected(int p, int q)
    {
        return Find(p) == Find(q);
    }

public:
    int count;
    vector<int> size;
    vector<int> parent;
};


class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<vector<int>> distance(n * (n - 1) / 2, vector<int>(3, 0));
        int k = 0;
        for(int i = 0; i < n; ++i)
        {
            for(int j = i+1; j < n; ++j)
            {
                distance[k][0] = i;
                distance[k][1] = j;
                distance[k][2] = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                ++k;
            }
        }

        sort(distance.begin(), distance.end(), [](vector<int>& a, vector<int>& b){ return a[2] < b[2]; });

        int mst = 0;
        UnionFind uf(n);
        for(int i = 0; i < distance.size(); ++i)
        {
            int x = distance[i][0];
            int y = distance[i][1];
            int cost = distance[i][2];
            if(uf.isConnected(x, y))
            {
                continue;
            }
            mst += cost;
            uf.Union(x, y);
        }
        return mst;
    }
};