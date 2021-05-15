/**
 * @file p36_1.cpp
 * @brief 
 * @author dingqunfei (dqflying@gmail.com)
 * @version 1.0
 * @date 2021-05-16
 * 
 * @copyright Copyright (c) 2021 DQFLYING
 * 
 * @par :
 * 
 * 
 * Date        : 2021-05-16
 * Version     : 1.0
 * Author      : dqflying
 * Lisence     : 
 * Description : 
 * 
 * 
 * 
 * 
 */


//笨办法呀呀呀

//进一步合并
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool colLabel[9] = {false};
        bool rowLabel[9] = {false};
        bool crLabel[9] = {false};
        for(int i = 0; i < 9; ++i)
        {
            for(int j = 0; j < 9; ++j)
            {
                char colChar = board[i][j];
                char rowChar = board[j][i];
                if(colChar != '.')
                {
                    if(colLabel[colChar-'1'])
                    {
                        return false;
                    }
                    else
                    {
                        colLabel[colChar-'1'] = true;
                    }
                }
                if(rowChar != '.')                
                {
                    if(rowLabel[rowChar-'1'])
                    {
                        return false;
                    }
                    else
                    {
                        rowLabel[rowChar-'1'] = true;
                    }
                }
            }
            int col = i / 3 * 3;
            int row = i % 3 * 3;
            for(int j = col; j < col + 3; ++j)
            {
                for(int k = row; k < row + 3; ++k)
                {
                    char crChar = board[j][k];
                    if(crChar != '.')
                    {
                        if(crLabel[crChar-'1'])
                        {
                            return false;
                        }
                        else
                        {
                            crLabel[crChar-'1'] = true;
                        }
                    }
                }
            }
           
            for(int k = 0; k < 9; ++k)
            {
                colLabel[k] = false;
                rowLabel[k] = false;
                crLabel[k] = false;
            }
        }

        /*
        for(int i = 0; i < 9; ++i) //0-8块
        {
            int col = i / 3 * 3;
            int row = i % 3 * 3;
            for(int j = col; j < col + 3; ++j)
            {
                for(int k = row; k < row + 3; ++k)
                {
                    char crChar = board[j][k];
                    if(crChar != '.')
                    {
                        if(crLabel[crChar-'1'])
                        {
                            return false;
                        }
                        else
                        {
                            crLabel[crChar-'1'] = true;
                        }
                    }
                }
            }
            for(int k = 0; k < 9; ++k)
            {
                crLabel[k] = false;
            }
        }
        */

        return true;
    }
};

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool colLabel[9] = {false};
        bool rowLabel[9] = {false};
        bool crLabel[9] = {false};
        for(int i = 0; i < 9; ++i)
        {
            for(int j = 0; j < 9; ++j)
            {
                char colChar = board[i][j];
                char rowChar = board[j][i];
                if(colChar != '.')
                {
                    if(colLabel[colChar-'1'])
                    {
                        return false;
                    }
                    else
                    {
                        colLabel[colChar-'1'] = true;
                    }
                }
                if(rowChar != '.')                
                {
                    if(rowLabel[rowChar-'1'])
                    {
                        return false;
                    }
                    else
                    {
                        rowLabel[rowChar-'1'] = true;
                    }
                }
            }
            for(int k = 0; k < 9; ++k)
            {
                colLabel[k] = false;
                rowLabel[k] = false;
            }
        }

        
        for(int i = 0; i < 9; ++i) //0-8块
        {
            int col = i / 3 * 3;
            int row = i % 3 * 3;
            for(int j = col; j < col + 3; ++j)
            {
                for(int k = row; k < row + 3; ++k)
                {
                    char crChar = board[j][k];
                    if(crChar != '.')
                    {
                        if(crLabel[crChar-'1'])
                        {
                            return false;
                        }
                        else
                        {
                            crLabel[crChar-'1'] = true;
                        }
                    }
                }
            }
            for(int k = 0; k < 9; ++k)
            {
                crLabel[k] = false;
            }
        }

        return true;
    }
};

