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
    //bool label表示左右子树
    bool isValid(TreeNode* root, long long minValue, long long maxValue)
    {
        if(!root)
        {
            return true;
        }
        if(root->val <= minValue || root->val >= maxValue)
        {
            return false;
        }
        return isValid(root->left, minValue, root->val) && isValid(root->right, root->val, maxValue);
    }
    bool isValidBST(TreeNode* root) {
        return isValid(root, LONG_MIN, LONG_MAX);
    }
};