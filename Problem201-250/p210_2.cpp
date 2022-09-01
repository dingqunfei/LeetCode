class Solution {
public:
    vector<int> onpath;
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
        onpath.push_back(start);
        return true;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<bool> visited(numCourses, false);
        vector<vector<int>> preCourses(numCourses, vector<int>());
        vector<bool> checked(numCourses, false);
        for(auto item: prerequisites)
        {
            preCourses[item[0]].push_back(item[1]);
        }
        for(int i = 0; i < numCourses; ++i)
        {
            if(!traverse(preCourses, i, visited, checked))
            {
                return vector<int>();
            }
        }
        return onpath;
    }

};