/**
 * @file 3_2.cpp
 * @brief 
 * @author dingqunfei (dqflying@gmail.com)
 * @version 1.0
 * @date 2021-02-27
 * 
 * @copyright Copyright (c) 2021 DQFLYING
 * 
 * @par :
 * 
 * 
 * Date        : 2021-02-27
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
    vector<int> postorderTraversal(TreeNode* root) 
    {
        vector<int> res;
        stack<pair<TreeNode *, bool>> nodes;
        while(root || !nodes.empty())
        {
            while(root)
            {
                nodes.push(make_pair(root, true));
                root = root->left;
            }
            pair<TreeNode *, bool> node = nodes.top();
            if(node.second)
            {
                nodes.pop();
                node.second = false;
                nodes.push(node);
                root = node.first;
                root = root->right;
            }
            else
            {
                root = node.first;
                res.push_back(root->val);
                nodes.pop();
                root = nullptr;
            }
        }
        return res;
    }
};