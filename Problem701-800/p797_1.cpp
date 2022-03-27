class Solution {
public:
    vector<int> onPath;
    vector<vector<int>> res;
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        traverse(graph, 0, n);
        return res;
    }
    void traverse(vector<vector<int>>& graph, int node, int n)
    {
        onPath.push_back(node);
        if(node == n-1)
        {
            res.push_back(onPath);
        }
        for(auto i : graph[node])
        {
            traverse(graph, i, n);
        }
        onPath.pop_back();
    }
};