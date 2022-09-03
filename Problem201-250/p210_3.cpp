class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indgree(numCourses, 0);
        vector<vector<int>> preCourses(numCourses, vector<int>());
        for(auto item: prerequisites)
        {
            preCourses[item[1]].push_back(item[0]);
            indgree[item[0]]++;
        }
        // for(int i = 0; i < preCourses.size(); ++i)
        // {
        //     for(int j = 0; j < preCourses[i].size(); ++j)
        //     {
        //         std::cout << preCourses[i][j] << std::endl;
        //     }
        // }
        queue<int> q;
        for(int i = 0; i < numCourses; ++i)
        {
            if(indgree[i] == 0)
            {
                q.push(i);
            }
        }
        vector<int> res;
        while(!q.empty())
        {
            int course = q.front();
            q.pop();
            res.push_back(course);
            for(int next: preCourses[course])
            {
                --indgree[next];
                if(indgree[next] == 0)
                {
                    q.push(next);
                }
            }
        }

        return res.size() == numCourses ? res : vector<int>();
    }
};