class Solution {
public:
    vector<vector<int>> edges;
    vector<bool> visited;
    vector<bool> path;
    vector<int> res;
    bool hasCycle = false;
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        visited.resize(numCourses);
        edges.resize(numCourses);
        path.resize(numCourses);
        for (const auto& info: prerequisites) {
            edges[info[1]].push_back(info[0]);
        }
        for(int i = 0; i < numCourses; ++i)
        {
            traverse(i);
        }
        if(hasCycle)
        {
            return vector<int>();
        }
        std::reverse(res.begin(), res.end());
        return res;
    }
    void traverse(int i)
    {
        if(path[i])
        {
            hasCycle = true;
        }
        if(visited[i] || hasCycle)
        {
            return;
        }
        visited[i] = true;
        path[i] = true;
        for(auto node: edges[i])
        {
            traverse(node);
        }
        res.push_back(i);
        path[i] = false;

    }
};