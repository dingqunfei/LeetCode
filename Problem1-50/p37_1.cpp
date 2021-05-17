/**
 * @file p37_1.cpp
 * @brief 
 * @author dingqunfei (dqflying@gmail.com)
 * @version 1.0
 * @date 2021-05-18
 * 
 * @copyright Copyright (c) 2021 DQFLYING
 * 
 * @par :
 * 
 * 
 * Date        : 2021-05-18
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
    bool isLegal(vector<vector<char>>& board, int r, int c, char n) 
    {
        for (int i = 0; i < 9; i++) 
        {
            if (board[r][i] == n) return false;
            if (board[i][c] == n) return false;
            if (board[(r/3)*3 + i/3][(c/3)*3 + i%3] == n)
                return false;
        }
        return true;
    }

    bool backtrack(vector<vector<char>>& board, int col, int row)
    {
        if (row == 9) 
        {
            return backtrack(board, col + 1, 0);;
        }
        if (col == 9) 
        {
            return true;
        }
        for(int i = col; i < 9; ++i)
        {
            for(int j = row; j < 9; ++j)
            {
                if (board[i][j] != '.') 
                {
                    return backtrack(board, i, j + 1);
                } 

                for(char start = '1'; start <= '9'; ++start)
                {
                    if(!isLegal(board, i, j, start))
                    {
                        continue;
                    }
                    board[i][j] = start;
                    if(backtrack(board, i, j + 1))
                    {
                        return true;
                    }
                    board[i][j] = '.';
                }
                return false;
            }
        }
        return false;
    }
public:
    void solveSudoku(vector<vector<char>>& board) 
    {
        backtrack(board, 0, 0);
    }
};