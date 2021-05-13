/**
 * @file p450_1.cpp
 * @brief 
 * @author dingqunfei (dqflying@gmail.com)
 * @version 1.0
 * @date 2021-04-10
 * 
 * @copyright Copyright (c) 2021 DQFLYING
 * 
 * @par :
 * 
 * 
 * Date        : 2021-04-10
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
private:
    TreeNode *get_left_max(TreeNode *root)
    {
        if(!root)
        {
            return nullptr;
        }
        while(root->right)
        {
            root = root->right;
        }
        return root;
    }
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
                root = root->right;
                return root;
            }
            else if(!root->right)
            {
                root = root->left;
                return root;
            }
            else
            {
                TreeNode *left_max = get_left_max(root->left);
                int remove_left_val = left_max->val;
                root->val = remove_left_val;
                root->left = deleteNode(root->left, remove_left_val);
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