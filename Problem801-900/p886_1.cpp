class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> graph(n, vector<int>());
        for(auto item: dislikes)
        {
            graph[item[0]-1].push_back(item[1]-1);
            graph[item[1]-1].push_back(item[0]-1);

        }
        return isBipartite(graph);
    }
    vector<bool> visited;
    vector<bool> color;
    bool isPart = true;
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        visited.resize(n);
        color.resize(n);
        for(int i = 0; i < n; ++i)
        {
            if(!visited[i])
            {
                traverse(graph, i);
            }
        }
        return isPart;
        
    }
    void traverse(vector<vector<int>>& graph, int n)
    {
        if(!isPart)
        {
            return;
        }
        visited[n] = true;
        for(auto node: graph[n])
        {
            if(!visited[node])
            {
                color[node] = !color[n];
                traverse(graph, node);
            }
            else
            {
                if(color[n] == color[node])
                {
                    isPart = false;
                }
            }
        }
    }
};