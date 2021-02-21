/**
 * @file 1_1.cpp
 * @brief 
 * @author dingqunfei (dqflying@gmail.com)
 * @version 1.0
 * @date 2021-02-21
 * 
 * @copyright Copyright (c) 2021 DQFLYING
 * 
 * @par :
 * 
 * 
 * Date        : 2021-02-21
 * Version     : 1.0
 * Author      : dqflying
 * Lisence     : 
 * Description : 
 * 
 */

/*
Description:
Given the root of a binary tree, return the preorder traversal of its nodes' values.

*/

/*
Result:
执行用时：
0 ms, 在所有 C++ 提交中击败了100.00%的用户
内存消耗：
8.3 MB, 在所有 C++ 提交中击败了69.15%的用户
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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode *> nodes;

        if(!root)
        {
            return res;
        }
        else
        {
            nodes.push(root);
        }
        TreeNode *CurrNode;
        while(!nodes.empty())
        {
            CurrNode = nodes.top();
            res.push_back(CurrNode->val);
            nodes.pop();
            if(CurrNode->right)
            {
                nodes.push(CurrNode->right);
            }
            if(CurrNode->left)
            {
                nodes.push(CurrNode->left);
            }
        }
        return res;
    }
};