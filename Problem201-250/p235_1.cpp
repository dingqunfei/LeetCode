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
    TreeNode* find(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if(!root)
        {
            return nullptr;
        }
        
        if(root->val == p->val || root->val == q->val)
        {
            return root;
        }
        if(root->val < p->val)
        {
            return find(root->right, p, q);
        }
        if(root->val > q->val)
        {
            return find(root->left, p, q);
        }
        return root;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(p->val > q->val)
        {
            swap(p, q);
        }
        return find(root, p, q);
    }
};