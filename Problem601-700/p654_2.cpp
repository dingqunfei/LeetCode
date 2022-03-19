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
    TreeNode* maxBinaryTree(vector<int>::iterator left, vector<int>::iterator right)
    {
        if(left >= right)
        {
            return NULL;
        }
        auto maxPoint = max_element(left, right);
        TreeNode* root = new TreeNode(*maxPoint);
        root->left = maxBinaryTree(left, maxPoint);
        root->right = maxBinaryTree(maxPoint+1, right);
        return root;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return maxBinaryTree(nums.begin(), nums.end());
    }
};