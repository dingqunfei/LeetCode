class Solution {
public:
    bool traverse(vector<vector<int>>& preCourses, int start, vector<bool>& visited, vector<bool>& checked)
    {
        if(checked[start])
        {
            return true;
        }
        if(visited[start])
        {
            return false;
        }
        visited[start] = true;
        for(int node: preCourses[start])
        {
            if(!traverse(preCourses, node, visited, checked))
            {
                return false;
            }
        }
        visited[start] = false;
        checked[start] = true;
        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<bool> visited(numCourses, false);
        vector<vector<int>> preCourses(numCourses, vector<int>());
        vector<bool> checked(numCourses, false);
        for(auto item: prerequisites)
        {
            preCourses[item[1]].push_back(item[0]);
        }
        for(int i = 0; i < numCourses; ++i)
        {
            if(!traverse(preCourses, i, visited, checked))
            {
                return false;
            }
        }
        return true;
    }
};