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
    int prev = 0;
    void rightinleftTraverse(TreeNode* root)
    {
        if(root == NULL)
        {
            return;
        }
        rightinleftTraverse(root->right);
        root->val += prev;
        prev = root->val;
        rightinleftTraverse(root->left);
    }
    TreeNode* bstToGst(TreeNode* root) {
        rightinleftTraverse(root);
        return root;
    }
};