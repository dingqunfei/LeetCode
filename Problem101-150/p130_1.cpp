/**
 * @file p130_1.cpp
 * @brief 
 * @author dingqunfei (dqflying@gmail.com)
 * @version 1.0
 * @date 2021-04-17
 * 
 * @copyright Copyright (c) 2021 DQFLYING
 * 
 * @par :
 * 
 * 
 * Date        : 2021-04-17
 * Version     : 1.0
 * Author      : dqflying
 * Lisence     : 
 * Description : 
 * 
 * 
 * 
 * 
 */

class UnionFind{
public:
    UnionFind(int n):
    num(n)
    {
        parent = new int[n];
        sizes = new int[n];
        for(int i = 0; i < n; ++i)
        {
            parent[i] = i;
            sizes[i] = 1;
        }
    }

    bool connected(int p, int q)
    {
        return Find(p) == Find(q);
    }

    int count() const
    {
        return num;
    }


    int Find(int x)
    {
        while(x != parent[x])
        {
            parent[x] = parent[parent[x]];
            x = parent[x];
        }
        return x;
    }

    void Union(int p, int q)
    {
        int rootP = Find(p);
        int rootQ = Find(q);
        if(rootP == rootQ) return;
        if(sizes[rootP] > sizes[rootQ])
        {
            parent[rootQ] = rootP;
            sizes[rootP] += sizes[rootQ];
        }
        else
        {
            parent[rootP] = rootQ;
            sizes[rootQ] += sizes[rootP];
        }
        --num;
    }
    

private:
    int *parent;
    int *sizes;
    int num;
};

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if(board.size() <= 2) return;
        if(board.size() == 3 && board[0].size() <= 2) return;

        int m = board.size();
        int n = board[0].size();
        UnionFind uf = UnionFind(m*n+1);
        int dummy = m*n;

        for(int i = 0; i < m; ++i)
        {
            if(board[i][0] == 'O')
            {
                uf.Union(dummy, n*i);
            }
            if(board[i][n-1] == 'O')
            {
                uf.Union(dummy, n*(i+1)-1);
            }
        }

        for(int j = 0; j < n; ++j)
        {
            if(board[0][j] == 'O')
            {
                uf.Union(dummy, j);
            }
            if(board[m-1][j] == 'O')
            {
                uf.Union(dummy, n*(m-1)+j);
            }
        }
        /*
        //为什么会内存越界？？？
        //因为使用了i+1, j+1
        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                if(board[i][j] == 'O')
                {
                    if((i+1 < m) && (board[i+1][j] == 'O'))
                    {
                        uf.Union(i*n+j-1, (i+1)*n+j-1);
                    }
                    if((j+1 < n) && (board[i][j+1] == 'O'))
                    {
                        uf.Union(i*n+j-1, i*n+j);
                    }
                }
            }
        }

        for (int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                if(!uf.connected(dummy, i*n+j))
                {
                    board[i][j] = 'X';
                }
            }
        }
        */
        vector<vector<int>> d = {{1,0}, {0,1}, {0,-1}, {-1,0}};
        for (int i = 1; i < m - 1; i++) 
            for (int j = 1; j < n - 1; j++) 
                if (board[i][j] == 'O')
                    // 将此 O 与上下左右的 O 连通
                    for (int k = 0; k < 4; k++) {
                        int x = i + d[k][0];
                        int y = j + d[k][1];
                        if (board[x][y] == 'O')
                            uf.Union(x * n + y, i * n + j);
                    }
        // 所有不和 dummy 连通的 O，都要被替换
        for (int i = 1; i < m - 1; i++) 
            for (int j = 1; j < n - 1; j++) 
                if (!uf.connected(dummy, i * n + j))
                    board[i][j] = 'X';

    }
};