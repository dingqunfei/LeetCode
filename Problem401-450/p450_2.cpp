/**
 * @file p450_2.cpp
 * @brief 
 * @author dingqunfei (dqflying@gmail.com)
 * @version 1.0
 * @date 2021-04-11
 * 
 * @copyright Copyright (c) 2021 DQFLYING
 * 
 * @par :
 * 
 * 
 * Date        : 2021-04-11
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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root)
        {
            return nullptr;
        }
        if(key == root->val)
        {
            if(!root->left && !root->right)
            {
                return nullptr;
            }
            else if(!root->left)
            {
                return root->right;
            }
            else if(!root->right)
            {
                return root->left;
            }
            else
            {
                TreeNode *left_max = root->left;
                while(left_max->right)
                {
                    left_max = left_max->right;
                }
                left_max->right = root->right;
                TreeNode *tmp = root;
                root = root->left;
                delete tmp;
                return root;
            }
        }
        else if(key < root->val)
        {
            root->left = deleteNode(root->left, key);
        }
        else
        {
            root->right = deleteNode(root->right, key);
        }
        return root;
    }
};