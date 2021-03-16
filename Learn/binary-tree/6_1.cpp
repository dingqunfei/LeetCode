/**
 * @file 6_1.cpp
 * @brief 
 * @author dingqunfei (dqflying@gmail.com)
 * @version 1.0
 * @date 2021-03-16
 * 
 * @copyright Copyright (c) 2021 DQFLYING
 * 
 * @par :
 * 
 * 
 * Date        : 2021-03-16
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
    bool isSymmetric(TreeNode* root) 
    {
        if(root)
        {
            return helper(root->left, root->right);
        }
        else
        {
            return true;
        }
        
    }

    bool helper(TreeNode *p, TreeNode *q)
    {
        if(!p && !q)
        {
            return true;
        }
        if(!p || !q)
        {
            return false;
        }
        return p->val == q->val && helper(p->left, q->right) && helper(p->right, q->left);
    }
};