/**
 * @file 4_1.cpp
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
        int next_level_nodes = 0;
        int cnt = 0;
        if(root)
        {
            nodes.push_back(root);
            next_level_nodes = 1;
        }
        cnt = next_level_nodes;
        next_level_nodes = 0;
        while(!nodes.empty())
        {
            vector<int> line;
            for(int i = 0; i < cnt; ++i)
            {
                root = nodes.front();
                line.push_back(root->val);
                if(root->left)
                {
                    nodes.push_back(root->left);
                    ++next_level_nodes;
                }
                if(root->right)
                {
                    nodes.push_back(root->right);
                    ++next_level_nodes;
                }
                nodes.pop_front();
            }
            cnt = next_level_nodes;
            next_level_nodes = 0;
            lines.push_back(line);
        }

        return lines;
    }
};