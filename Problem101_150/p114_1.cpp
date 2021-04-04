/**
 * @file p114_1.cpp
 * @brief 
 * @author dingqunfei (dqflying@gmail.com)
 * @version 1.0
 * @date 2021-04-05
 * 
 * @copyright Copyright (c) 2021 DQFLYING
 * 
 * @par :
 * 
 * 
 * Date        : 2021-04-05
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
    void flatten(TreeNode* root) {
        if(!root)
        {
            return;
        }
        flatten(root->left);
        flatten(root->right);

        TreeNode *left = root->left;
        TreeNode *right = root->right;
        root->left = nullptr;
        root->right = left;

        TreeNode *p = root;
        while(p->right)
        {
            p = p->right;
        }
        p->right = right;
    }

};