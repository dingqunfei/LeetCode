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
    long prev = LONG_MIN;
    bool isValidBST(TreeNode* root) {
        if(!root)
        {
            return true;
        }
        bool left = isValidBST(root->left);
        bool isBigger = false;
        if(root->val > prev)
        {
            isBigger = true;
            prev = root->val;
        }
        bool right = isValidBST(root->right);
        return left && isBigger && right;
    }
};