/**
 * @file p222_2.cpp
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
    int countNodes(TreeNode* root) {
        if(!root)
        {
            return 0;
        }
        int lh = 0, rh = 0;
        TreeNode *left = root;
        TreeNode *right = root;
        while(left)
        {
            ++lh;
            left = left->left;
        }
        while(right)
        {
            ++rh;
            right = right->right;
        }
        if(rh == lh)
        {
            return pow(2, rh)-1;
        }
        return 1+countNodes(root->left)+countNodes(root->right);
    }
};