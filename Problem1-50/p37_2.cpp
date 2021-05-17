/**
 * @file p37_2.cpp
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
        /*
            if board[i][j] != '.':      # 非空位置不用管
                return backtrack(board, i, j+1)
            for n in range(1, 10):      # 遍历选择列表，此处的选择是，给空白处填 "1" - "9" 中之一
                c = str(n)
                if not self.check(board, i, j, c):     # 判断选择的字符是否满足要求（不与其他位置冲突）
                    continue
                board[i][j] = c                 # 做出选择
                if backtrack(board, i, j+1):    # 递归调用，直接return是因为只需要一个可行解，而不需要所有可行解
                    return True
                board[i][j] = '.'               # 撤销选择


        */
        if(board[col][row] != '.')
        {
            return backtrack(board, col, row+1);
        }
        for(char ch = '1'; ch <= '9'; ++ch)
        {
            if(!isLegal(board, col, row, ch))
            {
                continue;
            }
            board[col][row] = ch;
            if(backtrack(board, col, row+1))
            {
                return true;
            }
            board[col][row] = '.';
        }
        return false;
    }
public:
    void solveSudoku(vector<vector<char>>& board) 
    {
        backtrack(board, 0, 0);
    }
};