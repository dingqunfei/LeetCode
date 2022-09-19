class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> g(n+1);
        for(auto &t: times)
        {
            g[t[0]].emplace_back(t[1], t[2]);
        }

        vector<int> dist(n+1, INT_MAX);
        dist[k] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;
        q.emplace(dist[k], k);

        while(!q.empty())
        {
            auto p = q.top();
            q.pop();
            int time = p.first, x = p.second;
            if(time > dist[x])
            {
                continue;
            }

            for(auto &t: g[x])
            {
                int nextDist = time + t.second;
                int next = t.first;
                if(nextDist < dist[next])
                {
                    dist[next] = nextDist;
                    q.emplace(nextDist, next);
                }
            }
        }

        int nMaxDist = *max_element(dist.begin()+1, dist.end());
        return nMaxDist == INT_MAX ? -1 : nMaxDist;
    }
};

