/**
 * @file p773_1.cpp
 * @brief 
 * @author dingqunfei (dqflying@gmail.com)
 * @version 1.0
 * @date 2021-05-25
 * 
 * @copyright Copyright (c) 2021 DQFLYING
 * 
 * @par :
 * 
 * 
 * Date        : 2021-05-25
 * Version     : 1.0
 * Author      : dqflying
 * Lisence     : 
 * Description : 
 * 
 * 
 * 
 * 
 */


class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        //6个数，2+2+1+1+1种移动方式
        string target = "123450";
        string start = "";
        int m = 2, n = 3;
        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                start.push_back(board[i][j]+'0');
            }
        }

        queue<string> q;
        unordered_set<string> visited;
        vector<vector<int>> neighbor = {
            { 1, 3 },
            { 0, 4, 2 },
            { 1, 5 },
            { 0, 4 },
            { 3, 1, 5 },
            { 4, 2 }
        };

        q.push(start);
        visited.insert(start);
        int step = 0;
        while(!q.empty())
        {
            int size = q.size();
            for(int i = 0; i < size; ++i)
            {
                string tmp = q.front();
                q.pop();
                if(tmp == target)
                {
                    return step;
                }
                visited.insert(tmp);
                int index = 0;
                for (; tmp[index] != '0'; index++);
                vector<int> tmp_neighbor = neighbor[index];
                for(int j = 0; j < tmp_neighbor.size(); ++j)
                {
                    string add_str = tmp;
                    add_str[index] = add_str[tmp_neighbor[j]];
                    add_str[tmp_neighbor[j]] = '0';
                    if(visited.count(add_str) == 0)
                    {
                        q.push(add_str);
                        visited.insert(add_str);
                    }
                }
            }
            ++step;
        }
        return -1;

    }
};