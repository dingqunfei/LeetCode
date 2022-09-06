class Solution {
public:
    bool traverse(vector<vector<int>>& graph, vector<bool>& visited, vector<bool>& color, int n)
    {
        visited[n] = true;
        for(int i: graph[n])
        {
            if(!visited[i])
            {
                color[i] = !color[n];
                traverse(graph, visited, color, i);
            }
            else
            {
                if(color[i] == color[n])
                {
                    return false;
                }
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<bool> visited(n, false);
        vector<bool> color(n, false);
        for(int i = 0; i < n; ++i)
        {
            if(!traverse(graph, visited, color, i))
            {
                return false;
            }
        }
        return true;
    }
};