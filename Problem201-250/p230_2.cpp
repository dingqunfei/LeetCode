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
    void traverse(TreeNode* root, int k, int &count, int &target)
    {
        if(!root)
        {
            return;
        }
        traverse(root->left, k, count, target);
        ++count;
        if(count == k)
        {
            target = root->val;
            return;
        }
        traverse(root->right, k, count, target);
    }
    int kthSmallest(TreeNode* root, int k) {
        int count = 0;
        int target = 0;
        traverse(root, k, count, target);
        return target;
    }
};