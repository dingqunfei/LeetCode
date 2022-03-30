//超时
class Solution {
public:
    bool hasCycle = false;
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjLinked(numCourses, vector<int>());
        for(int i = 0; i < prerequisites.size(); ++i)
        {
            adjLinked[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        vector<bool> visited(numCourses, false);
        vector<bool> onPath(numCourses, false);
        for(int i = 0; i < numCourses; ++i)
        {
            traverse(adjLinked, i, visited, onPath);
        }
        return !hasCycle;
    }
    void traverse(vector<vector<int>>& graph, int n, vector<bool>& visited, vector<bool>& onPath)
    {
        if(onPath[n])
        {
            hasCycle = true;
        }
        if(visited[n] || hasCycle)
        {
            return;
        }
        onPath[n] = true;
        for(int i = 0; i < graph[n].size(); ++i)
        {
            traverse(graph, graph[n][i], visited, onPath);
        }
        onPath[n] = false;
    }

};