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
        if(!root)
        {
            return res;
        }
        stack<TreeNode*> nodes;
        TreeNode* prev = root;
        while(!nodes.empty() || prev)
        {
            if(prev)
            {
                res.push_back(prev->val);
                nodes.push(prev);
                prev = prev->left;
            }
            else
            {
                prev = nodes.top();
                nodes.pop();
                prev = prev->right;
            }
        }
        return res;
    }
};