class Solution {
public:
    int m, n;
    void dfs(vector<vector<char>>& board, int x, int y)
    {
        if(x >= m || x < 0 || y >= n || y < 0 || board[x][y] != 'O')
        {
            return;
        }
        board[x][y] = 'A';
        dfs(board, x-1, y);
        dfs(board, x+1, y);
        dfs(board, x, y-1);
        dfs(board, x, y+1);
    }

    void solve(vector<vector<char>>& board) {
        m = board.size();
        if(m < 3)
        {
            return;
        }
        n = board[0].size();
        if(n < 3)
        {
            return;
        }

        for(int i = 0; i < n; ++i)
        {
            dfs(board, 0, i);
            dfs(board, m-1, i);
        }
        for(int i = 0; i < m; ++i)
        {
            dfs(board, i, 0);
            dfs(board, i, n-1);
        }
        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                if(board[i][j] == 'A')
                {
                    board[i][j] = 'O';
                }
                else if(board[i][j] == 'O')
                {
                    board[i][j] = 'X';
                }
            }
        }
    }
};