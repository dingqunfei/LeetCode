
class UnionFind{
public:
    UnionFind(int n):
    count(n)
    {
        size.resize(n);
        parent.resize(n);
        for(int i = 0; i < n; ++i)
        {
            size[i] = 1;
            parent[i] = i;
        }
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
        if(rootP == rootQ)
        {
            return;
        }
        if(size[rootP] >= size[rootQ])
        {
            parent[rootQ] = rootP;
            size[rootP] += size[rootQ];
        }
        else
        {
            parent[rootP] = rootQ;
            size[rootQ] += size[rootP];
        }
        --count;
    }

    int Count()
    {
        return count;
    }

    bool isConnected(int p, int q)
    {
        return Find(p) == Find(q);
    }

public:
    int count;
    vector<int> size;
    vector<int> parent;
};


class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        if(m <= 2)
        {
            return;
        }
        int n = board[0].size();
        if(n <= 2)
        {
            return;
        }

        UnionFind uf(m*n+1);
        int dummy = m*n;
        for(int i = 0; i < m; ++i)
        {
            if(board[i][0] == 'O')
            {
                uf.Union(i * n, dummy);
            }
            if(board[i][n-1] == 'O')
            {
                uf.Union(i * n + n -1, dummy);
            }
        }
        for(int j = 0; j < n; ++j)
        {
            if(board[0][j] == 'O')
            {
                uf.Union(j, dummy);
            }
            if(board[m-1][j] == 'O')
            {
                uf.Union((m-1) * n + j, dummy);
            }
        }
        vector<vector<int>> direct = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        for(int i = 1; i < m-1; ++i)
        {
            for(int j = 1; j < n-1; ++j)
            {
                if(board[i][j] == 'O')
                {
                    for(int k = 0; k < 4; ++k)
                    {
                        int x = i+direct[k][0];
                        int y = j+direct[k][1];
                        if(board[x][y] == 'O')
                        {
                            uf.Union(i * n + j, x * n + y);
                        }
                    }
                }
            }
        }

        for (int i = 1; i < m - 1; i++)
        {
            for (int j = 1; j < n - 1; j++)
            {
                if (!uf.isConnected(dummy, i * n + j))
                {
                    board[i][j] = 'X';
                }
            }
        }
            
    }
};
