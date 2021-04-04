/**
 * @file p226_2.cpp
 * @brief 
 * @author dingqunfei (dqflying@gmail.com)
 * @version 1.0
 * @date 2021-04-04
 * 
 * @copyright Copyright (c) 2021 DQFLYING
 * 
 * @par :
 * 
 * 
 * Date        : 2021-04-04
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
    TreeNode* invertTree(TreeNode* root) {
        if(!root)
        {
            return root;
        }
        list<TreeNode *> nodeList;
        nodeList.push_back(root);
        while(!nodeList.empty())
        {
            TreeNode *tempRoot = nodeList.front();
            nodeList.pop_front();

            if(tempRoot)
            {
                TreeNode *temp = tempRoot->left;
                tempRoot->left = tempRoot->right;
                tempRoot->right = temp;
                nodeList.push_back(tempRoot->left);
                nodeList.push_back(tempRoot->right);
            }
            
        }
        
        return root;

    }
};