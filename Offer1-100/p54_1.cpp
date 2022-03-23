/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int biger = 0;
    int val = 0;
    void kth(TreeNode* root, int k)
    {
        if(root == NULL)
        {
            return;
        }
        kth(root->right, k);
        biger++;
        if(k == biger)
        {
            val = root->val;
            return;
        }
        kth(root->left, k);
    }
    int kthLargest(TreeNode* root, int k) {
        kth(root, k);
        return val;
    }
};