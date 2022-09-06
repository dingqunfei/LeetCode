class Solution {
public:
    bool traverse(vector<vector<int>>& graph, vector<bool>& visited, vector<bool>& color, int node)
    {
        visited[node] = true;
        for(int adj: graph[node])
        {
            if(!visited[adj])
            {
                color[adj] = !color[node];
                traverse(graph, visited, color, adj);
            }
            else
            {
                if(color[node] == color[adj])
                {
                    return false;
                }
            }
        }
        return true;
    }

    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> graph(n+1, vector<int>());
        for(auto item: dislikes)
        {
            graph[item[0]].push_back(item[1]);
            graph[item[1]].push_back(item[0]);
        }

        vector<bool> visited(n+1, false);
        vector<bool> color(n+1, false);
        for(int i = 1; i < n+1; ++i)
        {
            if(!traverse(graph, visited, color, i))
            {
                return false;
            }
        }
        return true;
    }
};