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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if(!root)
        {
            return res;
        }
        stack<TreeNode*> nodes;
        TreeNode* curr = root;
        TreeNode* visited = new TreeNode(INT_MAX);
        while(!nodes.empty() || curr)
        {
            if(curr)
            {
                nodes.push(curr);
                curr = curr->left;
            }
            else
            {
                curr = nodes.top();
                if(curr->right == NULL || curr->right == visited)
                {
                    res.push_back(curr->val);
                    visited = curr;
                    nodes.pop();
                    curr = NULL;
                }
                else
                {
                    curr = curr->right;
                }
            }
        }
        return res;
    }
};