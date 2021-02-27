/**
 * @file 4_2.cpp
 * @brief 
 * @author dingqunfei (dqflying@gmail.com)
 * @version 1.0
 * @date 2021-02-28
 * 
 * @copyright Copyright (c) 2021 DQFLYING
 * 
 * @par :
 * 
 * 
 * Date        : 2021-02-28
 * Version     : 1.0
 * Author      : dqflying
 * Lisence     : 
 * Description : 
 * 
 * 
 * 
 * 
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root)
    {
        list<TreeNode *> nodes;
        vector<vector<int>> lines;
        vector<int> line, temp;
        
        if(root)
        {
            nodes.push_back(root);
            nodes.push_back(nullptr);

            while(nodes.size() > 1)
            {
                root = nodes.front();
                nodes.pop_front();
                if(root)
                {
                    line.push_back(root->val);
                    if(root->left)
                    {
                        nodes.push_back(root->left);
                    }
                    if(root->right)
                    {
                        nodes.push_back(root->right);
                    }
                }
                else
                {
                    nodes.push_back(nullptr);
                    lines.push_back(line);
                    line.clear();
                } 
                temp = line;           
            }
            lines.push_back(temp);
        }
        return lines;
    }
};