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
    void flatten(TreeNode* root) {
        flat(root);
    }
    TreeNode* flat(TreeNode* root)
    {
        if(root == NULL)
        {
            return NULL;
        }
        TreeNode* left = flat(root->left);
        TreeNode* right = flat(root->right);
        root->left = NULL;
        root->right = left;
        if(left)
        {
            while(left->right)
            {
                left = left->right;
            }
            left->right = right;
        }
        else
        {
            root->right = right;
        }
        
        return root;
    }
};