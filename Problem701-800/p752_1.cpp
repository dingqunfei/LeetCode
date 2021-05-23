/**
 * @file p752_1.cpp
 * @brief 
 * @author dingqunfei (dqflying@gmail.com)
 * @version 1.0
 * @date 2021-05-23
 * 
 * @copyright Copyright (c) 2021 DQFLYING
 * 
 * @par :
 * 
 * 
 * Date        : 2021-05-23
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
private:
    string PlusOne(string str, int j)
    {
        if(str[j] == '9')
        {
            str[j] = '0';
        }
        else
        {
            str[j] += 1;
        }
        return str;
    }

    string MinusOne(string str, int j)
    {
        if(str[j] == '0')
        {
            str[j] = '9';
        }
        else
        {
            str[j] -= 1;
        }
        return str;
    }
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> deads(deadends.begin(), deadends.end()), visited;
        
        queue<string> q;
        int step = 0;
        q.push("0000");
        while(!q.empty())
        {
            int size = q.size();
            for(int i = 0; i < size; ++i)
            {
                string tmp = q.front();
                q.pop();
                //排除第一次为"0000"的情况
                if(deads.find(tmp) != deads.end())
                {
                    continue;
                }
                if(tmp == target)
                {
                    return step;
                }
                for(int j = 0; j < 4; ++j)
                {
                    string less = MinusOne(tmp, j);
                    if(deads.find(less) == deads.end() && visited.find(less) == visited.end())
                    {
                        q.push(less);
                        visited.insert(less);
                    }
                    string more = PlusOne(tmp, j);
                    if(deads.find(more) == deads.end() && visited.find(more) == visited.end())
                    {
                        q.push(more);
                        visited.insert(more);
                    }
                }
            }
            ++step;
        }
        return -1;

    }
};



//优化了set判断元素与插入，速度略快了些
class Solution2 {
private:
    string PlusOne(string str, int j)
    {
        if(str[j] == '9')
        {
            str[j] = '0';
        }
        else
        {
            str[j] += 1;
        }
        return str;
    }

    string MinusOne(string str, int j)
    {
        if(str[j] == '0')
        {
            str[j] = '9';
        }
        else
        {
            str[j] -= 1;
        }
        return str;
    }
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> deads(deadends.begin(), deadends.end()), visited;
        
        queue<string> q;
        int step = 0;
        q.push("0000");
        while(!q.empty())
        {
            int size = q.size();
            for(int i = 0; i < size; ++i)
            {
                string tmp = q.front();
                q.pop();
                if(deads.find(tmp) != deads.end())
                {
                    continue;
                }
                if(tmp == target)
                {
                    return step;
                }
                for(int j = 0; j < 4; ++j)
                {
                    string less = MinusOne(tmp, j);
                    if(deads.count(less) + visited.count(less) == 0)
                    {
                        q.push(less);
                        visited.emplace(less);
                    }
                    string more = PlusOne(tmp, j);
                    if(deads.count(more) + visited.count(more) == 0)
                    {
                        q.push(more);
                        visited.emplace(more);
                    }
                }
            }
            ++step;
        }
        return -1;

    }
};