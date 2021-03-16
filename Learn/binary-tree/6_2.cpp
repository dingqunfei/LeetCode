/**
 * @file 6_2.cpp
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

    bool helper(TreeNode *l, TreeNode *r)
    {
        queue<TreeNode *> q;
        q.push(l);
        q.push(r);
        while(!q.empty())
        {
            l = q.front();
            q.pop();
            r = q.front();
            q.pop();
            if (!l && !r) continue;

            if((!l || !r) || (l->val != r->val))
            {
                return false;
            }
            q.push(l->left);
            q.push(r->right);

            q.push(l->right);
            q.push(r->left);
        }
        return true;
    }
};