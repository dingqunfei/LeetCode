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
    TreeNode* build(vector<int>::iterator preleft, vector<int>::iterator preright, vector<int>::iterator inleft, vector<int>::iterator inright)
    {
        if(preleft >= preright)
        {
            return nullptr;
        }
        int val = *preleft;
        TreeNode* root = new TreeNode(val);
        auto index = find(inleft, inright, val);
        int left_size = index - inleft;
        root->left = build(preleft+1, preleft+left_size+1, inleft, inleft+left_size);
        root->right = build(preleft+left_size+1, preright, inleft+left_size+1, inright);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build(preorder.begin(), preorder.end(), inorder.begin(), inorder.end());
    }
};