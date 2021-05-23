/**
 * @file p111_1.cpp
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
    int minDepth(TreeNode* root) {
        queue<TreeNode *> nodes;
        int step = 0;
        if(root)
        {
            nodes.push(root);
            ++step;
        }
        
        while(!nodes.empty())
        {
            int size = nodes.size();
            for(int i = 0; i < size; ++i)
            {
                TreeNode *child = nodes.front();
                nodes.pop();
                if(!child->left && ! child->right)
                {
                    return step;
                }
                if(child->left)
                {
                    nodes.push(child->left);
                }
                if(child->right)
                {
                    nodes.push(child->right);
                }
            }
            ++step;
        }
        return step;
    }
};