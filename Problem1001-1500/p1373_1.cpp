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
    int maxValue = 0;
    vector<int> traverse(TreeNode* root)
    {
        if(root == NULL)
        {
            return {1, INT_MAX, INT_MIN, 0};
        }
        vector<int> left = traverse(root->left);
        vector<int> right = traverse(root->right);
        vector<int> res(4, 0);
        if(left[0] + right[0] == 2 && root->val > left[2] && root->val < right[1])
        {
            res[0] = 1;
            res[1] = min(left[1], root->val);
            res[2] = max(right[2], root->val);
            res[3] = root->val + left[3] + right[3];
            maxValue = max(maxValue, res[3]);
        }
        else
        {
            res[0] = 0;
        }
        return res;
    }
    int maxSumBST(TreeNode* root) {
        traverse(root);
        return maxValue;
    }
};